/**
 * File contains declaration of Texture class.
 * @file    Texture.h
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2010-12-01
 * @version 1.0
 */

#ifndef TEXTURE_H
#define TEXTURE_H

#include <SDL.h>
#include <SDL_opengl.h> 
#include <SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>

/**
 * Class is used to load and store OpenGL type of Texture.
 * @remarks 
 */
class Texture
{
private:
	GLuint texture;

public:
	Texture(const char* fileName);
	Texture() {};
	~Texture();
	
	void loadTextureFromFile(const char* fileName);
	GLuint* getTexture();
};
#endif 
