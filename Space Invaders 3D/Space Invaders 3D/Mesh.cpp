/**
 * File contains definition of Mesh class.
 * @file    Mesh.cpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2010-12-01
 * @version 1.0
 */

#include "Mesh.h"

/**
 * Constructor with initialize parameters.
 * @param   fileName is mesh file name.
 */
Mesh::Mesh(const char* fileName)
{
	loadMeshFromFile(fileName);
}

/**
 * Destructor, free allocated memory.
 */
Mesh::~Mesh()
{
	delete verts;
	delete normals;
	delete coords;
}

/**
 * Method is used to load mesh from file.
 * @param   fileName is mesh file name.
 */
void Mesh::loadMeshFromFile(const char* fileName)
{
	int vertexNumber = 0;
	std::ifstream meshFile;

	meshFile.open(fileName);

	meshFile >> vertexNumber;

	verts = new Vertex[vertexNumber];
	normals = new Vertex[vertexNumber];
	coords = new TextureCoord[vertexNumber];

	for(int i = 0; i < vertexNumber; ++i)
	{
		meshFile >> verts[i].x;
		meshFile >> verts[i].y;
		meshFile >> verts[i].z;
	}

	for(int i = 0; i < vertexNumber; ++i)
	{
		meshFile >> normals[i].x;
		meshFile >> normals[i].y;
		meshFile >> normals[i].z;
	}

	for(int i = 0; i < vertexNumber; ++i)
	{
		meshFile >> coords[i].u;
		meshFile >> coords[i].v;
	}

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, verts);
	glEnableClientState(GL_NORMAL_ARRAY);
	glNormalPointer(GL_FLOAT, 0, normals);
	glEnableClientState (GL_TEXTURE_COORD_ARRAY);
	glTexCoordPointer(2, GL_FLOAT, 0, coords);

	points = vertexNumber;
	meshFile.close();
}

/**
 * Accessor to mesh verts.
 * @return mesh verts.
 */
Vertex* Mesh::getVerts() const
{
	return verts;
}

/**
 * Accessor to mesh normals.
 * @return mesh normals.
 */
Vertex* Mesh::getNormals() const
{
	return normals;
}

/**
 * Accessor to mesh texture coords.
 * @return mesh texture coords.
 */
TextureCoord* Mesh::getCoords() const
{
	return coords;
}

/**
 * Accessor to mesh point amount.
 * @return mesh point amount.
 */
int Mesh::getPoints() const
{
	return points;
}
