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
	boost::signal<void ()> wKeySignal;
	boost::signal<void ()> sKeySignal;
	boost::signal<void ()> aKeySignal;
	boost::signal<void ()> dKeySignal;
	boost::signal<void ()> qKeySignal;
	boost::signal<void ()> eKeySignal;
	boost::signal<void ()> stopXSignal;
	boost::signal<void ()> stopYSignal;
	boost::signal<void ()> stopLeftKeySignal;
	boost::signal<void ()> stopRightKeySignal;
	boost::signal<void ()> pauseKeySignal;
	boost::signal<void ()> resumeKeySignal;
	boost::signal<void ()> exitKeySignal;
	boost::signal<void ()> upKeySignal;
	boost::signal<void ()> downKeySignal;
	boost::signal<void ()> leftKeySignal;
	boost::signal<void ()> rightKeySignal;
	boost::signal<void ()> zKeySignal;
	boost::signal<void ()> xKeySignal;
	boost::signal<void ()> xUpKeySignal;
	boost::signal<void ()> spaceKeySignal;

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
		if (keystates[ SDLK_z ])
			zKeySignal();
		if (keystates[ SDLK_x ])
			xKeySignal();
		else 
			xUpKeySignal();

		if (keystates[ SDLK_UP ])
			upKeySignal();
		
		if (keystates[ SDLK_DOWN ])
			downKeySignal();
		
		if (!keystates[ SDLK_UP ] && !keystates[ SDLK_DOWN ])
			stopYSignal();
	
		if (keystates[ SDLK_LEFT ])
			leftKeySignal();

		if (keystates[ SDLK_RIGHT ])
			rightKeySignal();
		
		if (!keystates[ SDLK_LEFT ] && !keystates[ SDLK_RIGHT ])
			stopXSignal();

		if (keystates[ SDLK_SPACE ])
			spaceKeySignal();
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
