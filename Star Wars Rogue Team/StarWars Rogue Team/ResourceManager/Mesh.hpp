/**
 * Declaration of Mesh class.
 * @file    Mesh.h
 * @author  Adam Sznajder
 * @date    2010-10-30
 * @version 1.0
 */


#ifndef MESH_H
#define MESH_H

#include <fstream>
#include <SDL.h>
#include <SDL_opengl.h> 
#include <GL/gl.h>

#include "../Vertex.hpp"
#include "../TextureCoord.hpp"
#include "Resource.hpp"

using namespace engine;

namespace resMan
{
/**
 * Mesh class represents a mesh resource.
 */
class Mesh : public Resource
{
private:
	Vertex *verts;
	Vertex *normals;
	TextureCoord* coords;
	int points;
	Mesh(); // Default resource constructor.
public:
	Mesh(std::string label, std::string filepath);
	Mesh(Mesh& resource); // Copy constructor.
	~Mesh();
	Vertex* getVerts() const;
	Vertex* getNormals() const;
	TextureCoord* getCoords() const;
	int getPoints() const;
	virtual void loadResource(); // used to load a texture from a file
};
}
#endif
