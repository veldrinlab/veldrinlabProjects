/**
 * Definition of Mesh class.
 * @file    Mesh.cpp
 * @author  Adam Sznajder
 * @date    2010-10-30
 * @version 1.0
 */

#include "Mesh.hpp"

using namespace std;
using namespace Utils;

namespace Resource
{
/**
 * Constructor with initialization values.
 * @param	label is the name of the mesh.
 * @param	path is the path to file with the mesh.
 */
Mesh::Mesh(string label, string path)
{
	resourceType = ResourceType(MESH);
	name = label;
	filepath = string("");
	filepath.assign(path);
}

/**
 * Copy constructor.
 * @param	mesh is the object to copy.
 */
Mesh::Mesh(Mesh& mesh)
{
	resourceType = ResourceType(MESH);
	name = mesh.name;
	filepath = string("");
	filepath.assign(mesh.filepath);
}

/**
 * Destructor.
 */
Mesh::~Mesh()
{
	delete verts;
	delete normals;
	delete coords;
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

/**
 * Overridden method used to load resource from a file.
 */
void Mesh::loadResource()
{
	int vertexNumber = 0;
	std::ifstream meshFile;

	meshFile.open(filepath.c_str());

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

}