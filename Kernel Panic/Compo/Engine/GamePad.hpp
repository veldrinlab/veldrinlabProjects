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

	bool one;
	bool two;
	bool three;

public:
	boost::signal<void ()> moveLeftSignal;
	boost::signal<void ()> moveRightSignal;
	boost::signal<void ()> moveUpSignal;
	boost::signal<void ()> moveDownSignal;
	boost::signal<void ()> stopXAxisSignal;
	boost::signal<void ()> stopYAxisSignal;	
	boost::signal<void ()> exitSignal;
	boost::signal<void ()> magicSignal;

	boost::signal<void ()> probieren;
	boost::signal<void ()> verhogen;
	boost::signal<void ()> speedUp;
	boost::signal<void ()> setTower;


	/**
	 * Default constructor.
	 */
	GamePad()
	{
		if( SDL_NumJoysticks() < 1 )
		{
			printf("There is no game pad connected with PC!\n");
			//exit(0);
		}

		gamePad = SDL_JoystickOpen(0);

		if(!gamePad)
		{
			printf("GamePad open procedure error occurred!\n");
			//exit(0);
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

		int x2 = SDL_JoystickGetAxis(gamePad, 2);
		int y2 = SDL_JoystickGetAxis(gamePad, 3);		

		if(x < -257)
			moveLeftSignal();
		if(x > 257)
			moveRightSignal();
		if(y < -257)
			moveUpSignal();
		if(y > 257)
			moveDownSignal();
		if(x > -8000 && x < 8000)
			stopXAxisSignal();
		if(y > -8000 && y < 8000)
			stopYAxisSignal();		

		
		if(SDL_JoystickGetButton(gamePad,1))
			probieren();
		
		if(SDL_JoystickGetButton(gamePad,2))
			verhogen();
		
		if(SDL_JoystickGetButton(gamePad,3))
			speedUp();

		if(SDL_JoystickGetButton(gamePad,0))
			setTower();

		if(SDL_JoystickGetButton(gamePad,9))
			exitSignal();

		if(SDL_JoystickGetButton(gamePad,3))
			magicSignal();
	}
};

}
#endif
