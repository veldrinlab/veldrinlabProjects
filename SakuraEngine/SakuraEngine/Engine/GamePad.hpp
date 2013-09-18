/**
 * File contains definition and declaration of GamePad class which represnets one of the input devices.
 * @file    Mouse.hpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2011-02-20
 * @version 1.0
 */

#ifndef GAMEPAD_HPP
#define GAMEPAD_HPP

#include <SDL/SDL.h>
#include <boost/signal.hpp>

#include "Device.hpp"

namespace Engine
{

/**
 * Class represents one of input devide - analog GamePad which have got many buttons and axes. 
 */
class GamePad : public Device
{
private:
	SDL_Joystick *gamePad;

public:
	/**
	 * Default constructor.
	 */
	GamePad()
	{
		if( SDL_NumJoysticks() < 1 )
		{
			printf("There is no game pad connected with PC!\n");
			exit(0);
		}

		gamePad = SDL_JoystickOpen(0);

		if(!gamePad)
		{
			printf("GamePad open procedure error occurred!\n");
			exit(0);
		}
	}

	/**
	 * Destructor, close joystick.
	 */
	~GamePad()
	{
		SDL_JoystickClose(gamePad);
	}

	/**
	 * Method used to update device state.
	 */
	void updateDevice()
	{
		int x = SDL_JoystickGetAxis(gamePad, 0);
		int y = SDL_JoystickGetAxis(gamePad, 1);

		int x2 = SDL_JoystickGetAxis(gamePad, 4);
		int y2 = SDL_JoystickGetAxis(gamePad, 5);
	}
};

}
#endif
