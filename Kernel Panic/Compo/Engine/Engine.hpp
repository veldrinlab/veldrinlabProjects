/**
 * File contains declaration of main game engine structure object, Engine class.
 * @file    Engine.hpp
 * @author  Szymon "Veldrin" Jab³oñski & Adam Sznajder
 * @date    2010-10-16
 * @version 1.0
 */

#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "WindowManager.hpp"
#include "SceneManager.hpp"
#include "InputManager.hpp"
#include "Renderer.hpp"
#include "Timer.hpp"

namespace Engine
{

/**
 * Engine class represents main object of game engine system. It is initialized by configuration options stored
 * in instance of Configuration class. Engine class stores references to Engine Managers, sub-systems such as
 * WindowManager, Timer, Renderer and ResourceManager. 
 * @remarks
 */
class Engine
{
private:
	WindowManager* engineWindow;
	SceneManager* engineScene;
	InputManager* engineInput;
	Renderer* engineRenderer;
	Timer* engineTimer;

public:
	Engine();
	~Engine();

	SceneManager* getEngineScene() const;
	InputManager* getEngineInput() const;
	Renderer* getEngineRenderer() const;
	Timer* getEngineTimer() const;
	WindowManager* getEngineWindow() const;

};

}
#endif

