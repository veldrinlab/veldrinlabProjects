/**
 * Declaration of Texture class.
 *
 * @file    Texture.h
 * @author  Adam Sznajder
 * @date    2010-10-29
 * @version 1.0
 */

#ifndef TEXTURE_H
#define TEXTURE_H

#include "Resource.hpp"
#include "ResourceType.hpp"
#include <SDL.h>
#include <SDL_opengl.h> 
#include <SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "../TextureCoord.hpp"

namespace resMan
{

/**
 * Class which represents a texture resource.
 */
class Texture : public Resource
{
private:
	GLuint texture;
	Texture(); // Default resource constructor.
public:
	~Texture() { delete name; }; // Default resource destructor.
	Texture(std::string label, std::string filepath);
	Texture(Texture& resource); // Copy constructor.
	GLuint* getTexture(); // Accessor to texture.
	virtual void loadResource(); // used to load a texture from a file
};

}

#endif
