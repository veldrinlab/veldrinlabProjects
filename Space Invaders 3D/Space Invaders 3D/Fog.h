/**
 * Fle contains declaration of Fog class - one of Engine Special Effetcs.
 * @file    Fog.h
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2010-11-18
 * @version 1.0
 */

#ifndef FOG_H
#define FOG_H

#include <SDL.h>
#include <SDL_opengl.h> 
#include <GL/gl.h>
#include <GL/glu.h>

/**
 * Fog class represents one of Engine Special effects - fog.
 * @remarks 
 */
class Fog
{
private:
	GLfloat fogDensity;
	GLuint fogMode;
	GLfloat fogColor[4]; //use color class

public:
	Fog(const GLfloat fogDensity,const GLuint fogMode, const GLfloat* fogColor);
	Fog();
	~Fog();
	void initializeEffect();

};
#endif
