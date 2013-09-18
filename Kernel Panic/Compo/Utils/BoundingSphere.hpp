/**
 * File contains declaration and definition od BoundingSphere/BoundingBox class.
 * @file    BoundingSphere.hpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2011-02-28
 * @version 2.0
 */

#ifndef BOUNDING_HPP
#define BOUNDING_HPP


#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h> 
#include <GL/gl.h>
#include "../Math/Vector3D.hpp"

namespace Utils
{

/**
 * Class/structure represents object bounding sphere for collision detection.
 */
class BoundingSphere
{
public:
	Math::Vector3D position;
	float radius;

	/**
	 * Default constructor.
	 */
	BoundingSphere() {};
	
	/** 
	 * Constructor with initialize parameters.
	 * @param	positon is center point vector.
	 * @param	radius is circle radius.
	 */
	BoundingSphere(const Math::Vector3D& position, const float radius)
	{
		this->position = position;
		this->radius = radius;
	}

	/**
	 * Method is used to draw bounding sphere.
	 */
	void drawBoudningSphere()
	{
		glPushMatrix();
			glTranslatef(position.x,position.y,position.z);
			glBegin(GL_LINE_LOOP);
			for(float i=0; i<360; i+=10)
				glVertex2f(radius*static_cast<float>(cos(i/180*3.14)),radius*static_cast<float>(sin(i/180*3.14)));
			glEnd();
		glPopMatrix();
	}
};

/**
 * Class/structure represents object bounding box for collision detection.
 */
class BoundingBox
{
public:
	Math::Vector3D min;
	Math::Vector3D max;

	/**
	 * Default constructor.
	 */
	BoundingBox() {};

	/** 
	 * Constructor with initialize parameters.
	 * @param	min vector.
	 * @param	max vector.
	 */
	BoundingBox(const Math::Vector3D& min, const Math::Vector3D& max)
	{
		this->min = min;
		this->max = max;
	}

	/**
	 * Method is used to draw bounding box.
	 */
	void drawBoundingBox()
	{
		glPushMatrix();
			glBegin(GL_LINE_LOOP);
			glVertex3f(min.x,min.y,0);
			glVertex3f(min.x,max.y,0);
			glVertex3f(max.x,max.y,0);
			glVertex3f(max.x,min.y,0);
			glEnd();
		glPopMatrix();
	}
};

}
#endif

