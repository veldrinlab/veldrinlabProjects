/**
 * File contains abstract Device class used to handle user input.
 * @file    Device.h
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2010-11-09
 * @version 1.0
 */

#ifndef DEVICE_H
#define DEVICE_H

/**
 * Abstract class represents all input devices objects like mouse or keyboard.
 * @remarks
 */
class Device
{
public:
	virtual void updateDevice() = 0;
};
#endif
