/**
 * Declaration of Texture class.
 *
 * @file    Texture.h
 * @author  Adam Sznajder
 * @date    2010-10-29
 * @version 1.0
 */

#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h> 
#include <SDL/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "Resource.hpp"
#include "ResourceType.hpp"
#include "../Utils/TextureCoord.hpp"

namespace Resource
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
	~Texture();
	Texture(std::string label, std::string filepath);
	Texture(Texture& resource); // Copy constructor.
	GLuint* getTexture(); // Accessor to texture.
	virtual void loadResource(); // used to load a texture from a file
};

}

#endif
