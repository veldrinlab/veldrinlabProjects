/**
 * File contains Keyboard class that represents one of the input devices.
 * @file    Kyboard.hpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2010-11-09
 * @version 1.0
 */

#ifndef KEYBOARD_HPP
#define KEYBOARD_HPP

#include <SDL.h>
#include <boost/signal.hpp>

#include "Device.hpp"

namespace engine
{

/**
 * Keyboard class is one of input device controlled by InputManager. It is used to update keyboard state
 * and communicate with Scene objects by boost signal strucutre.
 * @remarks
 */
class Keyboard : public Device
{
public:
	boost::signal<void ()> wKeySignal;
	boost::signal<void ()> sKeySignal;
	boost::signal<void ()> aKeySignal;
	boost::signal<void ()> dKeySignal;
	boost::signal<void ()> qKeySignal;
	boost::signal<void ()> eKeySignal;
	boost::signal<void ()> pauseKeySignal;
	boost::signal<void ()> resumeKeySignal;
	boost::signal<void ()> exitKeySignal;

	/**
	 * Method used to update device state.
	 */
	void updateDevice()
	{
		Uint8 *keystates = SDL_GetKeyState( NULL );

		if (keystates[ SDLK_d])
			dKeySignal();
		if (keystates[ SDLK_a ])
			aKeySignal();
		if (keystates[ SDLK_e ])
			eKeySignal();
		if (keystates[ SDLK_q ])
			qKeySignal();
		if(keystates[ SDLK_p])
			pauseKeySignal();
		if(keystates[ SDLK_r])
			resumeKeySignal();
		if(keystates[SDLK_ESCAPE])
			exitKeySignal();
	}
};

}
#endif
