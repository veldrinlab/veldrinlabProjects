#include "NintendoIdentifier.hpp"

namespace Midori
{
	void prepareIdentifier(NintendoIdentifier* identifier)
	{
		createWindow(&identifier->app);
		configureContext();
		configureView(&identifier->view);
		identifier->isRunning = true;
		prepareNintendoShaders(&identifier->shaders);
		prepareNintendoFrames(&identifier->frames);
		identifier->foundObject = false;
	}

	void setInputImage(NintendoIdentifier* identifier, const std::string& name)
	{
		loadTexture(&identifier->inputTexture,name);
		createImage(&identifier->image,&identifier->inputTexture,&identifier->shaders.renderImage);
	}

	void prepareNintendoShaders(NintendoShaders* shaders)
	{
		loadShader(&shaders->renderImage,"Shaders/renderImage.vert","Shaders/renderImage.frag");
		loadShader(&shaders->redSegmentation,"Shaders/redSegmentation.vert","Shaders/redSegmentation.frag");
		loadShader(&shaders->blueSegmentation,"Shaders/blueSegmentation.vert","Shaders/blueSegmentation.frag");
		loadShader(&shaders->greenSegmentation,"Shaders/greenSegmentation.vert","Shaders/greenSegmentation.frag");
		loadShader(&shaders->yellowSegmentation,"Shaders/yellowSegmentation.vert","Shaders/yellowSegmentation.frag");
		loadShader(&shaders->segmentFilter,"Shaders/segmentFilter.vert","Shaders/segmentFilter.frag");
	}

	void prepareNintendoFrames(NintendoFrames* frames)
	{
		createFrameBuffer(&frames->redElements,WIDTH,HEIGHT);
		createFrameBuffer(&frames->greenElements,WIDTH,HEIGHT);
		createFrameBuffer(&frames->blueElements,WIDTH,HEIGHT);
		createFrameBuffer(&frames->yellowElements,WIDTH,HEIGHT);
	}

	void performSegmentation(NintendoIdentifier* identifier)
	{
		renderToTexture(&identifier->frames.redElements,&identifier->image,&identifier->view,&identifier->shaders.redSegmentation);
		renderToTexture(&identifier->frames.greenElements,&identifier->image,&identifier->view,&identifier->shaders.greenSegmentation);
		renderToTexture(&identifier->frames.blueElements,&identifier->image,&identifier->view,&identifier->shaders.blueSegmentation);
		renderToTexture(&identifier->frames.yellowElements,&identifier->image,&identifier->view,&identifier->shaders.yellowSegmentation);

		clasifySegments(identifier,&identifier->frames.redElements,&identifier->redSegments);
		performBoundaryConditionTest(identifier,&identifier->redSegments);
		divideSegments(identifier,&identifier->frames.redElements,&identifier->redSegments);

		clasifySegments(identifier,&identifier->frames.greenElements,&identifier->greenSegments);
		performBoundaryConditionTest(identifier,&identifier->greenSegments);
		divideSegments(identifier,&identifier->frames.greenElements,&identifier->greenSegments);

		clasifySegments(identifier,&identifier->frames.blueElements,&identifier->blueSegments);
		performBoundaryConditionTest(identifier,&identifier->blueSegments);
		divideSegments(identifier,&identifier->frames.blueElements,&identifier->blueSegments);

		clasifySegments(identifier,&identifier->frames.yellowElements,&identifier->yellowSegments);
		performBoundaryConditionTest(identifier,&identifier->yellowSegments);
		divideSegments(identifier,&identifier->frames.yellowElements,&identifier->yellowSegments);
	}

