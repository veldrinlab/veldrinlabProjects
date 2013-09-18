/**
 * File contains definition of Shader class.
 * @file    Shader.cpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2010-12-25
 * @version 1.0
 */

#include <iostream>
#include <stdlib.h>
#include "Shader.hpp"

using namespace std;

namespace engine
{

/**
 * Default constructor.
 */
Shader::Shader()
{

}
/** 
 * Constructor with initialize parameters.
 * @param	vertexShaderFile is source code of Vertex Shader.
 * @param	fragmentShaderFile is source code of Fragment Shader.
 */
Shader::Shader(const char* vertexShaderFile, const char* fragmentShaderFile)
{
	if(Extensions::shaderSupported)
		initializeShader(vertexShaderFile,fragmentShaderFile);
}

/**
 * Default destructor. Detach and delete shader program.
 */
Shader::~Shader()
{
	if(Extensions::shaderSupported)
	{
		Extensions::glDetachShader(shaderProgram, shaderFragment);
		Extensions::glDetachShader(shaderProgram, shaderVertex);
		Extensions::glDeleteShader(shaderFragment);
		Extensions::glDeleteShader(shaderVertex);
		Extensions::glDeleteProgram(shaderProgram);
	}
}

/**
 * Method is used to load Shader source code.
 * @param	shaderFileName is path to shader program source code.
 * @return	loaded shader source code string.
 */
char* Shader::loadShaderSource(const char* shaderFileName)
{
	char* shaderSource = NULL;
    
	if (shaderFileName != NULL)
	{
		FILE *file = fopen(shaderFileName, "rt");
        
		if (file != NULL)
		{
            fseek(file, 0, SEEK_END);
            int count = ftell(file);
            rewind(file);
            
			if (count > 0)
			{
				// use new
				shaderSource = (char*)malloc(sizeof(char) * (count + 1));
				count = fread(shaderSource, sizeof(char), count, file);
				shaderSource[count] = '\0';
			}
			fclose(file);
		}
	}
	return shaderSource;
}

/**
 * Method is used to initialize Shader object. Create Vertex and Fragment shaders, validate it, compile
 * and create shader program.
 * @param	vertexShaderFile is source code of Vertex Shader.
 * @param	fragmentShaderFile is source code of Fragment Shader.
 */	
void Shader::initializeShader(const char* vertexShaderFile, const char* fragmentShaderFile)
{
	shaderVertex = Extensions::glCreateShader(GL_VERTEX_SHADER);
	shaderFragment = Extensions::glCreateShader(GL_FRAGMENT_SHADER);

	const char* vertexShaderSource = loadShaderSource(vertexShaderFile);
	const char* fragmentShaderSource = loadShaderSource(fragmentShaderFile);

	if(vertexShaderSource == NULL || fragmentShaderSource == NULL)
	{
		printf("Shader loading error detected!\n");
		exit(1);
	}

	Extensions::glShaderSource(shaderVertex,1,&vertexShaderSource,0);
	Extensions::glShaderSource(shaderFragment,1,&fragmentShaderSource,0);
	delete vertexShaderSource;
	delete fragmentShaderSource;

	Extensions::glCompileShader(shaderVertex);
	Extensions::glCompileShader(shaderFragment);

	shaderProgram = Extensions::glCreateProgram();
	Extensions::glAttachShader(shaderProgram,shaderVertex);
	Extensions::glAttachShader(shaderProgram,shaderFragment);
	Extensions::glLinkProgram(shaderProgram);

}

/**
 * Method is used to bind shader program.
 */
void Shader::bindShader()
{
	if(Extensions::shaderSupported)
		Extensions::glUseProgram(shaderProgram);

}

/**
 * Method is used to unbind shader program.
 */
void Shader::unbindShader()
{
	if(Extensions::shaderSupported)
		Extensions::glUseProgram(0);
}

/**
 * Accessor to shader program.
 * @return	shader program id.
 */
unsigned int Shader::getShaderProgram() const
{
	return shaderProgram;
}

}
