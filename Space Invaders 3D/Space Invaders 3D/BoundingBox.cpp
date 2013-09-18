/**
 * File contains definition of BoundingBox class.
 * @file    BoundingBox.cpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2010-11-27
 * @version 1.0
 */

#include "BoundingBox.h"

/**
 * Constructor with initialize parameters.
 * @param   verts is vertex array.
 * @param   vertexAmount is amount of mesh vertexes.
 */
BoundingBox::BoundingBox(Vertex *verts, int vertexAmount)
{
	min = Vector3D(1000,1000,1000);
	max = Vector3D(-1000,-1000,-1000);

	calculateBoundingBox(verts,vertexAmount);
}

/**
 * Method is used to calculate bounding box memebrs.
 * @param   verts is vertex array.
 * @param   vertexAmount is amount of mesh vertexes.
 */
void BoundingBox::calculateBoundingBox(Vertex *verts, int vertexAmount)
{
	for(int i = 0; i <vertexAmount; ++i)
	{
		if(min.x > verts[i].x) min.x = verts[i].x;
		if(min.y > verts[i].y) min.y = verts[i].y;
		if(min.z > verts[i].z) min.z = verts[i].z;

		if(max.x < verts[i].x) max.x = verts[i].x;
		if(max.y < verts[i].y) max.y = verts[i].y;
		if(max.z < verts[i].z) max.z = verts[i].z;
	}
}

/**
 * Method is used to draw Bounding Box for testing.
 */
void BoundingBox::drawBoundingBox()
{
	glBegin(GL_LINE_LOOP);
	glVertex3f(max.x,max.y,min.z);
	glVertex3f(min.x,max.y,min.z);
	glVertex3f(min.x,min.y,min.z);
	glVertex3f(max.x,min.y,min.z);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3f(max.x,min.y,max.z);
	glVertex3f(max.x,max.y,max.z);
	glVertex3f(min.x,max.y,max.z);
	glVertex3f(min.x,min.y,max.z);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3f(max.x,max.y,min.z);
	glVertex3f(max.x,max.y,max.z);
	glVertex3f(min.x,max.y,max.z);
	glVertex3f(min.x,max.y,min.z);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3f(max.x,min.y,max.z);
	glVertex3f(min.x,min.y,max.z);
	glVertex3f(min.x,min.y,min.z);
	glVertex3f(max.x,min.y,min.z); 
	glEnd();
}
