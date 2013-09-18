/**
 * File contains declaration of Shader class.
 * @file    Shader.cpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2010-12-25
 * @version 1.0
 */

#ifndef SHADER_H
#define SHADER_H

#include "Extensions.h"

/**
 * Class represents GLSL Shader class. All engine shaders objects store Vertex and Fragment Shader. It is
 * used to load, compile and bind shader to current scene object. Used to such effects like lighting, bloom 
 * or advanced multitexturing.
 */
class Shader
{
private:
	unsigned int shaderProgram;
	unsigned int shaderVertex;
	unsigned int shaderFragment;

	char* loadShaderSource(const char* shaderFileName);

public:
	Shader();
	Shader(const char* vertexShaderFile, const char* fragmentShaderFile);
	~Shader();

	void initializeShader(const char* vertexShaderFile, const char* fragmentShaderFile);
	void bindShader();
	void unbindShader();
	unsigned int getShaderProgram() const;

};
#endif
