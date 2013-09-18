/**
 * File contains Keyboard class that represents one of the input devices.
 * @file    Keyboard.hpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2010-11-09
 * @version 1.0
 */

#ifndef KEYBOARD_HPP
#define KEYBOARD_HPP

#include <SDL/SDL.h>
#include <boost/signal.hpp>

#include "Device.hpp"

namespace Engine
{

/**
 * Keyboard class is one of input device controlled by InputManager. It is used to update keyboard state
 * and communicate with Scene objects by boost signal strucutre.
 * @remarks
 */
class Keyboard : public Device
{
public:
	boost::signal<void ()> exitKeySignal;

	/**
	 * Method used to update device state.
	 */
	void updateDevice()
	{
		Uint8 *keystates = SDL_GetKeyState( NULL );

		if(keystates[SDLK_ESCAPE])
			exitKeySignal();
	}
};

}
#endif
