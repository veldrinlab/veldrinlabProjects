/**
 * File contains declaration of Vertex Buffer Object - VBO class.
 * @file    VBO.h
 * @author  Szymon Jab³oñski
 * @date    2010-12-29
 * @version 1.0
 */

#ifndef VBO_H
#define VBO_H

#include "Mesh.h"
#include "Extensions.h"

/**
 * Class represents Vertex Buffer Object which is used to initiailize and store VBO object connected with scene
 * scene entity. It is used to render objects by using GPU power.
 */
class VBO
{
public:
	unsigned int VBOVertices;
	unsigned int VBONormals;
	unsigned int VBOTextureCoords;

	void initializeEntityVBO(const Mesh& entityMesh);

	VBO(const Mesh& entityMesh);
	~VBO();
};
#endif
