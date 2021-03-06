/**
 * File contains definition of Attractor classes module.
 * @file    Attractor.cpp
 * @author  Szymon "Veldrin" Jabłoński
 * @date    2010-09-27
 * @version 1.0
 */

#include "Attractor.h"

PickOver::PickOver(int pointAmount, float a, float b, float c, float d, float e)
{
	this->originPosition = Vector3D();
	this->destinationPosition = Vector3D();
	this->pointAmount = pointAmount;
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;
	this->e = e;

	imageBuffer = (unsigned int*)malloc(2048*1536*4);
	memset(imageBuffer,0,2048*1536*4);

}

PickOver::~PickOver()
{
	delete imageBuffer;
}

void PickOver::generateAttractor()
{
	for (int i = pointAmount; i--;)
	{
		putPixel(imageBuffer, 1390 + (int)(originPosition.x*1650), 1190 + (int)(originPosition.y*650));

		destinationPosition.x = sin(a*originPosition.y) - originPosition.z*cos(b*originPosition.x);
		destinationPosition.y = originPosition.z*sin(c*originPosition.x) - cos(d*originPosition.y);
		destinationPosition.z = sin(e*originPosition.x);

		originPosition.x = destinationPosition.x;
		originPosition.y = destinationPosition.y;
		originPosition.z = destinationPosition.z;
	}
}

void PickOver::putPixel(unsigned int* imageBuffer, const int x, const int y)
{	
	const int ra = 5*150;
	const int ga = 7*150;
	const int ba = 10*150;

	const int pp = x+(y<<11);

	if (pp >= 2048*1536)
		return;
	
	unsigned char* p = (unsigned char*)&imageBuffer[pp];

	int rr = (ra + (p[2]<<8)) >> 8;
	int gg = (ga + (p[1]<<8)) >> 8;
	int bb = (ba + (p[0]<<8)) >> 8;

	p[2] = (rr > 255) ? 255 : rr;
	p[1] = (gg > 255) ? 255 : gg;
	p[0] = (bb > 255) ? 255 : bb;

}

PickOverModified::PickOverModified(int pointAmount, float a, float b, float c, float d, float e)
{
	this->originPosition = Vector3D();
	this->destinationPosition = Vector3D();
	this->pointAmount = pointAmount;
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;
	this->e = e;

	imageBuffer = (unsigned int*)malloc(2048*1536*4);
	memset(imageBuffer,0,2048*1536*4);

}

PickOverModified::~PickOverModified()
{
	delete imageBuffer;
}

void PickOverModified::generateAttractor()
{
	float x2, y2,z2;

	for (int i = pointAmount; i--;)
	{
		static float x=0.0f;
		static float y=0.0f;
		static float z=0.0f;

		putPixel(imageBuffer, 490 + (int)(x*950), 1190 + (int)(y*650));

		x2 = MathLibrary::sin(a*y) - z*MathLibrary::cos(b*x);
		y2 = z*MathLibrary::sin(c*x) - MathLibrary::cos(d*y);
		z2 = MathLibrary::sin(e*x);

		x = x2;
		y = y2;
		z = z2;
	}

}

void PickOverModified::putPixel(unsigned int* imageBuffer, const int x, const int y)
{
	const int ra = 7*150;
	const int ga = 5*150;
	const int ba = 7*150;

	const int pp = x+(y<<11);

	if (pp >= 2048*1536)
		return;
	
	unsigned char* p = (unsigned char*)&imageBuffer[pp];

	int rr = (ra + (p[2]<<8)) >> 8;
	int gg = (ga + (p[1]<<8)) >> 8;
	int bb = (ba + (p[0]<<8)) >> 8;

	p[2] = (rr > 255) ? 255 : rr;
	p[1] = (gg > 255) ? 255 : gg;
	p[0] = (bb > 255) ? 255 : bb;

}


PolyNomialTypeA::PolyNomialTypeA(int pointAmount, float a, float b, float c)
{
	this->originPosition = Vector3D();
	this->destinationPosition = Vector3D();
	this->pointAmount = pointAmount;
	this->a = a;
	this->b = b;
	this->c = c;

	imageBuffer = (unsigned int*)malloc(2048*1536*4);
	memset(imageBuffer,0,2048*1536*4);

}

