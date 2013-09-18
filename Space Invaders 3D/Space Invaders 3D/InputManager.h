/**
 * File contains declaration of InputManager class.
 * @file    InputManager.h
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2010-11-09
 * @version 1.0
 */

#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include <SDL.h>
#include <boost/signal.hpp>
#include <boost/bind.hpp>

#include "SceneManager.h"
#include "Keyboard.h"
#include "GameState.h"

/**
 * InputManager class is used to catch user input controls from such devices as Mouse, Keybord and GamePad
 * and by using boost::signals connect events with game entities methods to udpate position data etc.
 * @remarks
 */
class InputManager
{
private:
	SDL_Event event;
	Keyboard* keyboardDevice;
	GameState* actualState;
	SceneManager* engineScene;

public:
	InputManager(SceneManager* engineScene, GameState* actualState);
	~InputManager();

	void exitKeyPressed();
	void pauseKeyPressed();
	void resumeKeyPressed();
	bool updateInput();

};
#endif

