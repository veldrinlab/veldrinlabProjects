/**
 * File contains definition of Game class.
 * @file    Game.cpp
 * @author  Szymon "Veldrin" Jab³oñki
 * @date    2010-11-09
 * @version 1.0
 */

#include "Game.h"

/**
 * Default object constructor. 
 */
Game::Game()
{
	gameDone = false;
	actualState = new IdleState(this);
	gameWindow = new WindowManager();
	gameTimer = new Timer();
	gameScene = new SceneManager(actualState);
	gameRenderer = new Renderer(gameScene);
	gameInput = new InputManager(gameScene,actualState);
	handler = new CollisionHandler(gameScene);
	detector = new CollisionDetector(handler,gameScene);

	actualState = new PlayState(this);

}

/**
 * Game object destructor, free allocated memory.
 */
Game::~Game()
{
	delete gameWindow;
	delete gameTimer;
	delete gameRenderer;
	delete gameInput;
	delete gameScene;
	delete handler;
	delete detector;
}

/**
* Game magic starts! Method that runs game and init game main loop.
*/
void Game::doSomeMagic()
{
    while(!gameDone)
		this->actualState->performAction();
}

/**
 * Accessor to private memeber.
 */
WindowManager* Game::getGameWindow() const
{
	return gameWindow;
}

/**
 * Accessor to private memeber.
 */
InputManager* Game::getGameInput() const
{
	return gameInput;
}

/**
 * Accessor to private memeber.
 */
SceneManager* Game::getGameScene() const
{
	return gameScene;
}

/**
 * Accessor to private memeber.
 */
Timer* Game::getGameTimer() const
{
	return gameTimer;
}

/**
 * Accessor to private memeber.
 */
Renderer* Game::getGameRenderer() const
{
	return gameRenderer;
}

/**
 * Accessor to private memeber.
 */
CollisionDetector* Game::getDetector() const
{
	return detector;
}

/**
 * Accessor to private memeber.
 */
CollisionHandler* Game::getHandler() const
{
	return handler;
}

/**
 * Accessor to private memeber.
 */
GameState* Game::getActualState() const
{
	return actualState;
}

/**
 * Accessor to private memeber.
 */
bool Game::isGameDone() const
{
	return gameDone;
}

/**
 * Setter of private member.
 */
void Game::setGameDone(const bool done)
{
	this->gameDone = done;
}

/**
 * Setter of private member.
 */
void Game::setGameState(GameState* gameState)
{
	this->actualState = gameState;
}