PolyNomialTypeA::~PolyNomialTypeA()
{
	delete imageBuffer;
}

void PolyNomialTypeA::generateAttractor()
{
	for (int i = pointAmount; i--;)
	{
		putPixel(imageBuffer, 500 + (int)(originPosition.x*500), 600 + (int)(originPosition.y*512));

		destinationPosition.x = a + originPosition.y - (originPosition.z * originPosition.y);
		destinationPosition.y = b + originPosition.z - (originPosition.x * originPosition.z);
		destinationPosition.z = c + originPosition.x - (originPosition.y * originPosition.x);

		originPosition.x = destinationPosition.x;
		originPosition.y = destinationPosition.y;
		originPosition.z = destinationPosition.z;
	}

}

void PolyNomialTypeA::putPixel(unsigned int* imageBuffer, const int x, const int y)
{
	const int ra = 5*150;
	const int ga = 10*150;
	const int ba = 7*150;

	const int pp = x+(y<<11);

	if (pp >= 2048*1536)
		return;
	
	unsigned char* p = (unsigned char*)&imageBuffer[pp];

	int rr = (ra + (p[2]<<8)) >> 8;
	int gg = (ga + (p[1]<<8)) >> 8;
	int bb = (ba + (p[0]<<8)) >> 8;

	p[2] = (rr > 255) ? 255 : rr;
	p[1] = (gg > 255) ? 255 : gg;
	p[0] = (bb > 255) ? 255 : bb;

}

Trigonometric::Trigonometric(int pointAmount, float a, float b, float c, float d, float e, float f)
{
	this->originPosition = Vector3D();
	this->destinationPosition = Vector3D();
	this->pointAmount = pointAmount;
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;
	this->e = e;
	this->f = f;

	imageBuffer = (unsigned int*)malloc(2048*1536*4);
	memset(imageBuffer,0,2048*1536*4);

}

Trigonometric::~Trigonometric()
{
	delete imageBuffer;
}

void Trigonometric::generateAttractor()
{
	for (int i = pointAmount; i--;)
	{
		putPixel(imageBuffer, 868 + (int)(originPosition.x*500), 924 + (int)(originPosition.y*200));
		
		destinationPosition.x = sin(a*originPosition.y) + b* cos(a*originPosition.z);
		destinationPosition.y = sin(c*originPosition.z) + d* cos(c*originPosition.x);
		destinationPosition.z = sin(e*originPosition.x) + f* cos(e*originPosition.y);

		originPosition.x = destinationPosition.x;
		originPosition.y = destinationPosition.y;
		originPosition.z = destinationPosition.z;
	}

}

void Trigonometric::putPixel(unsigned int* imageBuffer, const int x, const int y)
{
	const int ra = 10*150;
	const int ga = 4*150;
	const int ba = 2*150;

	const int pp = x+(y<<11);

	if (pp >= 2048*1536 || pp < 0)
		return;
	
	unsigned char* p = (unsigned char*)&imageBuffer[pp];

	int rr = (ra + (p[2]<<8)) >> 8;
	int gg = (ga + (p[1]<<8)) >> 8;
	int bb = (ba + (p[0]<<8)) >> 8;

	p[2] = (rr > 255) ? 255 : rr;
	p[1] = (gg > 255) ? 255 : gg;
	p[0] = (bb > 255) ? 255 : bb;


}

Trigonometric2::Trigonometric2(int pointAmount, float a, float b, float c, float d, float e, float f)
{
	this->originPosition = Vector3D();
	this->destinationPosition = Vector3D();
	this->pointAmount = pointAmount;
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;
	this->e = e;
	this->f = f;

	imageBuffer = (unsigned int*)malloc(2048*1536*4);
	memset(imageBuffer,0,2048*1536*4);

}

Trigonometric2::~Trigonometric2()
{
	delete imageBuffer;
}

void Trigonometric2::generateAttractor()
{
	for (int i = pointAmount; i--;)
	{
		putPixel(imageBuffer, 1200 + (int)(originPosition.x*500), 924 + (int)(originPosition.y*200));
		
		destinationPosition.x = sin(a*originPosition.y) - b* cos(a*originPosition.z);
		destinationPosition.y = sin(c*originPosition.z) - d* cos(c*originPosition.x);
		destinationPosition.z = sin(e*originPosition.x) - f* cos(e*originPosition.y);

		originPosition.x = destinationPosition.x;
		originPosition.y = destinationPosition.y;
		originPosition.z = destinationPosition.z;
	}

}

