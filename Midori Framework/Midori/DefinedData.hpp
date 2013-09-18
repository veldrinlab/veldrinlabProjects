#ifndef DEFINEDDATA_HPP
#define DEFINEDDATA_HPP

#include <GL/glew.h>

namespace Midori
{
	const int quadVertexAmount = 4;
	const int quadTriangleAmount = 2;

	const GLfloat quadVertices[quadVertexAmount*3] =
	{
		1.000000f, 1.000000f, 0.000000f,
		-1.000000f, 1.000000f, 0.000000f,
		-1.000000f, -1.000000f, 0.000000f,
		1.000000f, -1.000000f, 0.000000f
	};

	const GLfloat quadNormals[quadVertexAmount*3] =
	{
		0.000000f, 0.000000f, 1.000000f,
		0.000000f, 0.000000f, 1.000000f,
		0.000000f, 0.000000f, 1.000000f,
		0.000000f, 0.000000f, 1.000000f
	};

	const GLfloat quadUV[quadVertexAmount*2] =
	{
		1.000000f, 0.000000f, 
		0.000000f, 0.000000f,
		0.000000f, 1.000000f,
		1.000000f, 1.000000f
	};

	const unsigned int quadIndices[quadTriangleAmount*3] =
	{
		0,1,2,
		0,2,3
	};
}
#endif
