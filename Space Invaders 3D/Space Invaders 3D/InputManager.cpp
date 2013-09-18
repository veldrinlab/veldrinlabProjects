/**
 * File contains definition of InputManager class.
 * @file    InputManager.cpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2010-11-09
 * @version 1.0
 */

#include "InputManager.h"
#include "Game.h"

/**
 * Class constrcutor, create instances of devices objects and connect signals with slots.
 * @param	engineScene is pointer for SceneManager which is neccesary to connect input signals with slots.
 */
InputManager::InputManager(SceneManager* engineScene, GameState* actualState)
{
	this->actualState = actualState;
	this->engineScene = engineScene;

	keyboardDevice = new Keyboard();
	
	keyboardDevice->wKeySignal.connect(boost::bind(&SpaceShip::wKeyPressed,engineScene->getPlayerShip()));
	keyboardDevice->sKeySignal.connect(boost::bind(&SpaceShip::sKeyPressed,engineScene->getPlayerShip()));
	keyboardDevice->aKeySignal.connect(boost::bind(&SpaceShip::aKeyPressed,engineScene->getPlayerShip()));
	keyboardDevice->dKeySignal.connect(boost::bind(&SpaceShip::dKeyPressed,engineScene->getPlayerShip()));
	keyboardDevice->spaceKeySignal.connect(boost::bind(&SpaceShip::spaceKeyPressed,engineScene->getPlayerShip()));

	keyboardDevice->exitKeySignal.connect(boost::bind(&InputManager::exitKeyPressed,this));
	keyboardDevice->pauseKeySignal.connect(boost::bind(&InputManager::pauseKeyPressed,this));
	keyboardDevice->lightsUpSignal.connect(boost::bind(&Lighting::lightsUp, engineScene->getLightings()));
	keyboardDevice->lightsDownSignal.connect(boost::bind(&Lighting::lightsDown, engineScene->getLightings()));
}

/**
 * Default destrcutor. Free allocated memory for input devices.
 */
InputManager::~InputManager()
{
	delete keyboardDevice;
}

/**
 * Method used to catch escKeyPressed signal. Cause exit from application.
 */
void InputManager::exitKeyPressed()
{
	exit(1);
}

/**
 * Method used to catch pauseKeyPressed signal. Change game state to PauseState.
 */
void InputManager::pauseKeyPressed()
{
	keyboardDevice->wKeySignal.disconnect_all_slots();
	keyboardDevice->sKeySignal.disconnect_all_slots();
	keyboardDevice->aKeySignal.disconnect_all_slots();
	keyboardDevice->dKeySignal.disconnect_all_slots();
	keyboardDevice->spaceKeySignal.disconnect_all_slots();
	
	Game* game = this->actualState->game;
	game->setGameState(new PauseState(game));
	actualState = game->getActualState();

	keyboardDevice->resumeKeySignal.connect(boost::bind(&InputManager::resumeKeyPressed,this));
}

/**
 * Method used to catch resumeKeyPressed signal. Change game state from PauseState to PlayState.
 */
void InputManager::resumeKeyPressed()
{
	keyboardDevice->wKeySignal.connect(boost::bind(&SpaceShip::wKeyPressed,engineScene->getPlayerShip()));
	keyboardDevice->sKeySignal.connect(boost::bind(&SpaceShip::sKeyPressed,engineScene->getPlayerShip()));
	keyboardDevice->aKeySignal.connect(boost::bind(&SpaceShip::aKeyPressed,engineScene->getPlayerShip()));
	keyboardDevice->dKeySignal.connect(boost::bind(&SpaceShip::dKeyPressed,engineScene->getPlayerShip()));
	keyboardDevice->spaceKeySignal.connect(boost::bind(&SpaceShip::spaceKeyPressed,engineScene->getPlayerShip()));
	
	Game* game = this->actualState->game;
	game->setGameState(new PlayState(game));
	actualState = game->getActualState();
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
		}
	}
	
	keyboardDevice->updateDevice();

	return done;
}