	void clasifySegments(NintendoIdentifier* identifier, FrameBuffer* frame, std::vector<Segment*>* segments)
	{
		GLubyte* p = nullptr;
		p = new GLubyte[WIDTH*HEIGHT*4];
		
		GLubyte color = 0;
		GLubyte tab[256];
		for(int i = 0; i < 256; ++i)
			tab[i] = 0;
		
		glBindTexture(GL_TEXTURE_RECTANGLE,frame->colorBuffer);
		glGetTexImage(GL_TEXTURE_RECTANGLE,0,GL_RGBA,GL_UNSIGNED_BYTE,p);
		
		for(int y = 0; y < HEIGHT; ++y)
		{
			for(int x = 0; x < WIDTH; ++x)
			{
				int X = 4*x+WIDTH*y*4;
				
				if(p[X] == 255)
				{
					GLubyte colorA,colorB,colorC,colorD = 0;
				
					if(4*(x-1)+WIDTH*4*(y-1) > 0 && 4*(x-1)+WIDTH*4*(y-1) < WIDTH*HEIGHT*4) colorA = p[4*(x-1)+WIDTH*4*(y-1)];
					if(4*x+WIDTH*4*(y-1) > 0 && 4*x+WIDTH*4*(y-1) < WIDTH*HEIGHT*4) colorB = p[4*x+WIDTH*4*(y-1)];
					if(4*(x+1)+WIDTH*4*(y-1) > 0 && 4*(x+1)+WIDTH*4*(y-1) < WIDTH*HEIGHT*4) colorC = p[4*(x+1)+WIDTH*4*(y-1)];
					if(4*(x-1)+WIDTH*4*y > 0 && 4*(x-1)+WIDTH*4*y < WIDTH*HEIGHT*4) colorD = p[4*(x-1)+WIDTH*4*y];

					if((colorA == 0) && (colorB == 0) && (colorC == 0) && (colorD == 0))
					{
						color = color + 1;	
						p[X] = color;
						tab[color] = color;

						Segment* segment = new Segment();
						segment->id = color;
						segment->isPartOfObject = false;
						segment->isNFragment = false;
						segment->isYFragment = false;
						segment->vertexAmount = 0;
						segments->push_back(segment);
					}
					else
					{
						std::vector<int> v;
						bool same = true;

						if(colorA != 0) v.push_back(colorA);
						if(colorB != 0) v.push_back(colorB);
						if(colorC != 0) v.push_back(colorC);
						if(colorD != 0) v.push_back(colorD);

						GLubyte pattern = v[0];

						for(unsigned int i = 0; i < v.size(); ++i)
							if(pattern != v[i])
								same = false;

						if(same)
							p[X] = pattern;
						else
						{
							int min = v[0];
							int max = v[0];

							for(unsigned int i = 0; i < v.size(); ++i)
							{
								if(v[i] < min) min = v[i];
								if(v[i] > max) max = v[i];
							}
							p[X] = min;
							tab[max] = min;
						}	
					}
				}
			}
		}
		
		for(int y = 0; y < HEIGHT; ++y)
			for(int x = 0; x < WIDTH; ++x)
				p[4*x+WIDTH*y*4] = tab[p[4*x+WIDTH*y*4]];

		for(int y = 0; y < HEIGHT; ++y)
		{
			for(int x = 0; x < WIDTH; ++x)
			{
				int X = 4*x+WIDTH*y*4;

				if(p[X] != 0)
				{
					GLubyte segmentColor = p[X];
					int t = 1;
					for(int i = -1; i < 2; ++i)
						for(int j = -1; j < 2; ++j)
						{
							bool end = false;
							t = 1;
							X = 4*x+WIDTH*y*4;
							
							if((i == 0 && j == 0))
								continue;

							while(!end)
							{
								X = 4*(x+i*t)+WIDTH*(y+j*t)*4;
								end = true;
								if(X > 0 && X < WIDTH*HEIGHT*4)
									if(p[X] != 0)
									{
										p[X] = segmentColor;
										end = false;
										t++;
									}
							}
						}
				}
			}
		}

		for(int y = 0; y < HEIGHT; ++y)
		{
			for(int x = 0; x < WIDTH; ++x)
			{
				int X = 4*x+WIDTH*y*4;

				GLubyte c = p[X];
				if(c != 0)
					segments->at(c-1)->vertexAmount++;
			}
		}
		
		glTexSubImage2D(GL_TEXTURE_RECTANGLE,0,0,0,WIDTH,HEIGHT,GL_RGBA,GL_UNSIGNED_BYTE,p);
		delete [] p;
	}

	void performBoundaryConditionTest(NintendoIdentifier* identifier, std::vector<Segment*>* segments)
	{
		int min = Configuration::getInstance()->getMinVert();
		int max = Configuration::getInstance()->getMaxVert();
		int counter = segments->size();
		while(counter > 0)
		{
			for(std::vector<Segment*>::const_iterator it = segments->begin(); it != segments->end(); ++it)
			{
				if((*it)->vertexAmount < min || (*it)->vertexAmount > max)
				{
					segments->erase(it);
					break;
				}
			}
			counter--;
		}
	}

