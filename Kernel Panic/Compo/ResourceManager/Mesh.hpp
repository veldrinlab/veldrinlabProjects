/**
 * Declaration of Mesh class.
 * @file    Mesh.h
 * @author  Adam Sznajder
 * @date    2010-10-30
 * @version 1.0
 */

#ifndef MESH_HPP
#define MESH_HPP

#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h> 
#include <GL/gl.h>
#include <fstream>

#include "../Utils/Vertex.hpp"
#include "../Utils/TextureCoord.hpp"
#include "Resource.hpp"


namespace Resource
{
/**
 * Mesh class represents a mesh resource.
 */
class Mesh : public Resource
{
private:
	Utils::Vertex *verts;
	Utils::Vertex *normals;
	Utils::TextureCoord* coords;
	int points;
	Mesh(); // Default resource constructor.
public:
	Mesh(std::string label, std::string filepath);
	Mesh(Mesh& resource); // Copy constructor.
	~Mesh();
	Utils::Vertex* getVerts() const;
	Utils::Vertex* getNormals() const;
	Utils::TextureCoord* getCoords() const;
	int getPoints() const;
	virtual void loadResource(); // used to load a texture from a file
};
}
#endif
