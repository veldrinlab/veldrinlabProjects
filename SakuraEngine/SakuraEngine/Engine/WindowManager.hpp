/**
 * File constains declaration of WindowManager class, one of Engine managers, responsible for creating Window
 * and initializing OpenGL and SDL options.
 * @file    WindowManager.hpp
 * @author  Szymon Jab³oñski
 * @date    2010-10-16
 * @version 1.0
 */

#ifndef WINDOW_MANAGER_HPP
#define WINDOW_MANAGER_HPP

#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <string>

#include "Extensions.hpp"
#include "Configuration.hpp"

namespace Engine
{

/**
 * WindowManager class represents a part of the game Engine system. It is responsible for creating Window and initalizing 
 * all OpenGL and SDL options, like pixel format, resolution etc. It uses Configuration object which stores all necessary
 * data.
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

public:
	WindowManager();
	~WindowManager();

	void resizeOpenGL(int windowWidth,int windowHeight);
	void setWindowCaption(const std::string);
};

}
#endif
