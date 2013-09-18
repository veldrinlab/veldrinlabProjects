/**
 * File contains definition of WindowManager class.
 * @file    WindowManager.cpp
 * @author  Szymon Jab³oñski & Adam Sznajder
 * @date    2010-10-16
 * @version 1.0
 */

#include "WindowManager.hpp"
#include "Configuration.hpp"

using namespace game;

namespace engine
{

/**
 * Class constructor, set window properties from Configuration object and init SDL and OpenGL widnow.
 * @param configuration is pointer to Configuration class.
 */
WindowManager::WindowManager()
{
	this->windowCaption ="Star Wars: Rogue Team";

	initializeSDL();

	Configuration* config = Configuration::getInstance();
	_putenv(_strdup("SDL_VIDEO_CENTERED=1")); 
	if (!config->getFullscreen())
		this->windowScreen = SDL_SetVideoMode(config->getWidth(), config->getHeight(), config->getColorDepth(), SDL_OPENGL| SDL_DOUBLEBUF | SDL_HWSURFACE);
	else this->windowScreen = SDL_SetVideoMode(config->getWidth(), config->getHeight(), config->getColorDepth(), SDL_OPENGL | SDL_FULLSCREEN);

	if( !this->windowScreen )
	{
		printf("Video set mode failed: %s\n", SDL_GetError());		
		exit(0);
	}

	SDL_WM_SetCaption(windowCaption.c_str(), NULL);
	SDL_WM_GrabInput(SDL_GRAB_ON);
	SDL_ShowCursor(false);
		resizeOpenGL(config->getWidth(), config->getHeight());
	initializeOpenGL();

}

void WindowManager::changeSurface()
{
	if(windowScreen)
		SDL_FreeSurface(windowScreen);
	Configuration* config = Configuration::getInstance();
	if (!config->getFullscreen())
		this->windowScreen = SDL_SetVideoMode(config->getWidth(), config->getHeight(), config->getColorDepth(), SDL_OPENGL);
	else this->windowScreen = SDL_SetVideoMode(config->getWidth(), config->getHeight(), config->getColorDepth(), SDL_OPENGL | SDL_FULLSCREEN);

	if( !this->windowScreen )
	{
		printf("Video set mode failed: %s\n", SDL_GetError());	
		exit(0);
	}
	SDL_WM_SetCaption(windowCaption.c_str(), NULL);
	SDL_WM_GrabInput(SDL_GRAB_ON);
	SDL_ShowCursor(false);

	resizeOpenGL(config->getWidth(), config->getHeight());
	initializeOpenGL();
}

/**
 * Default destrcutor, free SDL surface.
 */
WindowManager::~WindowManager()
{
	if(windowScreen)
		SDL_FreeSurface(windowScreen);
}

/**
 * Method used to initialize SDL video and timer modes. Also used to set SDL + OpenGL connection attributes
 */
void WindowManager::initializeSDL()
{
	if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER)<0)
	{
		printf("SDL init error ocurred! Engine shut down immediately");
		exit(0);
	}
	
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE,8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE,8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE,8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE,8);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE,32);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1);
}

/**
 * Method used to iniatlize OpenGL state machine.
 */
void WindowManager::initializeOpenGL()
{
	glEnable(GL_TEXTURE_2D);
	glShadeModel(GL_SMOOTH);
	glClearColor(0.0f,0.0f, 0.0f, 0.5f);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CCW);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState (GL_TEXTURE_COORD_ARRAY);

	Extensions::defineAllExtensions();
	Extensions::checkSupportedExtensions();

}

/**
 * Method used to update OpenGL state machine when window resize event occured. Called when SDL
 * initializes SDL surface. Sets 3D scene viewport and perspective. In the game Camera class updates them.
 */
void WindowManager::resizeOpenGL(int windowWidth, int windowHeight)
{
	if(windowHeight == 0)
		windowHeight = 1;

	if(windowWidth == 0)
		windowWidth = 1;
  
	glViewport(0,0,windowWidth,windowHeight);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f,static_cast<GLfloat>(windowWidth)/static_cast<GLfloat>(windowHeight),0.1f,30000.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

/**
 * Method used to set window caption which is used to show game title in window mode and can be used fo
 * debugging.
 */
void WindowManager::setWindowCaption(std::string windowCaption)
{
	this->windowCaption = windowCaption;
	SDL_WM_SetCaption(windowCaption.c_str(), NULL);
}

}