	void divideSegments(NintendoIdentifier* identifier, FrameBuffer* frame, std::vector<Segment*>* segments)
	{
		for(std::vector<Segment*>::const_iterator it = segments->begin(); it != segments->end(); ++it)
		{
			GLfloat filterColor;
			filterColor = (*it)->id / 255.0f;
			createFrameBuffer(&(*it)->data,WIDTH,HEIGHT);
			renderSegmentToTexture(&(*it)->data,&identifier->image,&identifier->view,&identifier->shaders.segmentFilter,frame,filterColor);
		}
	}

	void calculatePatternsInvariants()
	{
		// yellow element invariants
		Texture y;
		Texture ySize;
		Texture yRot;
		Texture yPers;
		loadTexture(&y,"Images/wzorY.png");
		loadTexture(&ySize,"Images/wzorYSize.png");
		loadTexture(&yRot,"Images/wzorYRot.png");
		loadTexture(&yPers,"Images/wzorYPers.png");

		Invariants yInv;
		Invariants ySizeInv;
		Invariants yRotInv;
		Invariants yPersInv;

		calculateInvariants(&yInv,y.id);
		calculateInvariants(&ySizeInv,ySize.id);
		calculateInvariants(&yRotInv,yRot.id);
		calculateInvariants(&yPersInv,yPers.id);

		std::cout << "        Base" << "Scale" << "Rot" << "Pers" << std::endl;
		std::cout<< " M1: " << yInv.M1 << " " << ySizeInv.M1 << " " << yRotInv.M1 << " " << yPersInv.M1 << std::endl;
		std::cout<< " M2: " << yInv.M2 << " " << ySizeInv.M2 << " " << yRotInv.M2 << " " << yPersInv.M2 << std::endl;
		std::cout<< " M3: " << yInv.M3 << " " << ySizeInv.M3 << " " << yRotInv.M3 << " " << yPersInv.M3 << std::endl;
		std::cout<< " M4: " << yInv.M4 << " " << ySizeInv.M4 << " " << yRotInv.M4 << " " << yPersInv.M4 << std::endl;
		std::cout<< " M5: " << yInv.M5 << " " << ySizeInv.M5 << " " << yRotInv.M5 << " " << yPersInv.M5 << std::endl;
		std::cout<< " M6: " << yInv.M6 << " " << ySizeInv.M6 << " " << yRotInv.M6 << " " << yPersInv.M6 << std::endl;
		std::cout<< " M7: " << yInv.M7 << " " << ySizeInv.M7 << " " << yRotInv.M7 << " " << yPersInv.M7 << std::endl;
		std::cout<< " M8: " << yInv.M8 << " " << ySizeInv.M8 << " " << yRotInv.M8 << " " << yPersInv.M8 << std::endl;
		std::cout<< " M9: " << yInv.M9 << " " << ySizeInv.M9 << " " << yRotInv.M9 << " " << yPersInv.M9 << std::endl;
		std::cout<< " M10: " << yInv.M10 << " " << ySizeInv.M10 << " " << yRotInv.M10 << " " << yPersInv.M10 << std::endl;

		//Najlepsze chyba M1, ca³kiem dobre na skalowanie i Rot, najgorzej Pers(jak mozna bylo sie spodziewac
		//M2 tez zajebiste, podobnie
		//M4 niezle, M6 podobnie
		//M7 dobre w kazdej sytuacji

		// N element invariants
		Texture n;
		Texture nSize;
		Texture nRot;
		Texture nPers;
		loadTexture(&n,"Images/wzorN.png");
		loadTexture(&nSize,"Images/wzorNSize.png");
		loadTexture(&nRot,"Images/wzorNRot.png");
		loadTexture(&nPers,"Images/wzorNPers.png");

		Invariants nInv;
		Invariants nSizeInv;
		Invariants nRotInv;
		Invariants nPersInv;

		calculateInvariants(&nInv,n.id);
		calculateInvariants(&nSizeInv,nSize.id);
		calculateInvariants(&nRotInv,nRot.id);
		calculateInvariants(&nPersInv,nPers.id);
		
		std::cout << "        Base" << "Scale" << "Rot" << "Pers" << std::endl;
		std::cout<< " M1: " << nInv.M1 << " " << nSizeInv.M1 << " " << nRotInv.M1 << " " << nPersInv.M1 << std::endl;
		std::cout<< " M2: " << nInv.M2 << " " << nSizeInv.M2 << " " << nRotInv.M2 << " " << nPersInv.M2 << std::endl;
		std::cout<< " M3: " << nInv.M3 << " " << nSizeInv.M3 << " " << nRotInv.M3 << " " << nPersInv.M3 << std::endl;
		std::cout<< " M4: " << nInv.M4 << " " << nSizeInv.M4 << " " << nRotInv.M4 << " " << nPersInv.M4 << std::endl;
		std::cout<< " M5: " << nInv.M5 << " " << nSizeInv.M5 << " " << nRotInv.M5 << " " << nPersInv.M5 << std::endl;
		std::cout<< " M6: " << nInv.M6 << " " << nSizeInv.M6 << " " << nRotInv.M6 << " " << nPersInv.M6 << std::endl;
		std::cout<< " M7: " << nInv.M7 << " " << nSizeInv.M7 << " " << nRotInv.M7 << " " << nPersInv.M7 << std::endl;
		std::cout<< " M8: " << nInv.M8 << " " << nSizeInv.M8 << " " << nRotInv.M8 << " " << nPersInv.M8 << std::endl;
		std::cout<< " M9: " << nInv.M9 << " " << nSizeInv.M9 << " " << nRotInv.M9 << " " << nPersInv.M9 << std::endl;
		std::cout<< " M10: " << nInv.M10 << " " << nSizeInv.M10 << " " << nRotInv.M10 << " " << nPersInv.M10 << std::endl;

		//swietnie sie sprawdza M1
		// niezle M2
		//M5/M10 -> zera, moze te¿ da sie wykorzystac 
		//M7 znowu swietnie, ewentualnie M2, choc gorzej rotatcja, persp

		releaseTexture(&y);
		releaseTexture(&ySize);
		releaseTexture(&yPers);
		releaseTexture(&yRot);
		releaseTexture(&n);
		releaseTexture(&nSize);
		releaseTexture(&nPers);
		releaseTexture(&nRot);
	}

