/**
 * File contains Engine Renderer class definition.
 * @file    Renderer.hpp
 * @author  Szymon Jab³oñski
 * @date    2010-10-16
 * @version 1.0
 */

#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h> 
#include <GL/gl.h>
#include <GL/glu.h>

#include "SceneManager.hpp"
#include "../Utils/Random.hpp"

namespace Engine
{

/**
 * Renderer class represents main game Engine sub-system which is used to render 3D scene in SDL window.
 * Game World scene is organized in tree structure, so Renderer need only reference to scene tree root, which
 * is Terrain or SkyBox.
 * @remarks maybe change class name. It's pattern name for such object but we have so many "Managers" of engine
 *			strcutre and only one "Renderer"
 */
class Renderer
{
private:
	SceneManager* sceneManager;
	bool motionBlurOn;
	bool nightVisionOn;

	Utils::Random randomGenerator;
	Utils::Color color;

public:
	Renderer(SceneManager* sceneManager);
	~Renderer();

	void renderScene();

};

}
#endif
