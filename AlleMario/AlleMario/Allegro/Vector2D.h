/**
 * Vector2D.h
 * Simple class represents two dimmension vector.
 * 
 *  Created on: 2010-08-05
 *      Author: Szymon Jab³oñski - Veldrin
 */

#ifndef VECTOR2D_H
#define VECTOR2D_H

class Vector2D
{
private:
	float x;
	float y;

public:
	Vector2D(float x, float y);
	Vector2D();
	~Vector2D();
	
	float getX();
	float getY();
	void setX(float x);
	void setY(float y);
	Vector2D operator+(const Vector2D& other);
	Vector2D operator-(const Vector2D& other);
	void operator+=(Vector2D other);
	Vector2D operator*(float times);
};
#endif
