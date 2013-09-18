/**
 * File contains definition of Vector3D class.
 * @file    Vector3D.cpp
 * @author  Szymon "Veldrin" Jab³oñki
 * @date    2010-09-27
 * @version 1.0
 */

#include "Vector3D.h"

Vector3D::Vector3D(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3D::Vector3D()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;

}

Vector3D Vector3D::operator=(const Vector3D& other)
{
	Vector3D resultVector;

	resultVector.x = other.x;
	resultVector.y = other.y;
	resultVector.z = other.z;

	return resultVector; 
}