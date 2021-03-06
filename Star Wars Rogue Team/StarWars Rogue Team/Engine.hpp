/**
 * File contains declaration of main game engine structure object, Engine class.
 * @file    Engine.hpp
 * @author  Szymon "Veldrin" Jab�o�ski & Adam Sznajder
 * @date    2010-10-16
 * @version 1.0
 */

#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "WindowManager.hpp"
#include "SceneManager.hpp"
#include "InputManager.hpp"
#include "Renderer.hpp"
#include "ResourceManager/ResourceManager.hpp"
#include "Timer.hpp"
#include "GameState.hpp"
#include "CollisionDetector.hpp"

using namespace game;

namespace engine
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

	CollisionDetector* detector;
	CollisionHandler* handler;

public:
	Engine(GameState* actualState);
	~Engine();

	SceneManager* getEngineScene() const;
	InputManager* getEngineInput() const;
	Renderer* getEngineRenderer() const;
	Timer* getEngineTimer() const;
	WindowManager* getEngineWindow() const;
	CollisionDetector* getDetector() const;
	CollisionHandler* getHandler() const;
};

}
#endif

