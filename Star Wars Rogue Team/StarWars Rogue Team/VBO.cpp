/**
 * File contains definition of Vertex Buffer Object - VBO class.
 * @file    VBO.cpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2010-12-29
 * @version 1.0
 */

#include "VBO.hpp"

namespace engine
{

/**
 * Constructor with initialize parameters.
 * @param	entityMesh is entity model object data.
 */
VBO::VBO(const Mesh& entityMesh)
{
	initializeEntityVBO(entityMesh);
}

/**
 * Default destructor, nothing to do.
 */
VBO::~VBO()
{

}

/**
 * Method is used to initialize Entity Vecrtex Buffer Object data to use GPU for rendering.
 */
void VBO::initializeEntityVBO(const Mesh& entityMesh)
{
	Extensions::glGenBuffersARB(1, &VBOVertices);
	Extensions::glBindBufferARB(GL_ARRAY_BUFFER_ARB, VBOVertices);
	Extensions::glBufferDataARB(GL_ARRAY_BUFFER_ARB, entityMesh.getPoints()*3*sizeof(float),entityMesh.getVerts(),GL_STATIC_DRAW_ARB);

	Extensions::glGenBuffersARB(1, &VBONormals);
	Extensions::glBindBufferARB(GL_ARRAY_BUFFER_ARB, VBONormals);
	Extensions::glBufferDataARB(GL_ARRAY_BUFFER_ARB,entityMesh.getPoints()*3*sizeof(float),entityMesh.getNormals(), GL_STATIC_DRAW_ARB);

	Extensions::glGenBuffersARB(1, &VBOTextureCoords);	    
	Extensions::glBindBufferARB(GL_ARRAY_BUFFER_ARB, VBOTextureCoords);
	Extensions::glBufferDataARB(GL_ARRAY_BUFFER_ARB, entityMesh.getPoints()*2*sizeof(float),entityMesh.getCoords(), GL_STATIC_DRAW_ARB);

}

}
