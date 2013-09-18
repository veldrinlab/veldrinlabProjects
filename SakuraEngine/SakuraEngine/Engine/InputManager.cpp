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

}

/**
 * Method used to catch resumeKeyPressed signal. Change game state from PauseState to PlayState.
 */
void InputManager::resumeKeyPressed()
{

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
