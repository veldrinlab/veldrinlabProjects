/**
 * File contains declaration of Engine Timer class used to simulate real-time game loop.
 * @file    Timer.h
 * @author  Szymon Jab³oñski
 * @date    2010-10-17
 * @version 1.0
 */

#ifndef TIMER_H
#define TIMER_H

#include <SDL.h>

/**
 * Timer class represents real time timer. It is used to synchronize game speed
 * for all typ of PC hardware configuration and accure delta time between game frames to
 * simulate physics. Timer has also methods for calculating maximum frames per second( if v-sync is off).
 *
 * @remarks 
 */
class Timer
{
private:
	float actualTime;
	float previousTime;
	float elapsedTime;
	float framesTimeAccumulator;
	int framesCounter;
	float framesPerSecond;

public:
	Timer();
	~Timer();

	void updateTimerData();
	void updateFramesData();
	bool isSecondElapsed();
	void updateFpsData();
	void resetFrameData();

	float getElapsedTime() const;
	float getFramesPerSecond() const;

};
#endif



 