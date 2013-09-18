/**
 * File constains declaration of WindowManager class, one of Engine managers, responsible for creating Window
 * and initializing OpenGL and SDL options.
 * @file    WindowManager.h
 * @author  Szymon Jab³oñski
 * @date    2010-10-16
 * @version 1.0
 */

#ifndef WINDOW_MANAGER_H
#define WINDOW_MANAGER_H

#include <SDL.h>
#include <SDL_opengl.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include <string>

#include "Extensions.h"

/**
 * WindowManager class represents part of game Engine system. It is responsible for creating Window and initalizing
 * all OpenGL and SDL options, like pixel format, resolution etc. It use Configuration object which store all necessary data.
 * @remarks 
 */
class WindowManager
{
private:
	SDL_Surface* windowScreen;
	int resolutionHeight;
	int resolutionWidth;
	int colorDepth;
	std::string windowCaption;
	bool fullScreenEnabled;

	void initializeSDL();
	void initializeOpenGL();
	void resizeOpenGL(int windowWidth, int windowHeight);

public:
	WindowManager();
	~WindowManager();
};
#endif
