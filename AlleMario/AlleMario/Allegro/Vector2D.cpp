/**
 * Vector2D.cpp
 * File contains definition of Vector2D class.
 *
 *  Created on: 2010-08-05
 *      Author: Szymon Jab³oñski - Veldrin
 */

#include <iostream>
#include "Vector2D.h"

using namespace std;

Vector2D::Vector2D(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vector2D::Vector2D()
{
	this->x = 0.0f;
	this->y = 0.0f;
}

Vector2D::~Vector2D()
{

}
	
float Vector2D::getX()
{
	return x;
}

float Vector2D::getY()
{
	return y;
}

void Vector2D::setX(float x)
{
	this->x = x;
}

void Vector2D::setY(float y)
{
	this->y = y;
}

Vector2D Vector2D::operator+(const Vector2D& other)
{
	return Vector2D(x + other.x, y + other.y);
}

Vector2D Vector2D::operator-(const Vector2D& other)
{
	return Vector2D(y - other.x, y - other.y);
}

void Vector2D::operator+=(Vector2D other)
{
	x += other.x; 
	y += other.y;
}

Vector2D Vector2D::operator*(float times)
{
	return Vector2D(x * times, y * times);
}