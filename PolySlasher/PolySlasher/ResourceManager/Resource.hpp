/**
 * Definition of Resource class.
 * @file    Resource.h
 * @author  Adam Sznajder
 * @date    2010-10-29
 * @version 1.0
 */

#ifndef RESOURCE_HPP
#define RESOURCE_HPP

#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include <string>
#include <iostream>
#include "ResourceType.hpp"

namespace Resource
{

/**
 * File contains declaration of abstract class which will be an interface to communicate with 
 * such resources as audio files or textures.
 */
class Resource
{
protected:
	ResourceType resourceType; // Type of the resource
	std::string name; // Name of the resource
	std::string filepath; // Path to the file;
public:
	ResourceType getResourceType(); // Accessor to resourceType variable.
	std::string getName(); // Accessor to the name variable.
	std::string getFilepath(); // Accessor to the filepath variable;
	virtual void loadResource() = 0;
};
}
#endif

