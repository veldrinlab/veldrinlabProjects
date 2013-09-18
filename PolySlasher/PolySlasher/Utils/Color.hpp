/**
 * File contains declaration and definition od Color class.
 * @file    Color.hpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2010-09-04
 * @version 2.0
 */

#ifndef COLOR_HPP
#define COLOR_HPP

#include <math.h>

namespace Utils
{

/**
 * Class represets color representation in RGBA format.
 */
class Color
{
public:
	float r;
	float g;
	float b;
	float a;

	/**
	 * Default constructor, set all class members to 0.0f.
	 */
	Color()
	{
		r = 0.0f;
		g = 0.0f;
		b = 0.0f;
		a = 0.0f;
	}

	/**
	 * Constructor with initialize parameters.
	 * @param	r is red amount.	
	 * @param	g is green amount.
	 * @param	b is blue amount.
	 * @param	a is alpha canal.
	 */
	Color(const float r,const float g,const float b,const float a = 1.0f) : r(r), g(g), b(b), a(a){}

	/**
	 * Copy constructor.
	 * @param	object to copy.
	 */
	Color(const Color& v) : r(v.r), g(v.g), b(v.b), a(v.a)
	{

	}

	/**
	 * Class assign operator.
	 */
	Color& operator=(const Color& v)
	{
		r = v.r;
		g = v.g;
		b = v.b;
		a = v.a;

		return *this;
	}

	/**
	 * Class addition operator.
	 */
	Color& operator+=(const Color& v)
	{
		r += v.r;
		g += v.g;
		b += v.b;
		a += v.a;

		return *this;
	}

	/**
	 * Class substraction operator.
	 */
	Color& operator -=(const Color& v)
	{
		r -= v.r;
		g -= v.g;
		b -= v.b;
		a -= v.a;

		return *this;
	}

	/**
	 * Class multiply operator.
	 */
	Color& operator *=(float f)
	{
		r *= f;
		g *= f;
		b *= f;
		a *= f;

		return *this;
	}

	/**
	 * Class divide operator.
	 */
	Color& operator/=(float f)
	{
		float invF = 1.0f / f;
		
		r *= invF;
		g *= invF;
		b *= invF;
		a *= invF;

		return *this;
	}

	/**
	 * Class addition operator.
	 */
	Color operator+(const Color& v) const
	{
		return Color(r + v.r, g + v.g, b + v.b, a + v.a);
	}

	/**
	 * Class substraction operator.
	 */
	Color operator-(const Color& v) const
	{
		return Color(r - v.r, g - v.g, b - v.b, a - v.a);
	}

	/**
	 * Class multiply operator.
	 */
	Color operator*(float f) const
	{
		return Color(r * f, g * f, b * f, a * f);
	}

	/**
	 * Class divide operator.
	 */
	Color operator/(float f) const
	{
		float invF = 1.0f / f;
		return Color(r * invF, g * invF, b * invF, a * invF);
	}
};

}
#endif
