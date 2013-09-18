#include "MidoriApi.hpp"

using namespace sf;
using namespace std;

namespace Midori
{
	void createWindow(Window* app)
	{
		app->contextSettings =  ContextSettings(24,8,0,3,3);
		app->contextVideoMode = VideoMode(WIDTH,HEIGHT,32);
		app->contextWindow = new sf::Window(app->contextVideoMode,"Midori - NG4 Logo identify tool", Style::Close,app->contextSettings);
		app->contextWindow->SetActive();
		app->contextWindow->ShowMouseCursor(true);
		app->contextWindow->SetCursorPosition(WIDTH/2,HEIGHT/2);
	}

	void configureContext()
	{
		GLenum glewError;
		glewExperimental = GL_TRUE;
		if(glewError = glewInit() != GLEW_OK)
			cerr << "Error: " << glewGetErrorString(glewError) << endl;
		if(!GLEW_VERSION_3_3) 
			cerr << "Error: OpenGL 3.3 is required" << endl;

		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		glEnable(GL_BLEND);
		glBlendFunc(GL_ONE, GL_ONE);
		
		if(ilGetInteger(IL_VERSION_NUM) < IL_VERSION)
			cerr <<"Wrong DevIL version detected!" << endl;

		ilInit();
		glPixelStorei(GL_UNPACK_ALIGNMENT,1);
	}

	void configureView(Midori::View* view)
	{
		view->modelMatrix.LoadIdentity();
		view->viewMatrix.LoadIdentity();
		view->projectionMatrix.LoadIdentity();
		view->projectionMatrix.Ortho2D(-WIDTH,WIDTH,-HEIGHT,HEIGHT);
		view->projectionMatrix.transpose();
		glViewport(0, 0,static_cast<GLsizei>(WIDTH), static_cast<GLsizei>(HEIGHT));
	}

