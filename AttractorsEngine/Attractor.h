/**
 * Attractor class represents abstract class of procedural generating graphics like texture, fractals 
 * and of course strange attractors. All class represents each type of strange attractors like PicOver
 * or Peter De Jung must extend Attractor class.
 * @file    Attractor.h
 * @author  Szymon "Veldrin" Jabłoński
 * @date    2010-09-27
 * @version 1.0
 */

#ifndef ATTRACTOR_H
#define ATTRACTOR_H

#include <SDL.h>
#include <math.h>

#include "Pixel.h"
#include "Vector3D.h"
#include "MathLibrary.h"


class Attractor
{
protected:
	unsigned int* imageBuffer;
	Vector3D originPosition;
	Vector3D destinationPosition;
	int pointAmount;

public:
	virtual void generateAttractor() = 0;
	virtual void putPixel(unsigned int* imageBuffer, const int x, const int y) = 0;
	
	void scaleImageBuffer(SDL_Surface* screen)
	{
		Pixel* bufferPixel = (Pixel*)imageBuffer;
		Pixel* screenPixel = (Pixel*)screen->pixels;

		for (int i=1024*768; i--;)
		{
			int y = i>>10;
			int x = i-(y<<10);

			int p = x*2+(y<<12);		

			const Pixel* bufferPixel1 = bufferPixel+p;
			const Pixel* bufferPixel2 = bufferPixel1+2048;

			screenPixel[i].r = (bufferPixel1[0].r+bufferPixel1[1].r+bufferPixel2[0].r+bufferPixel2[1].r)>>2;
			screenPixel[i].g = (bufferPixel1[0].g+bufferPixel1[1].g+bufferPixel2[0].g+bufferPixel2[1].g)>>2;
			screenPixel[i].b = (bufferPixel1[0].b+bufferPixel1[1].b+bufferPixel2[0].b+bufferPixel2[1].b)>>2;
		}

	}

	unsigned int* getImageBuffer()
	{
		return imageBuffer;
	}

};


class PickOver : public Attractor
{
protected:
	float a;
	float b;
	float c;
	float d;
	float e;

public:
	PickOver(int pointAmount, float a, float b, float c, float d, float e);
	PickOver(){};
	virtual ~PickOver();

	void generateAttractor();
	void putPixel(unsigned int* imageBuffer, const int x, const int y);

};

class PickOverModified : public PickOver
{
public:
	PickOverModified(int pointAmount, float a, float b, float c, float d, float e);
	~PickOverModified();

	void generateAttractor();
	void putPixel(unsigned int* imageBuffer, const int x, const int y);

};



class PolyNomialTypeA : public Attractor
{
private:
	float a;
	float b;
	float c;

public:
	PolyNomialTypeA(int pointAmount, float a, float b, float c);
	~PolyNomialTypeA();

	void generateAttractor();
	void putPixel(unsigned int* imageBuffer, const int x, const int y);

};

class Trigonometric : public Attractor
{
protected:
	float a;
	float b;
	float c;
	float d;
	float e;
	float f;

public:
	Trigonometric(int pointAmount, float a, float b, float c, float d, float e, float f);
	Trigonometric(){};
	~Trigonometric();

	void generateAttractor();
	void putPixel(unsigned int* imageBuffer, const int x, const int y);

};

class Trigonometric2 : public Trigonometric
{
public:
	Trigonometric2(int pointAmount, float a, float b, float c, float d, float e, float f);
	~Trigonometric2();

	void generateAttractor();
	void putPixel(unsigned int* imageBuffer, const int x, const int y);


};

class Trigonometric3 : public Trigonometric
{
public:
	Trigonometric3(int pointAmount, float a, float b, float c, float d, float e, float f);
	~Trigonometric3();

	void generateAttractor();
	void putPixel(unsigned int* imageBuffer, const int x, const int y);


};

class Clifford : public Attractor
{
private:
	float a;
	float b;
	float c;
	float d;
	float e;

public:
	Clifford(int pointAmount, float a, float b, float c, float d, float e);
	~Clifford();

	void generateAttractor();
	void putPixel(unsigned int* imageBuffer, const int x, const int y);

};


class Lorenz : public Attractor
{
private:
	float a;
	float b;
	float c;
	float d;

public:
	Lorenz(int pointAmount, float a, float b, float c, float d);
	~Lorenz();

	void generateAttractor();
	void putPixel(unsigned int* imageBuffer, const int x, const int y);

};

class Lorenz84 : public Attractor
{
private:
	float a;
	float b;
	float c;
	float d;
	float e;

public:
	Lorenz84(int pointAmount, float a, float b, float c, float d, float e);
	~Lorenz84();

	void generateAttractor();
	void putPixel(unsigned int* imageBuffer, const int x, const int y);

};


#endif