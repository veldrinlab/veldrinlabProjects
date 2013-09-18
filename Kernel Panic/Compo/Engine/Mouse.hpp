/**
 * File contains Mouse class that represnets one of the input devices.
 * @file    Mouse.hpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2010-11-09
 * @version 1.0
 */

#ifndef MOUSE_H
#define MOUSE_H

#include <SDL/SDL.h>
#include <boost/signal.hpp>

#include "Device.hpp"

namespace Engine
{

/**
 * Mouse class is one of input device controlled by InputManager. It is used to update mouse state
 * and communicate with Scene objects by boost signal strucutre.
 * @remarks add mouse state memebr.
 */
class Mouse : public Device
{
public:
	boost::signal<void ()> pressSignal;
	boost::signal<void ()> moveSignal;

	/**
	 * Method used to update device state.
	 */
	void updateDevice()
	{
		moveSignal();
	}

};

}
#endif 
