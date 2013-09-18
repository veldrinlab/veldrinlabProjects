/**
 * File contains definition of Terrain class.
 * @file    Terrain.cpp
 * @author  Szymon Jab³oñski
 * @date    2010-10-16
 * @version 1.0
 */

#include "Terrain.hpp"

namespace engine
{

/**
 * Class constructor, sets inital value.
 * @param	terrainFileName is name of file that contains terrain heightmap.	
 * @param	textureFileName is name of file that contains terrain texture.
 */
Terrain::Terrain(const char* terrainFileName,const char* textureFileName)
{
	this->terrainMapHeight = 1024;
	this->terrainMapWidth = 1024;
	this->isDead = false;
	levelOfDetail = 16;

	ResourceManager* resManager = ResourceManager::getInstance();
	terrainTexture = resManager->getResource(std::string("Terrainext"), std::string(textureFileName), TEXTURE);
	loadRawFile(terrainFileName);
	initializeTerrain();
	
	if(Extensions::shaderSupported)
		shader.initializeShader("Shaders/texture.vert","Shaders/texture.frag");

	collisionBox = new BoundingBox();
	collisionBox->min = Vector3D(0.0f,0.0f,0.0f);
	collisionBox->max = Vector3D(0.0f,0.0f,0.0f);
}

/**
 * Destructor, free allocated memory.
 */
Terrain::~Terrain()
{
	delete collisionBox;
}

/**
 * Method is used to initialize Terrain loaded from RAW file, and create Terrain VBO buffers.
 */
void Terrain::initializeTerrain()
{
	points = (int)(terrainMapHeight * terrainMapHeight* 6) / (levelOfDetail * levelOfDetail);
	verts = new Vertex[points];
	coords = new TextureCoord[points];
    
	int vertexIndex = 0;
    
	float terrainX = 0.0f;
	float terrainY = 0.0f;
	
	for (int i = 0; i < terrainMapWidth; i+=levelOfDetail)
	{
		for (int j = 0; j < terrainMapHeight; j+=levelOfDetail)
		{
			for (int triID = 0; triID < 6; ++triID)
			{
				terrainX = static_cast<float>(i)+((triID == 1 || triID == 2 || triID == 5) ? levelOfDetail  : 0);
                terrainY = static_cast<float>(j)+((triID == 1 || triID == 4 || triID == 5) ? levelOfDetail  : 0);
                
				verts[vertexIndex].x = terrainX;
				verts[vertexIndex].y = terrainHeightMap[static_cast<int>(terrainX)][static_cast<int>(terrainY)];
                verts[vertexIndex].z = terrainY;
                
				coords[vertexIndex].u = terrainX / 1024;
				coords[vertexIndex].v = terrainY / 1024;
                
				++vertexIndex;
			}
		}
	}

	if(Extensions::vboSupported)
	{
		Extensions::glGenBuffersARB(1, &VBOVertices);
		Extensions::glBindBufferARB(GL_ARRAY_BUFFER_ARB, VBOVertices);
		Extensions::glBufferDataARB(GL_ARRAY_BUFFER_ARB, points * 3 * sizeof(float), verts, GL_STATIC_DRAW_ARB);

		Extensions::glGenBuffersARB(1, &VBOTextureCoords);	    
		Extensions::glBindBufferARB(GL_ARRAY_BUFFER_ARB, VBOTextureCoords);
		Extensions::glBufferDataARB(GL_ARRAY_BUFFER_ARB, points * 2 * sizeof(float), coords, GL_STATIC_DRAW_ARB);

		delete [] verts;
		verts = NULL;   
		delete [] coords;
		coords = NULL;
	}

}

/**
 * Method used to update entity by elapsedTime.
 * @param	elapsedTime is time between frames in seconds.
 */
void Terrain::updateEntity(const float elapsedTime)
{
	//nothing to do 
}

/**
 * Method used to render terrain. Use HeightMapping algorithm.
 */
void Terrain::renderEntity()
{ 
	glPushMatrix();
		glScalef(5.0f,4.0f,5.0f);
		glTranslatef(-512,-200,-512);
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glEnableClientState(GL_VERTEX_ARRAY);

		Texture* tempTexture = static_cast<Texture*>(terrainTexture.get());
		glBindTexture(GL_TEXTURE_2D, *tempTexture->getTexture());
		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		glLightModeli(GL_LIGHT_MODEL_COLOR_CONTROL,GL_SINGLE_COLOR);
		
		if(Extensions::vboSupported)
		{
			Extensions::glBindBufferARB(GL_ARRAY_BUFFER_ARB,VBOVertices);
			glVertexPointer(3, GL_FLOAT, 0, 0);
			Extensions::glBindBufferARB(GL_ARRAY_BUFFER_ARB,VBOTextureCoords);
			glTexCoordPointer(2, GL_FLOAT, 0, 0);
		}
		else
		{
			glVertexPointer(3, GL_FLOAT, 0, verts);
			glTexCoordPointer(2, GL_FLOAT, 0, coords);
		}
		glDrawArrays(GL_TRIANGLES, 0, points);	
		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glPopMatrix();

}


/**
 * Method is used to load terrain heightmap from *raw file.
 * @param	fileName is path to terrain heightmap *raw file.
 */
void Terrain::loadRawFile(const char* fileName)
{
	FILE *rawFile = NULL;

	rawFile = fopen(fileName, "rb");

	if (rawFile == NULL)											
	{
		printf("Terrain *raw file open error occurred!\n");
		exit(0);
	}

	fread(terrainHeightMap, 1, terrainMapWidth*terrainMapHeight, rawFile);

	if (ferror(rawFile))
	{
		printf("Terrain *raw file read error occurred!\n");
		exit(0);
	}
	fclose(rawFile);
}

}