void Trigonometric2::putPixel(unsigned int* imageBuffer, const int x, const int y)
{
	const int ra = 5*150;
	const int ga = 7*150;
	const int ba = 5*150;

	const int pp = x+(y<<11);

	if (pp >= 2048*1536 || pp < 0)
		return;
	
	unsigned char* p = (unsigned char*)&imageBuffer[pp];

	int rr = (ra + (p[2]<<8)) >> 8;
	int gg = (ga + (p[1]<<8)) >> 8;
	int bb = (ba + (p[0]<<8)) >> 8;

	p[2] = (rr > 255) ? 255 : rr;
	p[1] = (gg > 255) ? 255 : gg;
	p[0] = (bb > 255) ? 255 : bb;


}


Trigonometric3::Trigonometric3(int pointAmount, float a, float b, float c, float d, float e, float f)
{
	this->originPosition = Vector3D();
	this->destinationPosition = Vector3D();
	this->pointAmount = pointAmount;
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;
	this->e = e;
	this->f = f;

	imageBuffer = (unsigned int*)malloc(2048*1536*4);
	memset(imageBuffer,0,2048*1536*4);

}

Trigonometric3::~Trigonometric3()
{
	delete imageBuffer;
}

void Trigonometric3::generateAttractor()
{
	for (int i = pointAmount; i--;)
	{
		putPixel(imageBuffer, 1030 + (int)(originPosition.x*500), 724 + (int)(originPosition.y*200));

		destinationPosition.x = d * sin(a* originPosition.x) - sin(b* originPosition.y);
		destinationPosition.y = c * cos(a * originPosition.x) + cos(b * originPosition.y);
		destinationPosition.z = sin(e * originPosition.x);

		originPosition.x = destinationPosition.x;
		originPosition.y = destinationPosition.y;
		originPosition.z = destinationPosition.z;
	}

}

void Trigonometric3::putPixel(unsigned int* imageBuffer, const int x, const int y)
{
	const int ra = 5*150;
	const int ga = 7*150;
	const int ba = 10*150;

	const int pp = x+(y<<11);

	if (pp >= 2048*1536 || pp < 0)
		return;
	
	unsigned char* p = (unsigned char*)&imageBuffer[pp];

	int rr = (ra + (p[2]<<8)) >> 8;
	int gg = (ga + (p[1]<<8)) >> 8;
	int bb = (ba + (p[0]<<8)) >> 8;

	p[2] = (rr > 255) ? 255 : rr;
	p[1] = (gg > 255) ? 255 : gg;
	p[0] = (bb > 255) ? 255 : bb;


}

Clifford::Clifford(int pointAmount, float a, float b, float c, float d, float e)
{
	this->originPosition = Vector3D();
	this->destinationPosition = Vector3D();
	this->pointAmount = pointAmount;
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;
	this->e = e;

	imageBuffer = (unsigned int*)malloc(2048*1536*4);
	memset(imageBuffer,0,2048*1536*4);

}

Clifford::~Clifford()
{
	delete imageBuffer;
}

void Clifford::generateAttractor()
{
	for (int i = pointAmount; i--;)
	{
		putPixel(imageBuffer, 980 + (int)(originPosition.x*400), 724 + (int)(originPosition.y*200));

		destinationPosition.x = sin( a * originPosition.y) + b * cos( a * originPosition.x);
		destinationPosition.y = sin( c * originPosition.x) + d * cos( c * originPosition.y);
		destinationPosition.z = sin( e * originPosition.y);

		originPosition.x = destinationPosition.x;
		originPosition.y = destinationPosition.y;
		originPosition.z = destinationPosition.z;
	}
}

void Clifford::putPixel(unsigned int* imageBuffer, const int x, const int y)
{
	const int ra = 8*150;
	const int ga = 5*150;
	const int ba = 7*150;

	const int pp = x+(y<<11);

	if (pp >= 2048*1536 || pp < 0)
		return;
	
	unsigned char* p = (unsigned char*)&imageBuffer[pp];

	int rr = (ra + (p[2]<<8)) >> 8;
	int gg = (ga + (p[1]<<8)) >> 8;
	int bb = (ba + (p[0]<<8)) >> 8;

	p[2] = (rr > 255) ? 255 : rr;
	p[1] = (gg > 255) ? 255 : gg;
	p[0] = (bb > 255) ? 255 : bb;

}

