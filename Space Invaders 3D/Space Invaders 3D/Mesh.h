/**
 * File contains declaration of Mesh class.
 * @file    Mesh.h
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2010-12-01
 * @version 1.0
 */

#ifndef MESH_H
#define MESH_H

#include <SDL.h>
#include <SDL_opengl.h> 
#include <GL/gl.h>
#include <fstream>

#include "Vertex.h"
#include "TextureCoord.h"

/**
 * Class is used to represent 3D model, created in Blender application and exported to OpenGL format.
 * Class is used to load and store mesh data.
 * @remarks
 */
class Mesh
{
private:
	Vertex *verts;
	Vertex *normals;
	TextureCoord* coords;
	int points;

public:
	Mesh(const char* fileName);
	Mesh() {};
	~Mesh();

	void loadMeshFromFile(const char* fileName);

	Vertex* getVerts() const;
	Vertex* getNormals() const;
	TextureCoord* getCoords() const;
	int getPoints() const;
};
#endif 
