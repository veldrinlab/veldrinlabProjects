/**
 * Definition of Texture class.
 *
 * @file    Texture.cpp
 * @author  Adam Sznajder
 * @date    2010-10-29
 * @version 1.0
 */

#include "Texture.hpp"

using namespace std;

namespace resMan
{

/**
 * Constructor with initialization values.
 * @param	label is the name of the resource. It should be uniqe for every resource of defined type.
 * @param	path is the path to resource's file.
 */
Texture::Texture(string label, string path)
{
	resourceType = ResourceType(TEXTURE);
	name = new string("");
	name->assign(label);
	filepath = string("");
	filepath.assign(path);
}

/**
 * Copy constructor.
 * @param	texture is the object which will be copied.
 */
Texture::Texture(Texture& texture)
{
	resourceType = ResourceType(TEXTURE);
	name = new string("");
	name->assign(*(texture.name));
	filepath = string("");
	filepath.assign(texture.filepath);
	this->texture = texture.texture;
}

/**
 * Overridden method used to load resource from a file.
 */
void Texture::loadResource()
{
	SDL_Surface *surface;
	GLenum texture_format;
	GLint  nOfColors;

	if(surface = IMG_Load(filepath.c_str()))
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
 * Accessor to texture variable.
 * @return	value of texture variable.
 */
GLuint* Texture::getTexture()
{
	return &texture;
}

}