Lorenz::Lorenz(int pointAmount, float a, float b, float c, float d)
{
	this->originPosition = Vector3D(0.1f,0.1f,0.1f);
	this->destinationPosition = Vector3D();
	this->pointAmount = pointAmount;
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;

	imageBuffer = (unsigned int*)malloc(2048*1536*4);
	memset(imageBuffer,0,2048*1536*4);

}

Lorenz::~Lorenz()
{
	delete imageBuffer;
}


void Lorenz::generateAttractor()
{
	for (int i = pointAmount; i--;)
	{
		putPixel(imageBuffer, 980 + (int)(originPosition.x*800), 724 + (int)(originPosition.y*200));

		destinationPosition.x = originPosition.x+a*d*(originPosition.y-originPosition.x); 
		destinationPosition.y = originPosition.y+d*(b*originPosition.x-originPosition.y-originPosition.z*originPosition.x);
		destinationPosition.z = originPosition.z+d*(originPosition.x*originPosition.y-c*originPosition.z);

		originPosition.x = destinationPosition.x;
		originPosition.y = destinationPosition.y;
		originPosition.z = destinationPosition.z;

	}
}

void Lorenz::putPixel(unsigned int* imageBuffer, const int x, const int y)
{
	const int ra = 5*150;
	const int ga = 7*150;
	const int ba = 10*150;

	const int pp = x+(y<<11);

	if (pp >= 2048*1536 || pp < 0)
		return;
	
	unsigned char* p = (unsigned char*)&imageBuffer[pp];

	int rr = (ra + (p[2]<<8)) >> 8;
	int gg = (ga + (p[1]<<8)) >> 8;
	int bb = (ba + (p[0]<<8)) >> 8;

	p[2] = (rr > 255) ? 255 : rr;
	p[1] = (gg > 255) ? 255 : gg;
	p[0] = (bb > 255) ? 255 : bb;

}


Lorenz84::Lorenz84(int pointAmount, float a, float b, float c, float d, float e)
{
	this->originPosition = Vector3D();
	this->destinationPosition = Vector3D();
	this->pointAmount = pointAmount;
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;
	this->e = e;

	imageBuffer = (unsigned int*)malloc(2048*1536*4);
	memset(imageBuffer,0,2048*1536*4);

}


Lorenz84::~Lorenz84()
{
	delete imageBuffer;
}


void Lorenz84::generateAttractor()
{	
	for (int i = pointAmount; i--;)
	{
		putPixel(imageBuffer, 980 + (int)(originPosition.x*400), 724 + (int)(originPosition.y*200));

		destinationPosition.x = originPosition.x + d*(-a*originPosition.x - originPosition.y*originPosition.y - originPosition.z*originPosition.z + a*c);
		destinationPosition.y = originPosition.y + d*(-originPosition.y+originPosition.x*originPosition.y-b*originPosition.x*originPosition.z+e);
		destinationPosition.z = originPosition.z + d *(-originPosition.z+b*originPosition.x*originPosition.y+originPosition.x*originPosition.z);

		originPosition.x = destinationPosition.x;
		originPosition.y = destinationPosition.y;
		originPosition.z = destinationPosition.z;

	}

}

void Lorenz84::putPixel(unsigned int* imageBuffer, const int x, const int y)
{
	const int ra = 5*150;
	const int ga = 7*150;
	const int ba = 10*150;

	const int pp = x+(y<<11);

	if (pp >= 2048*1536 || pp < 0)
		return;
	
	unsigned char* p = (unsigned char*)&imageBuffer[pp];

	int rr = (ra + (p[2]<<8)) >> 8;
	int gg = (ga + (p[1]<<8)) >> 8;
	int bb = (ba + (p[0]<<8)) >> 8;

	p[2] = (rr > 255) ? 255 : rr;
	p[1] = (gg > 255) ? 255 : gg;
	p[0] = (bb > 255) ? 255 : bb;

}
