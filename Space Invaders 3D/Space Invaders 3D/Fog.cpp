/**
 * File contains definition of Fog class.
 * @file    Fog.cpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2010-11-19
 * @version 1.0
 */

#include "Fog.h"

/**
 * Constrcutor with initialization values.
 * @param   fogDensity is fog density.
 * @param   fogMode is one of three fog mode.
 * @param   fogColor is fog color.
 */
Fog::Fog(const GLfloat fogDensity, const GLuint fogMode,const GLfloat* fogColor)
{
	this->fogDensity = fogDensity;
	this->fogMode = fogMode;
	this->fogColor[0] = fogColor[0];
	this->fogColor[1] = fogColor[1];
	this->fogColor[2] = fogColor[2];
	this->fogColor[3] = fogColor[3];
}

/**
 * Default constrcutor, set default values.
 */
Fog::Fog()
{
	fogDensity = 0.002f;
	fogMode = GL_EXP2;
	fogColor[0] = 1.0f;
	fogColor[1] = 0.0f;
	fogColor[2] = 0.0f;
	fogColor[3] = 0.4f;
}

/**
 * Destrcutor, nothing to do.
 */
Fog::~Fog()
{

}

/**
 * Method used to initialize and turn on special effect.
 */
void Fog::initializeEffect()
{
	glFogi(GL_FOG_MODE, fogMode);
	glFogfv(GL_FOG_COLOR, fogColor);
	glFogf(GL_FOG_DENSITY, fogDensity);
	glHint(GL_FOG_HINT, GL_DONT_CARE);
	glFogf(GL_FOG_START, 1.0f);
	glFogf(GL_FOG_END, 500.0f);
	glEnable(GL_FOG);
}
