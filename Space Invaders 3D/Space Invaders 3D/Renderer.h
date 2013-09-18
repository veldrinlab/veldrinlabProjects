/**
 * File contains Engine Renderer class definition.
 * @file    Renderer.h
 * @author  Szymon Jab³oñski
 * @date    2010-10-16
 * @version 1.0
 */

#ifndef RENDERER_H
#define RENDERER_H

#include <SDL.h>
#include <SDL_opengl.h> 
#include <GL/gl.h>
#include <GL/glu.h>

#include "SceneManager.h"

/**
 * Renderer class represents main game Engine sub-system which is used to render 3D scene in SDL window.
 * @remarks maybe change class name. It's pattern name for such object but we have so many "Managers" of engine
 *			strcutre and only one "Renderer"
 */
class Renderer
{
private:
	SceneManager* gameScene;

public:
	Renderer(SceneManager* gameScene);
	~Renderer();

	void renderScene();

};
#endif