	void calculateInvariants(Invariants* inv, GLuint tex)
	{
		GLubyte* p = nullptr;
		p = new GLubyte[WIDTH*HEIGHT*4];

		//momenty zwyk³e
 		float m00 = 0.0f;
		float m01 = 0.0f;
		float m10 = 0.0f;
		float m11 = 0.0f;
		float m02 = 0.0f;
		float m20 = 0.0f;
		float m21 = 0.0f;
		float m12 = 0.0f;
		float m30 = 0.0f;
		float m03 = 0.0f;

		//momenty centralne
		float M00 = 0.0f;
		float M01 = 0.0f;
		float M10 = 0.0f;
		float M11 = 0.0f;
		float M20 = 0.0f;
		float M02 = 0.0f;
		float M21 = 0.0f;
		float M12 = 0.0f;
		float M30 = 0.0f;
		float M03 = 0.0f;

		glBindTexture(GL_TEXTURE_RECTANGLE,tex);
		glGetTexImage(GL_TEXTURE_RECTANGLE,0,GL_RGBA,GL_UNSIGNED_BYTE,p);
		
		for(int j = 1; j < HEIGHT; ++j)
		{
			for(int i = 1; i < WIDTH; ++i)
			{
				if(p[4*i+WIDTH*j*4] == 255)
				{
					m00 += 1.0f;
					m01 += j;
					m10 += i;
					m11 += i*j;
					m02 += pow(static_cast<float>(j),2);
					m20 += pow(static_cast<float>(i),2);
					m21 += pow(static_cast<float>(i),2)*j;
					m12 += pow(static_cast<float>(j),2)*i;
					m30 += pow(static_cast<float>(i),3);
					m03 += pow(static_cast<float>(j),3);
				}
			}
		}

		M00 = m00;
		M01 = m01 - m01/m00*m00;
		M10 = m10 - m10/m00*m00;
		M11 = m11 - m10*m01/m00;
		M20 = m20 - m10*m10/m00;
		M02 = m02 - m01*m01/m00;
		M21 = m21 - 2*m11*m10/m00 - m20*m01/m00 + 2*m01*m10*m10/m00/m00;
		M12 = m12 - 2*m11*m01/m00 - m02*m10/m00 + 2*m10*m01*m01/m00/m00;
		M30 = m30 - 3*m20*m10/m00 + 2* m10 *m10*m10/m00/m00;
		M03 = m03 - 3*m02*m01/m00 + 2* m01 *m01*m01/m00/m00;

		//niezmienniki momentowe
		inv->area = M00;
		inv->M1 = (M20 + M02)/pow(static_cast<float>(m00),2);
		inv->M2 = ((M20-M02)*(M20-M02) + 4*M11*M11)/ pow(static_cast<float>(m00),4);
		inv->M3 = ((M30-3*M12)*(M30-3*M12)+(3*M21-M03)*(3*M21-M03))/pow(static_cast<float>(m00),5);
		inv->M4 = ((M30+M12)*(M30+M12) + (M21+M03)*(M21+M03))/pow(static_cast<float>(m00),5);
		inv->M5 = ((M30-3*M12)*(M30+M12)*((M30+M12)*(M30*M12)-3*(M21+M03)*(M21+M03)) + (3*M12-M03)*(M21+M03)*(3*(M30+M12)*(M30+M12)-(M21+M03)*(M21+M03)))/pow(static_cast<float>(m00),10);
		inv->M6 = ((M20-M02)*((M30+M12)*(M30+M12) - (M21+M03)*(M21+M03))+4*M11*(M30+M12)*(M21+M03))/pow(static_cast<float>(m00),7);
		inv->M7 = (M20*M02-M11*M11)/pow(static_cast<float>(m00),4);
		inv->M8 = (M30*M12+M21*M03-M12*M12-M21*M21)/pow(static_cast<float>(m00),5);
		inv->M9 = (M20*(M21*M03-M12*M12)+M02*(M03*M12-M21*M21)-M11*(M30*M03-M21*M12))/pow(static_cast<float>(m00),7);
		inv->M10 = ((M30*M03 - M12*M21)*(M30*M03 - M12*M21) - 4*(M30*M12-M21*M21)*(M03*M21-M12))/pow(static_cast<float>(m00),10);

		inv->centerX = m10/m00;
		inv->centerY = m01/m00;

		delete [] p;
	}

