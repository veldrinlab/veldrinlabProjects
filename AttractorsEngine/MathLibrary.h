/**
 * MathLibrary contains static math functions. It is faster alternative of math.h library.
 * @file    MathLibrary.h
 * @author  Szymon "Veldrin" Jabłońki
 * @date    2010-09-27
 * @version 1.0
 */

#ifndef MATHLIBRARY_H
#define MATHLIBRARY_H

class MathLibrary
{
public:
	static float sin(const float x)
	{
		const float x2 = x*x;
		const float x3 = x*x2;
		const float x5 = x3*x2;
		return x - x3/6.0f + x5/120.0f ;
	}

	static float cos(const float x)
	{
		const float x2 = x*x;
		const float x4 = x2*x2;
		return 1.0f - x2/2.0f + x4/24.0f;
	}

};
#endif
