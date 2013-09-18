/**
 * Vector3D class represents simple three dimmension vector to represents point in three dimmension space.
 * @file    Vector3D.h
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2010-09-27
 * @version 1.0
 */

#ifndef VECTOR3D_H
#define VECTOR3D_H

class Vector3D
{
public:
	float x;
	float y;
	float z;

	Vector3D(float x, float y, float z);
	Vector3D();
	Vector3D operator=(const Vector3D& other);

};
#endif
