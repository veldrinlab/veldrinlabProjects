/**
 * File contains definition of InputManager class.
 * @file    InputManager.cpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2010-11-09
 * @version 1.0
 */

#include "InputManager.hpp"

using namespace Game;

namespace Engine
{

/**
 * Class constrcutor, create instances of devices objects and connect signals with slots.
 * @param	engineScene is pointer for SceneManager which is neccesary to connect input signals with slots.
 */
InputManager::InputManager(SceneManager* engineScene)
{
	this->engineScene = engineScene;

	mouseDevice = new Mouse();
	keyboardDevice = new Keyboard();
	padDevice = new GamePad();

	keyboardDevice->exitKeySignal.connect(boost::bind(&InputManager::exitKeyPressed,this));
	padDevice->moveLeftSignal.connect(boost::bind(&Player::moveLeft,engineScene->getPlayer()));
	padDevice->moveRightSignal.connect(boost::bind(&Player::moveRight,engineScene->getPlayer()));
	padDevice->moveUpSignal.connect(boost::bind(&Player::moveUp,engineScene->getPlayer()));
	padDevice->moveDownSignal.connect(boost::bind(&Player::moveDown,engineScene->getPlayer()));
	padDevice->stopXAxisSignal.connect(boost::bind(&Player::stopXAxisMove,engineScene->getPlayer()));
	padDevice->stopYAxisSignal.connect(boost::bind(&Player::stopYAxisMove,engineScene->getPlayer()));
	padDevice->rightAttackSignal.connect(boost::bind(&Player::rightAttack,engineScene->getPlayer()));
	padDevice->magicSignal.connect(boost::bind(&Player::rageStart,engineScene->getPlayer()));
	padDevice->exitSignal.connect(boost::bind(&InputManager::exitKeyPressed,this));

	//keyboardDevice->pauseKeySignal.connect(boost::bind(&InputManager::pauseKeyPressed,this));
	//keyboardDevice->resumeKeySignal.connect(boost::bind(&InputManager::resumeKeyPressed,this));
}

/**
 * Default destrcutor. Free allocated memory for input devices.
 */
InputManager::~InputManager()
{
	delete mouseDevice;
	delete keyboardDevice;
	delete padDevice;
}

/**
 * Method used to catch escKeyPressed signal. Cause exit from application.
 */
void InputManager::exitKeyPressed()
{
	exit(0);
}

/**
 * Method used to catch pauseKeyPressed signal. Change game state to PauseState.
 */
void InputManager::pauseKeyPressed()
{
	//keyboardDevice->wKeySignal.disconnect_all_slots();
	//keyboardDevice->sKeySignal.disconnect_all_slots();
	//keyboardDevice->aKeySignal.disconnect_all_slots();
	//keyboardDevice->dKeySignal.disconnect_all_slots();
	//mouseDevice->moveSignal.disconnect_all_slots();
	//mouseDevice->pressSignal.disconnect_all_slots();
	//
	//Game* game = this->actualState->game;
	//game->setGameState(new PauseState(game));
	//actualState = game->getActualState();

	//keyboardDevice->resumeKeySignal.connect(boost::bind(&InputManager::resumeKeyPressed,this));
}

/**
 * Method used to catch resumeKeyPressed signal. Change game state from PauseState to PlayState.
 */
void InputManager::resumeKeyPressed()
{
	//Xwing* playerShip = engineScene->getPlayerShip();
	//keyboardDevice->wKeySignal.connect(boost::bind(&Xwing::accelerateShip,engineScene->getPlayerShip()));
	//keyboardDevice->sKeySignal.connect(boost::bind(&Xwing::slowDownShip,engineScene->getPlayerShip()));
	//keyboardDevice->aKeySignal.connect(boost::bind(&Xwing::rotateLeft,engineScene->getPlayerShip()));
	//keyboardDevice->dKeySignal.connect(boost::bind(&Xwing::rotateRight,engineScene->getPlayerShip()));
	//mouseDevice->moveSignal.connect(boost::bind(&Xwing::steerShip,engineScene->getPlayerShip()));
	//mouseDevice->pressSignal.connect(boost::bind(&Xwing::shootLasers, engineScene->getPlayerShip()));
	//
	//Game* game = this->actualState->game;
	//game->setGameState(new PlayState(game));
	//actualState = game->getActualState();
}

/**
 * Method used to update user input from keyboard and mouse. Method poll events from SDL quenue.
 * SDL_QUIT events causes end of game.
 * @return true if SDL_QUIT events occurred.
 */
bool InputManager::updateInput()
{
	bool done = false;

	while(SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				done = true;
				break;
			default:
				break;
		}
	}
	
	keyboardDevice->updateDevice();
	mouseDevice->updateDevice();
	padDevice->updateDevice();

	return done;
}

}
