/**
 * File contains Keyboard class that represnets one of the input devices.
 * @file    Kyboard.h
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2010-11-09
 * @version 1.0
 */

#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <SDL.h>
#include <boost/signal.hpp>

#include "Device.h"
#include "Vector3D.h"

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
	boost::signal<void ()> pauseKeySignal;
	boost::signal<void ()> resumeKeySignal;
	boost::signal<void ()> spaceKeySignal;
	boost::signal<void ()> exitKeySignal;

	boost::signal<void ()> lightsUpSignal;
	boost::signal<void ()> lightsDownSignal;

	/**
	 * Method used to update device state.
	 */
	void updateDevice()
	{
		Uint8 *keystates = SDL_GetKeyState( NULL );

		// moze pokusic sie o optymalizacje wizytator
		if (keystates[ SDLK_w ])
			wKeySignal();
		if (keystates[ SDLK_s ])
			sKeySignal();
		if (keystates[ SDLK_d])
			dKeySignal();
		if (keystates[ SDLK_a ])
			aKeySignal();
		if (keystates[ SDLK_q ])
			pauseKeySignal();
		if (keystates[ SDLK_e ])
			resumeKeySignal();
		if (keystates[ SDLK_z ])
			lightsUpSignal();
		if (keystates[ SDLK_x ])
			lightsDownSignal();
		if(keystates[ SDLK_SPACE])
			spaceKeySignal();
		if(keystates[SDLK_ESCAPE])
			exitKeySignal();
	}
};
#endif