	void calculateSegmentsInvariants(NintendoIdentifier* identifier)
	{
		for(std::vector<Segment*>::const_iterator it = identifier->redSegments.begin(); it != identifier->redSegments.end(); ++it)
			calculateInvariants(&(*it)->invariants,(*it)->data.colorBuffer);
		
		for(std::vector<Segment*>::const_iterator it = identifier->greenSegments.begin(); it != identifier->greenSegments.end(); ++it)
			calculateInvariants(&(*it)->invariants,(*it)->data.colorBuffer);
		
		for(std::vector<Segment*>::const_iterator it = identifier->blueSegments.begin(); it != identifier->blueSegments.end(); ++it)
			calculateInvariants(&(*it)->invariants,(*it)->data.colorBuffer);
		
		for(std::vector<Segment*>::const_iterator it = identifier->yellowSegments.begin(); it != identifier->yellowSegments.end(); ++it)
			calculateInvariants(&(*it)->invariants,(*it)->data.colorBuffer);
	}

	void identifySegmentsInvariants(NintendoIdentifier* identifier)
	{
		int yellowCounter = 0;
		int nCounter = 0;
		//szukamy kawalkow zoltych
		for(std::vector<Segment*>::const_iterator it = identifier->yellowSegments.begin(); it != identifier->yellowSegments.end(); ++it)
		{
			//dla zotych dane

			// M1 - 0.20-0.30
			// M2 - 0.05 - 0.06
			// M7 - 0.006-.007		

			if( ((*it)->invariants.M1 > 0.20f && (*it)->invariants.M1 < 0.30f) ||
				((*it)->invariants.M2 > 0.05f && (*it)->invariants.M2 < 0.06f) ||
				((*it)->invariants.M7 > 0.006f && (*it)->invariants.M7 < 0.007f))
			{
				(*it)->isPartOfObject = true;
				(*it)->isYFragment = true;
				std::cout << "Yellow" << std::endl;
				yellowCounter++;
			}
		}

		//szukamy kawalkow niebieskich
		for(std::vector<Segment*>::const_iterator it = identifier->blueSegments.begin(); it != identifier->blueSegments.end(); ++it)
		{
			// M1  0.24 - 0.27
			// M2 0.12 - 0.13
			// M7 0.010 - 0.015
			//dla niebieskich dane
			if( ((*it)->invariants.M1 > 0.24f && (*it)->invariants.M1 < 0.27f) ||
				((*it)->invariants.M2 > 0.12f && (*it)->invariants.M2 < 0.13f) ||
				((*it)->invariants.M7 > 0.010f && (*it)->invariants.M7 < 0.018f))
			{
				if(((*it)->invariants.M5 > -0.0000001f && (*it)->invariants.M5 < 0.0000001f) ||
					((*it)->invariants.M10 > -0.0000001f && (*it)->invariants.M10 < 0.0000001f))
				{
					(*it)->isPartOfObject = true;
					(*it)->isNFragment = true;
					std::cout << "N niebieski" << std::endl;
					nCounter++;
				}
			}
		}

		//szukamy kawalkow zielonych
		for(std::vector<Segment*>::const_iterator it = identifier->greenSegments.begin(); it != identifier->greenSegments.end(); ++it)
		{
			// M1  0.24 - 0.27
			// M2 0.12 - 0.13
			// M7 0.010 - 0.015
			//dla zielonych dane
			if( ((*it)->invariants.M1 > 0.24f && (*it)->invariants.M1 < 0.27f) ||
				((*it)->invariants.M2 > 0.12f && (*it)->invariants.M2 < 0.13f) ||
				((*it)->invariants.M7 > 0.010f && (*it)->invariants.M7 < 0.018f))
			{
				if(((*it)->invariants.M5 > -0.0000001f && (*it)->invariants.M5 < 0.0000001f) ||
					((*it)->invariants.M10 > -0.0000001f && (*it)->invariants.M10 < 0.0000001f))
				{
					(*it)->isPartOfObject = true;
					(*it)->isNFragment = true;
					nCounter++;
					std::cout << "N niebieski" << std::endl;
				}
			}
		}



		//odrzucanie z³ych liter - bo te zostaja
	
		float minX = 1024.0f; // za daleko zle
		float maxX = 0.0f; // za daleko zle
		float maxY = 0.0f; //wszystko ponizej

		std::cout << identifier->yellowSegments.size() << std::endl;

		for(std::vector<Segment*>::const_iterator it = identifier->yellowSegments.begin(); it != identifier->yellowSegments.end(); ++it)
		{
			if((*it)->isYFragment)
			{
				if((*it)->invariants.centerX < minX)
					minX = (*it)->invariants.centerX;
				if((*it)->invariants.centerX > maxX)
					maxX = (*it)->invariants.centerX;
				if((*it)->invariants.centerY > maxY)
					maxY = (*it)->invariants.centerY;
			}
		}

		std::cout << maxY << std::endl;

		for(std::vector<Segment*>::const_iterator it = identifier->blueSegments.begin(); it != identifier->blueSegments.end(); ++it)
		{
			if((*it)->isNFragment)
			{
				if((*it)->invariants.centerX < minX - 100)
				{
					nCounter--;
					(*it)->isPartOfObject = false;
				}
				if((*it)->invariants.centerX > maxX + 100)
				{
					nCounter--;
					(*it)->isPartOfObject = false;
				}
				if((*it)->invariants.centerY < maxY - 100)
				{
					nCounter--;
					(*it)->isPartOfObject = false;	
				}
			}
		}
				
		for(std::vector<Segment*>::const_iterator it = identifier->greenSegments.begin(); it != identifier->greenSegments.end(); ++it)
		{	
			if((*it)->isNFragment)
			{
				if((*it)->invariants.centerX < minX - 100)
				{
					nCounter--;
					(*it)->isPartOfObject = false;
				}
				if((*it)->invariants.centerX > maxX + 100)
				{
					nCounter--;
					(*it)->isPartOfObject = false;
				}
				if((*it)->invariants.centerY < maxY - 100)
				{
					nCounter--;
					(*it)->isPartOfObject = false;	
				}
			}
		}
		if(yellowCounter == 4 && nCounter == 2)
			identifier->foundObject = true;
	}

