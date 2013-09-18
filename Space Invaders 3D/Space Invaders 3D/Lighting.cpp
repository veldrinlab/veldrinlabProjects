/**
 * File contains definition of Lighting class.
 * @file    Lighting.cpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2010-11-19
 * @version 1.0
 */

#include "Lighting.h"

using namespace std;

/**
 * Default constructor, set environmentLight data
 */
LightState::LightState()
{
	ambientLight[0] = -0.3f;
	ambientLight[1] = -0.3f;
	ambientLight[2] = -0.3f;

	diffuseLight[0] = 1.0f;
	diffuseLight[1] = 1.0f;
	diffuseLight[2] = 1.0f;

	lightPosition[0] = 0.0f;
	lightPosition[1] = 1.0f;
	lightPosition[2] = 0.0f;
	lightPosition[3] = 0.0f;

	for(int i = 0; i<4; ++i)
	{
		matAmbient[i] = 1.0f;
		matDiff[i] = 1.0f;
	}

}

/**
 * Default constructor, set environment light.
 */
Lighting::Lighting()
{
	environmentLight = new LightState();
}

/**
 * Default destructor, delete allocated memory for object memebrs.
 */
Lighting::~Lighting()
{
	delete environmentLight;
}

/**
 * Method used to initialize and turn on special effect.
 */
void Lighting::initializeEffect()
{
	glLightfv (GL_LIGHT0, GL_DIFFUSE, environmentLight->diffuseLight);
    glLightfv (GL_LIGHT0, GL_AMBIENT, environmentLight->ambientLight);
	glLightfv (GL_LIGHT0, GL_POSITION, environmentLight->lightPosition);

	GLfloat mShininess[] = {10};
    
	GLfloat DiffuseMaterial[] = {0.0, 0.0, 0.0};
    GLfloat AmbientMaterial[] = {1.0, 1.0, 1.0};
    GLfloat SpecularMaterial[] = {1.0, 1.0, 1.0};
    
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, DiffuseMaterial);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, AmbientMaterial);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, SpecularMaterial);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mShininess);

}

/**
 * Method used to increase ambinet light.
 */
void Lighting::lightsUp()
{
	environmentLight->ambientLight[0] += 0.01f;
	environmentLight->ambientLight[1] += 0.01f;
	environmentLight->ambientLight[2] += 0.01f;
	glLightfv(GL_LIGHT0, GL_AMBIENT, environmentLight->ambientLight);
}

/**
 * Method used to decrease ambinet light.
 */
void Lighting::lightsDown()
{
	environmentLight->ambientLight[0] -= 0.01f;
	environmentLight->ambientLight[1] -= 0.01f;
	environmentLight->ambientLight[2] -= 0.01f;
	glLightfv(GL_LIGHT0, GL_AMBIENT, environmentLight->ambientLight);
}


void Lighting::changeSpectrum()
{

	//if(environmentLight->ambientLight[0] <= 1.0f)
	//	environmentLight->ambientLight[0] += 0.01f;
	//else
	//	environmentLight->ambientLight[0] = -0.3f;

	//if(environmentLight->ambientLight[1] <= 1.0f)
	//	environmentLight->ambientLight[1] += 0.05f;
	//else
	//	environmentLight->ambientLight[1] = -0.1f;

	//if(environmentLight->ambientLight[2] <= 1.0f)
	//	environmentLight->ambientLight[2] += 0.10f;
	//else
	//	environmentLight->ambientLight[2] = -0.1f;


	//glLightfv(GL_LIGHT0, GL_AMBIENT, environmentLight->ambientLight);
}