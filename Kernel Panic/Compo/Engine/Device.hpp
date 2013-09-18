/**
 * File contains abstract Device class used to handle user input.
 * @file    Device.hpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2010-11-09
 * @version 1.0
 */

#ifndef DEVICE_HPP
#define DEVICE_HPP

namespace Engine
{

/**
 * Abstract class represents all input devices objects like mouse or keyboard.
 * @remarks
 */
class Device
{
public:
	virtual void updateDevice() = 0;
};

}
#endif
