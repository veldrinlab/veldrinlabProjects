/**
 * File contains definition of Texture class.
 * @file    Texture.cpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2010-12-01
 * @version 1.0
 */

#include "Texture.h"

/**
 * Constructor with initialize parameters.
 * @param   fileName is texture file name.
 */
Texture::Texture(const char* fileName)
{
	loadTextureFromFile(fileName);
}

/**
 * Destructor, free allocated memory.
 */
Texture::~Texture()
{
	glDeleteTextures(1,&texture);
}

/**
 * Method is used to load texture from file and convert it to OpenGL format.
 * @param   fileName is texture file name.
 */
void Texture::loadTextureFromFile(const char* fileName)
{
	SDL_Surface *surface;
	GLenum texture_format;
	GLint  nOfColors;

	if(surface = IMG_Load(fileName))
	{
		if((surface->w & (surface->w - 1)) != 0)
			printf("warning: width is not a power of 2\n");
	
		if((surface->h & (surface->h - 1)) != 0)
			printf("warning: height is not a power of 2\n");
 
        nOfColors = surface->format->BytesPerPixel;
        if(nOfColors == 4)
        {
			if(surface->format->Rmask == 0x000000ff)
				texture_format = GL_RGBA;
            else
				texture_format = GL_BGRA;
        }
		else if(nOfColors == 3)
        {
			if(surface->format->Rmask == 0x000000ff)
				texture_format = GL_RGB;
            else
				texture_format = GL_BGR;
        } 
		else
		{
			printf("warning: the image is not truecolor..  this will probably break\n");
        }
        
		glGenTextures( 1, &texture );
		glBindTexture( GL_TEXTURE_2D, texture );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
		glTexImage2D( GL_TEXTURE_2D, 0, nOfColors, surface->w, surface->h, 0,
                      texture_format, GL_UNSIGNED_BYTE, surface->pixels );

	}
	else
	{
		printf("SDL could not load image: %s\n", SDL_GetError());
		SDL_Quit();
	}

	if (surface)
		SDL_FreeSurface(surface);
}

/**
 * Accessor to texture.
 * @return stored texture
 */
GLuint* Texture::getTexture()
{
	return &texture;
}