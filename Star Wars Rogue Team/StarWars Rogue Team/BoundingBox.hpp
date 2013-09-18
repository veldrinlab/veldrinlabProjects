/**
 * File contains declaration of BoundingBox class.
 * @file    BoundingBox.hpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2010-11-26
 * @version 1.0
 */

#ifndef BOUNDINGBOX_HPP
#define BOUNDINGBOX_HPP

#include <SDL.h>
#include <SDL_opengl.h> 
#include <GL/gl.h>

#include "Vector3D.hpp"
#include "Vertex.hpp"

using namespace math;

namespace engine
{

/**
 * Class represents two Vector3D objects used in collision detection between objects based on
 * BoundingBoxes algorithm.
 * @remarks
 */
class BoundingBox
{
public:
	Vector3D min;
	Vector3D max;
	
	BoundingBox() {};
	BoundingBox(Vertex *verts, int vertexAmount);

	void calculateBoundingBox(Vertex *verts, int vertexAmount);
	void drawBoundingBox();
};

}
#endif 
