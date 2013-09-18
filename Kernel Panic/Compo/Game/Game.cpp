/**
 * File contains definition of Game class.
 * @file    Game.cpp
 * @author  Szymon "Veldrin" Jab³oñki
 * @date    2010-11-09
 * @version 1.0
 */

#include <iostream>
#include "Game.hpp"

namespace Game
{
/**
 * Default object constructor. 
 */

Game::Game()
{
	gameDone = false;
	actualState = new IdleState(this);
	gameEngine = new Engine::Engine();

	//Configuration* conf = Configuration::getInstance();
	//if(conf->getLevel() == INTRO)
	//	actualState = new IntroState(this);
	//else
	//
	actualState = new PlayState(this);
}

/**
 * Game object destructor.
 */
Game::~Game()
{
	delete gameEngine;
	delete actualState;
}

/**
* Game's magic starts! Method that sets up the game and inits game main loop.
*/
void Game::performAction()
{
    while(!gameDone)
		this->actualState->performAction();
}

/**
 * Accessor to engine.
 * @return pointer to engine.
 */
Engine::Engine* Game::getGameEngine() const
{
	return gameEngine;
}

/**
 * Accessor to private memeber.
 * @return poiter to actual State.
 */
GameState* Game::getActualState() const
{
	return actualState;
}

/**
 * Accessor to private memeber.
 * @return boolean value which indicates whether the game is done.
 */
bool Game::isGameDone() const
{
	return gameDone;
}

/**
 * Setter of private member.
 * @param	done is information whether the game has finished.
 */
void Game::setGameDone(const bool done)
{
	this->gameDone = done;
}

/**
 * Setter of private member.
 * @param	gameState is a pointer to new state of the game.
 */
void Game::setGameState(GameState* gameState)
{
	this->actualState = gameState;
}

}