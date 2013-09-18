/**
 * Fle contains declaration and definition of Random class.
 * @file    Random.hpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2010-09-06
 * @version 1.0 
 */

#ifndef RANDOM_HPP
#define RANDOM_HPP

#include "Color.hpp"

#include "../Math/Vector3D.hpp"

namespace Utils
{
#define FRAND ((float)(rand()-rand())/RAND_MAX)

/**
 * Class represents Random class which is used to calculate random int and float values.
 */
class Random
{
private:
	int seed;

public:
	/**
	 * Default constructor, set seed to random 42 value :).
	 */
	Random()
	{
		seed = 42;
	}

	/**
	 * Constructor with initialize parameter.
	 * @param	seed is object seed value.
	 */
	Random(const int seed)
	{
		this->seed = seed;
	}

	/**
	 * Seed setter.
	 * @param	seed is new seed value.
	 */
	void setSeed(const int seed)
	{
		this->seed = seed;
	}

	/**
	 * Method is used to get random integer.
	 * @return	random integer.
	 */
	int getInt()
	{
		return (seed = (seed * 3877 + 29573) % 139968);
	}

	/**
	 * Method is used to get random integer from range.
	 * @param	min is range minimum.
	 * @param	max is range maximum.
	 * @return	random integer.
	 */
	int getInt(const int min, const int max)
	{
		return min + getInt() % (max - min + 1);
	}

	/**
	 * Method is used to get random float.
	 * @return	random float.
	 */
	float getFloat()
	{
		return (seed = (seed * 3877 + 29573) % 139968) / 139967.0f;
	}

	/**
	 * Method is used to get random float from range.
	 * @param	min is range minimum.
	 * @param	max is range maximum.
	 * @return	random float.
	 */
	float getFloat(const float min,const float max)
	{
		return min + getFloat() * (max - min);
	}

	/**
	 * Method is used to get random Color.
	 * @return	random color.
	 */
	Color getColor()
	{
		return Color(getFloat(), getFloat(), getFloat(), getFloat());
	}

	/**
	 * Method is used to get random opaque Color.
	 * @return	random color.
	 */
	Color getOpaqueColor()
	{
		return Color(getFloat(), getFloat(), getFloat(), 1);
	}

	/**
	 * Method is used to get random transparent Color.
	 * @return	random color.
	 */
	Color getTransparentColor()
	{
		return Color(getFloat(), getFloat(), getFloat(), 0);
	}

	/**
	 * Method is used to get random Color from two colors.
	 * @param	colorA is first color.
	 * @param	colorB is second color.
	 * @return	random color.
	 */
	Color getColor(const Color& colorA, const Color& colorB)
	{
		float r = getFloat(colorA.r, colorB.r);
		float g = getFloat(colorA.g, colorB.g);
		float b = getFloat(colorA.b, colorB.b);
		float a = getFloat(colorA.a, colorB.a);

		return Color(r, g, b, a);
	}

	/**
	 * Method is used to get random angle.
	 * @return	float value which represents angle.
	 */
	float getAngle()
	{
		return getFloat() * 6.28318531f;
	}

	/**
	 * Method is used to get random point on circle.
	 * @param	r is circle radius.
	 * @return	random point on circle.
	 */
	Math::Vector3D getPointOnCircle(const float r = 1.0f)
	{
		float angle = getAngle();
		return Math::Vector3D(r * cos(angle), r * sin(angle), 0.0f);
	}

	/**
	 * Method is used to get random Vector3D from each x,y,z values range.
	 * @param minX	is x value range minimum.
	 * @param maxX	is x value range maximum.
	 * @param minY	is y value range minimum.
	 * @param maxY	is y value range maximum.
	 * @param minZ	is z value range minimum.
	 * @param maxZ	is z value range maximum.
	 * @return	random Vector3D.
	 */
	Math::Vector3D getVector3D(const float minX,const  float maxX,const  float minY,const  float maxY, const float minZ,const float maxZ)
	{
		return Math::Vector3D(getFloat(minX, maxX), getFloat(minY, maxY), getFloat(minZ, maxZ));
	}
};
}
#endif