	void calculateResultData(NintendoIdentifier* identifier)
	{
		if(identifier->foundObject)
		{
			std::cout << "Object found status: true" << std::endl;
			createFrameBuffer(&identifier->result,WIDTH,HEIGHT);
			glBindFramebuffer(GL_FRAMEBUFFER,identifier->result.frameBuffer);		
			glClear(GL_COLOR_BUFFER_BIT);	

			for(std::vector<Segment*>::const_iterator it = identifier->yellowSegments.begin(); it != identifier->yellowSegments.end(); ++it)
				{
					if((*it)->isPartOfObject)
					{
						identifier->image.shader = &identifier->shaders.renderImage;
						identifier->image.texture->id = (*it)->data.colorBuffer;
						renderImage(&identifier->image,&identifier->view);
					}
				}
				for(std::vector<Segment*>::const_iterator it = identifier->blueSegments.begin(); it != identifier->blueSegments.end(); ++it)
				{
					if((*it)->isPartOfObject)
					{
						identifier->image.shader = &identifier->shaders.renderImage;
						identifier->image.texture->id = (*it)->data.colorBuffer;
						renderImage(&identifier->image,&identifier->view);
					}
				}
				for(std::vector<Segment*>::const_iterator it = identifier->greenSegments.begin(); it != identifier->greenSegments.end(); ++it)
				{
					if((*it)->isPartOfObject)
					{
						identifier->image.shader = &identifier->shaders.renderImage;
						identifier->image.texture->id = (*it)->data.colorBuffer;
						renderImage(&identifier->image,&identifier->view);
					}
				}
			glBindFramebuffer(GL_FRAMEBUFFER, 0);

			AyumiEngine::AyumiMath::Vector3D min(1024.0f,1024.0f,0.0f);
			AyumiEngine::AyumiMath::Vector3D max(0.0f,0.0f,0.0f);

			GLubyte* p = nullptr;
			p = new GLubyte[WIDTH*HEIGHT*4];

			glBindTexture(GL_TEXTURE_RECTANGLE,identifier->result.colorBuffer);
			glGetTexImage(GL_TEXTURE_RECTANGLE,0,GL_RGBA,GL_UNSIGNED_BYTE,p);
		
			for(int j = 0; j < HEIGHT; ++j)
			{
				for(int i = 0; i < WIDTH; ++i)
				{
					if(p[4*i+WIDTH*j*4] == 255)
					{
						if(i > max[0])
							max[0] = i;
						if(i < min[0])
							min[0] = i;
						if(j > max[1])
							max[1] = i;
						if(j < min[1])
							min[1] = i;
					}
				}
			}
			identifier->min = min;
			identifier->max = max;

			std::cout <<"Volume box min " << min[0] << " " << min[1] << " " << std::endl;
			std::cout <<"Volume box max " << max[0] << " " << max[1] << " " << std::endl;

			identifier->isRunning = true;
			while(identifier->isRunning && identifier->app.contextWindow->IsOpened())
			{
				sf::Event event;
				while(identifier->app.contextWindow->GetEvent(event))
				{
					switch(event.Type)
					{
						case sf::Event::KeyPressed:
							if(event.Key.Code == sf::Key::Escape)
							identifier->isRunning = false;
							break;
					}
				}
	
				glClear(GL_COLOR_BUFFER_BIT);
				glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

				for(std::vector<Segment*>::const_iterator it = identifier->yellowSegments.begin(); it != identifier->yellowSegments.end(); ++it)
				{
					if((*it)->isPartOfObject)
					{
						identifier->image.shader = &identifier->shaders.renderImage;
						identifier->image.texture->id = (*it)->data.colorBuffer;
						renderImage(&identifier->image,&identifier->view);
					}
				}
				for(std::vector<Segment*>::const_iterator it = identifier->blueSegments.begin(); it != identifier->blueSegments.end(); ++it)
				{
					if((*it)->isPartOfObject)
					{
						identifier->image.shader = &identifier->shaders.renderImage;
						identifier->image.texture->id = (*it)->data.colorBuffer;
						renderImage(&identifier->image,&identifier->view);
					}
				}
				for(std::vector<Segment*>::const_iterator it = identifier->greenSegments.begin(); it != identifier->greenSegments.end(); ++it)
				{
					if((*it)->isPartOfObject)
					{
						identifier->image.shader = &identifier->shaders.renderImage;
						identifier->image.texture->id = (*it)->data.colorBuffer;
						renderImage(&identifier->image,&identifier->view);
					}
				}
				identifier->app.contextWindow->Display();
			}
		}
		else
			std::cout << "Object found status: false" << std::endl;
	}

