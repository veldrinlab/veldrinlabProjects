/**
 * File contains declaration of InputManager class.
 * @file    InputManager.hpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2010-11-09
 * @version 1.0
 */

#ifndef INPUT_MANAGER_HPP
#define INPUT_MANAGER_HPP

#include <SDL/SDL.h>
#include <boost/signal.hpp>
#include <boost/bind.hpp>

#include "SceneManager.hpp"
#include "Mouse.hpp"
#include "Keyboard.hpp"
#include "GamePad.hpp"

namespace Engine
{

/**
 * InputManager class is used to catch user input controls from such devices as Mouse, Keybord and GamePad
 * and by using boost::signals connect events with game entities methods to udpate position data etc.
 * @remarks
 */
class InputManager
{
private:
	SDL_Event event;
	Mouse* mouseDevice;
	Keyboard* keyboardDevice;
	GamePad* padDevice;
	SceneManager* engineScene;

public:
	InputManager(SceneManager* engineScene);
	~InputManager();

	void exitKeyPressed();
	void pauseKeyPressed();
	void resumeKeyPressed();
	bool updateInput();

};

}
#endif
