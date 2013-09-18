/**
 * File contains definition of GameState module classes.
 * @file    GameState.cpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2010-12-01
 * @version 1.0
 */

#include "Game.hpp"

namespace Game
{

/**
 * Method is used to perform action of actual state.
 */
void IdleState::performAction()
{
	// nothing to do, Idle state
}

/**
 * Method is used to perform action of actual state.
 */
void PlayState::performAction()
{
	game->getGameEngine()->getEngineTimer()->updateTimerData();

	if(game->getGameEngine()->getEngineInput()->updateInput())
		game->setGameDone(true);

	game->getGameEngine()->getEngineScene()->updateScene(game->getGameEngine()->getEngineTimer()->getElapsedTime());
	game->getGameEngine()->getEngineRenderer()->renderScene();

	game->getGameEngine()->getEngineTimer()->updateFramesData();

	if(game->getGameEngine()->getEngineTimer()->isSecondElapsed())
	{
		game->getGameEngine()->getEngineTimer()->updateFpsData();
		game->getGameEngine()->getEngineTimer()->resetFrameData();
	}
}

}