	void renderInput(NintendoIdentifier* identifier)
	{
		identifier->image.texture->id = identifier->inputTexture.id;
		identifier->image.shader = &identifier->shaders.renderImage;
		identifier->isRunning = true;
		while(identifier->isRunning && identifier->app.contextWindow->IsOpened())
		{
			sf::Event event;
			while(identifier->app.contextWindow->GetEvent(event))
			{
				switch(event.Type)
				{
					case sf::Event::KeyPressed:
					if(event.Key.Code == sf::Key::Escape)
						identifier->isRunning = false;
						break;
					case sf::Event::Closed:
						identifier->isRunning = false;
					default:
						break;
				}
			}

			glClear(GL_COLOR_BUFFER_BIT);
			glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
			renderImage(&identifier->image,&identifier->view);
			identifier->app.contextWindow->Display();
		}
	}

	void renderSegmentationResult(NintendoIdentifier* identifier)
	{
		for(std::vector<Segment*>::const_iterator it = identifier->redSegments.begin(); it != identifier->redSegments.end(); ++it)
			renderSegment(identifier,(*it));
		for(std::vector<Segment*>::const_iterator it = identifier->greenSegments.begin(); it != identifier->greenSegments.end(); ++it)
			renderSegment(identifier,(*it));
		for(std::vector<Segment*>::const_iterator it = identifier->blueSegments.begin(); it != identifier->blueSegments.end(); ++it)
			renderSegment(identifier,(*it));
		for(std::vector<Segment*>::const_iterator it = identifier->yellowSegments.begin(); it != identifier->yellowSegments.end(); ++it)
			renderSegment(identifier,(*it));
	}