	void loadTexture(Midori::Texture* texture, const std::string& path)
	{
		ILuint texID;
		ilGenImages(1,&texID);
		ilBindImage(texID);
			
		if(!ilLoadImage((const ILstring)path.c_str()))
			cerr << "Error loading image " << path << endl;

		if(!ilConvertImage(IL_RGBA,IL_UNSIGNED_BYTE))
			cerr << " Error converting image " << path << endl;
		
		glGenTextures(1,&texture->id);
		glBindTexture(GL_TEXTURE_RECTANGLE,texture->id);
		glTexParameteri(GL_TEXTURE_RECTANGLE,GL_TEXTURE_WRAP_S,GL_CLAMP);
		glTexParameteri(GL_TEXTURE_RECTANGLE,GL_TEXTURE_WRAP_T,GL_CLAMP);
		glTexParameteri(GL_TEXTURE_RECTANGLE,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexParameteri(GL_TEXTURE_RECTANGLE,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

		glTexImage2D(GL_TEXTURE_RECTANGLE,0,ilGetInteger(IL_IMAGE_BPP),ilGetInteger(IL_IMAGE_WIDTH),
			  ilGetInteger(IL_IMAGE_HEIGHT),0,ilGetInteger(IL_IMAGE_FORMAT),GL_UNSIGNED_BYTE,ilGetData());
		
		ilDeleteImages(1, &texID);
	}

	void releaseTexture(Midori::Texture* texture)
	{
		glDeleteTextures(1,&texture->id);
	}

	void loadShader(Midori::Shader* shader, const std::string& vertex, const std::string& fragment)
	{
		shader->vertexShader = glCreateShader(GL_VERTEX_SHADER);
		shader->fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		shader->id = glCreateProgram();
		
		const char* vertexShaderSource = loadShaderSource(vertex.c_str());
		const char* fragmentShaderSource = loadShaderSource(fragment.c_str());

		if(vertexShaderSource == nullptr || fragmentShaderSource == nullptr)
			cerr << " Shader loading error " << vertex << " " << fragment << cerr;
	
		glShaderSource(shader->vertexShader,1,&vertexShaderSource,0);
		glShaderSource(shader->fragmentShader,1,&fragmentShaderSource,0);	
		glCompileShader(shader->vertexShader);
		glCompileShader(shader->fragmentShader);
		glAttachShader(shader->id,shader->vertexShader);
		glAttachShader(shader->id,shader->fragmentShader);
		glLinkProgram(shader->id);

		delete vertexShaderSource;
		delete fragmentShaderSource;
	}

	void releaseShader(Midori::Shader* shader)
	{
		glDetachShader(shader->id,shader->vertexShader);
		glDeleteShader(shader->vertexShader);
		glDetachShader(shader->id,shader->fragmentShader);
		glDeleteShader(shader->fragmentShader);
		glDeleteProgram(shader->id);
	}

	char* loadShaderSource(const char* shaderFileName)
	{
		char* shaderSource = nullptr;
    
		if(shaderFileName != nullptr)
		{
			ifstream file;
			file.open(shaderFileName, ios::binary);
		
			if(file.is_open())
			{
				file.seekg(0,ios::end);
				int count = static_cast<int>(file.tellg());
				file.seekg(0,ios::beg);
			
				if(count > 0)
				{
					shaderSource = new char[count + 1];
					file.read(shaderSource, count * sizeof(char));
					shaderSource[count] = '\0';
				}
			}
			else
				cerr << " Shader source loading error" << shaderFileName << endl;
			file.close();
		}
		
		return shaderSource;
	}

	void createImage(Midori::Image* image, Midori::Texture* texture, Midori::Shader* shader)
	{
		image->texture = texture;
		image->shader = shader;

		AyumiEngine::AyumiUtils::Vertex<> vertices[4];
		unsigned int indices[quadTriangleAmount*3];

		for(int i = 0, i2 = 0, i3 = 0; i < quadVertexAmount; ++i)
		{
			vertices[i].x = quadVertices[i2];
			vertices[i].nx = quadNormals[i2++];
			vertices[i].y = quadVertices[i2];
			vertices[i].ny = quadNormals[i2++];
			vertices[i].z = quadVertices[i2];
			vertices[i].nz = quadNormals[i2++];
			vertices[i].u = quadUV[i3++];
			vertices[i].v = quadUV[i3++];
		}

		for(int i = 0; i < quadTriangleAmount*3; ++i)
			indices[i] = quadIndices[i];

		for(int i = 0; i < quadVertexAmount; ++i)
		{
			vertices[i].u *= WIDTH;
			vertices[i].v *= HEIGHT;
		}

		glGenVertexArrays(1,&image->vao);
		glBindVertexArray(image->vao);
		glGenBuffers(1,&image->vertexBuffer);
		glBindBuffer(GL_ARRAY_BUFFER,image->vertexBuffer);
		glBufferData(GL_ARRAY_BUFFER,quadVertexAmount*12*sizeof(float),vertices,GL_STATIC_DRAW);
		glGenBuffers(1,&image->indicesBuffer);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,image->indicesBuffer);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER,quadTriangleAmount*3*sizeof(unsigned int),indices,GL_STATIC_DRAW);
		glVertexAttribPointer(glGetAttribLocation(image->shader->id,"vertex"), 3, GL_FLOAT, GL_FALSE, sizeof(AyumiEngine::AyumiUtils::Vertex<>), reinterpret_cast<const GLubyte *>(0) + 0);
		glVertexAttribPointer(glGetAttribLocation(image->shader->id,"texCoord"), 2, GL_FLOAT, GL_FALSE, sizeof(AyumiEngine::AyumiUtils::Vertex<>), reinterpret_cast<const GLubyte *>(0) + sizeof(float)*6);
		glBindBuffer(GL_ARRAY_BUFFER,image->vertexBuffer);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,image->indicesBuffer);
		glEnableVertexAttribArray(glGetAttribLocation(image->shader->id,"vertex"));
		glEnableVertexAttribArray(glGetAttribLocation(image->shader->id,"texCoord"));	
	}

	void releaseImage(Midori::Image* image)
	{
		glDeleteVertexArrays(1,&image->vao);
		glDeleteBuffers(1,&image->vertexBuffer);
		glDeleteBuffers(1,&image->indicesBuffer);
	}

	void createFrameBuffer(Midori::FrameBuffer* fbo, const int width, const int height)
	{
		if(width <= 0 || height <= 0)
			std::cerr << "Frame Buffer wrong width/height error" << std::endl; 

		glGenFramebuffers(1,&fbo->frameBuffer);
		glBindFramebuffer(GL_FRAMEBUFFER,fbo->frameBuffer);
			
		glGenTextures(1,&fbo->colorBuffer);
		glBindTexture(GL_TEXTURE_RECTANGLE,fbo->colorBuffer);
		glTexImage2D(GL_TEXTURE_RECTANGLE,0,GL_RGBA,width,height,0,GL_RGBA,GL_UNSIGNED_BYTE,nullptr);
		glTexParameteri(GL_TEXTURE_RECTANGLE,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
		glTexParameteri(GL_TEXTURE_RECTANGLE,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
		glTexParameteri(GL_TEXTURE_RECTANGLE,GL_TEXTURE_WRAP_S,GL_CLAMP);
		glTexParameteri(GL_TEXTURE_RECTANGLE,GL_TEXTURE_WRAP_T,GL_CLAMP);
		glFramebufferTexture2D(GL_FRAMEBUFFER,GL_COLOR_ATTACHMENT0,GL_TEXTURE_RECTANGLE,fbo->colorBuffer,0);
		
		GLenum status = glCheckFramebufferStatus(GL_FRAMEBUFFER);
			
		if(status != GL_FRAMEBUFFER_COMPLETE)
			cerr << "Frame Buffer creation error" << endl;

		glBindFramebuffer(GL_FRAMEBUFFER, 0);
	}

	void releaseFrameBuffer(Midori::FrameBuffer* fbo)
	{
		glDeleteFramebuffers(1,&fbo->frameBuffer);
		glDeleteTextures(1,&fbo->colorBuffer);
	}

	void renderImage(Midori::Image* image, Midori::View* view, bool rotated)
	{		
		glBindVertexArray(image->vao);
		glUseProgram(image->shader->id);
		view->modelMatrix.LoadIdentity();
		view->modelMatrix.Translatef(0.0f,0.0f,0.0f);
		view->modelMatrix.Scalef(static_cast<float>(WIDTH),static_cast<float>(HEIGHT),0.0f);

		if(rotated)
		{
			AyumiEngine::AyumiMath::Quaternion rotate(AyumiEngine::AyumiMath::Vector3D(1.0f,0.0f,0.0f),180.0f); 
			rotate *= AyumiEngine::AyumiMath::Quaternion(AyumiEngine::AyumiMath::Vector3D(0.0f,1.0f,0.0f),0.0f); 
			view->modelMatrix *= rotate.matrix4(); 
		}

		glUniformMatrix4fv(glGetUniformLocation(image->shader->id,"projectionMatrix"),1,GL_FALSE,view->projectionMatrix.data());
		glUniformMatrix4fv(glGetUniformLocation(image->shader->id,"modelViewMatrix"),1,GL_FALSE,view->modelMatrix.transpose().data());
		glUniform1i(glGetUniformLocation(image->shader->id, "ColorMapSampler"), 0);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_RECTANGLE,image->texture->id);
		glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,NULL);
		glUseProgram(0);
		glBindVertexArray(0);
	}

	void renderToTexture(Midori::FrameBuffer* fbo, Midori::Image* image, Midori::View* view, Midori::Shader* shader)
	{
		image->shader = shader;
		glBindFramebuffer(GL_FRAMEBUFFER,fbo->frameBuffer);
		glClear(GL_COLOR_BUFFER_BIT);	
		Midori::renderImage(image,view,true);
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
	}

	void renderSegmentToTexture(Midori::FrameBuffer* fbo, Midori::Image* image, Midori::View* view, Midori::Shader* shader, FrameBuffer* frames, GLfloat color)
	{
		image->shader = shader;
		glBindFramebuffer(GL_FRAMEBUFFER,fbo->frameBuffer);
		glClear(GL_COLOR_BUFFER_BIT);	

		glBindVertexArray(image->vao);
		glUseProgram(image->shader->id);
		view->modelMatrix.LoadIdentity();
		view->modelMatrix.Translatef(0.0f,0.0f,0.0f);
		view->modelMatrix.Scalef(static_cast<float>(WIDTH),static_cast<float>(HEIGHT),0.0f);
		AyumiEngine::AyumiMath::Quaternion rotate(AyumiEngine::AyumiMath::Vector3D(1.0f,0.0f,0.0f),180.0f); 
		rotate *= AyumiEngine::AyumiMath::Quaternion(AyumiEngine::AyumiMath::Vector3D(0.0f,1.0f,0.0f),0.0f); 
		view->modelMatrix *= rotate.matrix4(); 

		glUniformMatrix4fv(glGetUniformLocation(image->shader->id,"projectionMatrix"),1,GL_FALSE,view->projectionMatrix.data());
		glUniformMatrix4fv(glGetUniformLocation(image->shader->id,"modelViewMatrix"),1,GL_FALSE,view->modelMatrix.transpose().data());
		glUniform1i(glGetUniformLocation(image->shader->id, "ColorMapSamplerSampler"), 0);
		glUniform1f(glGetUniformLocation(image->shader->id,"color"),color);

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_RECTANGLE,frames->colorBuffer);
		
		glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,NULL);
		glUseProgram(0);
		glBindVertexArray(0);
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
	}
}
