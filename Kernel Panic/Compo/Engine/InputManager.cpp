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

	// PolySlasher pozosta³oœci!

	keyboardDevice->exitKeySignal.connect(boost::bind(&InputManager::exitKeyPressed,this));
	keyboardDevice->leftKeySignal.connect(boost::bind(&PlayerWii::moveLeft,engineScene->getPlayerWii()));
	keyboardDevice->rightKeySignal.connect(boost::bind(&PlayerWii::moveRight,engineScene->getPlayerWii()));
	keyboardDevice->upKeySignal.connect(boost::bind(&PlayerWii::moveUp,engineScene->getPlayerWii()));
	keyboardDevice->downKeySignal.connect(boost::bind(&PlayerWii::moveDown,engineScene->getPlayerWii()));
	keyboardDevice->stopXSignal.connect(boost::bind(&PlayerWii::stopXAxisMove,engineScene->getPlayerWii()));
	keyboardDevice->stopYSignal.connect(boost::bind(&PlayerWii::stopYAxisMove,engineScene->getPlayerWii()));
	keyboardDevice->spaceKeySignal.connect(boost::bind(&PlayerWii::leftAttack,engineScene->getPlayerWii()));
	keyboardDevice->xKeySignal.connect(boost::bind(&PlayerWii::stomp,engineScene->getPlayerWii()));
	keyboardDevice->xUpKeySignal.connect(boost::bind(&PlayerWii::stompStop,engineScene->getPlayerWii()));

	padDevice->moveLeftSignal.connect(boost::bind(&PlayerPad::moveLeft,engineScene->getPlayer()));
	padDevice->moveRightSignal.connect(boost::bind(&PlayerPad::moveRight,engineScene->getPlayer()));
	padDevice->moveUpSignal.connect(boost::bind(&PlayerPad::moveUp,engineScene->getPlayer()));
	padDevice->moveDownSignal.connect(boost::bind(&PlayerPad::moveDown,engineScene->getPlayer()));
	padDevice->stopXAxisSignal.connect(boost::bind(&PlayerPad::stopXAxisMove,engineScene->getPlayer()));
	padDevice->stopYAxisSignal.connect(boost::bind(&PlayerPad::stopYAxisMove,engineScene->getPlayer()));

	padDevice->probieren.connect(boost::bind(&PlayerPad::Probieren,engineScene->getPlayer()));
	padDevice->verhogen.connect(boost::bind(&PlayerPad::Verhogen,engineScene->getPlayer()));
	padDevice->speedUp.connect(boost::bind(&PlayerPad::SpeedUp,engineScene->getPlayer()));
	padDevice->setTower.connect(boost::bind(&PlayerPad::SetTower,engineScene->getPlayer()));
	
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
