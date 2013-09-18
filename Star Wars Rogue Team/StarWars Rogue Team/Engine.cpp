/**
 * File contains definition/implementation of Engine class.
 * @file    Engine.cpp
 * @author  Szymon "Veldrin" Jab³oñski & Adam Sznajder
 * @date    2010-10-16
 * @version 1.0
 */

#include "Engine.hpp"

namespace engine
{

/**
 * Class default constructor.
 */
Engine::Engine(GameState* actualState)
{
	engineWindow = new WindowManager();
	engineScene = new SceneManager();
	engineInput = new InputManager(engineScene,actualState);
	engineRenderer = new Renderer(engineScene);
	engineTimer = new Timer();
	handler = new CollisionHandler(engineScene);
	detector = new CollisionDetector(handler,engineScene);
}

/**
 * Class's default destructor, free allocated memory.
 */
Engine::~Engine()
{
	delete engineScene;
	delete engineInput;
	delete engineRenderer;
	delete engineWindow;
	delete engineTimer;
	delete handler;
	delete detector;
}

/**
 * Accessor to engine renderer object.
 * @return	pointer to renderer object.
 */
Renderer* Engine::getEngineRenderer() const
{
	return engineRenderer;
}

/**
 * Accessor to engine timer object.
 * @return	pointer to timer object.
 */
Timer* Engine::getEngineTimer() const
{
	return engineTimer;
}

/**
 * Accessor to engine window manager object.
 * @return	pointer to window manager object.
 */
WindowManager* Engine::getEngineWindow() const
{
	return engineWindow;
}

/**
 * Accessor to engine scene manager object.
 * @return	pointer to scene manager object.
 */
SceneManager* Engine::getEngineScene() const
{
	return engineScene;
}

/**
 * Accessor to engine input manager object.
 * @return	pointer to input manager object.
 */
InputManager* Engine::getEngineInput() const
{
	return engineInput;
};

/**
 * Accessor to engine collision detector object.
 * @return	pointer to collision detector object.
 */
CollisionDetector* Engine::getDetector() const
{
	return detector;
}

/**
 * Accessor to engine collision handler object.
 * @return	pointer to collision handler object.
 */
CollisionHandler* Engine::getHandler() const
{
	return handler;
}

}