	void renderSegment(NintendoIdentifier* identifier, Segment* segment)
	{
		identifier->isRunning = true;
		while(identifier->isRunning && identifier->app.contextWindow->IsOpened())
		{
			sf::Event event;
			while(identifier->app.contextWindow->GetEvent(event))
			{
				switch(event.Type)
				{
					case sf::Event::KeyPressed:
						if(event.Key.Code == sf::Key::Escape)
						identifier->isRunning = false;
						break;
				}
			}
	
			glClear(GL_COLOR_BUFFER_BIT);
			glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
			identifier->image.shader = &identifier->shaders.renderImage;
			identifier->image.texture->id = segment->data.colorBuffer;
			renderImage(&identifier->image,&identifier->view);
			identifier->app.contextWindow->Display();
		}
	}

	void renderResult(NintendoIdentifier* identifier)
	{
		std::string name = std::string(*Configuration::getInstance()->getInput());
		Texture res;
		loadTexture(&res,name);

		identifier->image.texture->id = res.id;
		identifier->image.shader = &identifier->shaders.renderImage;
		identifier->isRunning = true;
		while(identifier->isRunning && identifier->app.contextWindow->IsOpened())
		{
			sf::Event event;
			while(identifier->app.contextWindow->GetEvent(event))
			{
				switch(event.Type)
				{
					case sf::Event::KeyPressed:
					if(event.Key.Code == sf::Key::Escape)
						identifier->isRunning = false;
						break;
					case sf::Event::Closed:
						identifier->isRunning = false;
					default:
						break;
				}
			}

			glClear(GL_COLOR_BUFFER_BIT);
			glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
			renderImage(&identifier->image,&identifier->view);
			identifier->app.contextWindow->Display();
		}
		releaseTexture(&res);
	}

	void releaseResource(NintendoIdentifier* identifier)
	{
		releaseImage(&identifier->image);
		releaseTexture(&identifier->inputTexture);
		releaseShader(&identifier->shaders.renderImage);
		releaseShader(&identifier->shaders.redSegmentation);
		releaseShader(&identifier->shaders.greenSegmentation);
		releaseShader(&identifier->shaders.blueSegmentation);
		releaseShader(&identifier->shaders.yellowSegmentation);
		releaseShader(&identifier->shaders.segmentFilter);
		releaseFrameBuffer(&identifier->frames.redElements);
		releaseFrameBuffer(&identifier->frames.greenElements);
		releaseFrameBuffer(&identifier->frames.blueElements);
		releaseFrameBuffer(&identifier->frames.yellowElements);
		releaseFrameBuffer(&identifier->result);

		for(std::vector<Segment*>::const_iterator it = identifier->redSegments.begin(); it != identifier->redSegments.end(); ++it)
			releaseFrameBuffer(&(*it)->data);
	
		for(std::vector<Segment*>::const_iterator it = identifier->blueSegments.begin(); it != identifier->blueSegments.end(); ++it)
			releaseFrameBuffer(&(*it)->data);
	
		for(std::vector<Segment*>::const_iterator it = identifier->greenSegments.begin(); it != identifier->greenSegments.end(); ++it)
			releaseFrameBuffer(&(*it)->data);
	
		for(std::vector<Segment*>::const_iterator it = identifier->yellowSegments.begin(); it != identifier->yellowSegments.end(); ++it)
			releaseFrameBuffer(&(*it)->data);
	
		delete identifier;
		exit(0);
	}
}
