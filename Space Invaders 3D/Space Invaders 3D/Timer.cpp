/**
 * File contains definition of Timer class.
 * @file    Timer.cpp
 * @author  Szymon Jab³oñski
 * @date    2010-10-17
 * @version 1.0
 */

#include "Timer.h"


/**
 * Default constructor, set initialize values.
 */
Timer::Timer()
{
	actualTime = 0.0f;
	previousTime = (float)SDL_GetTicks()/1000.0f;
	elapsedTime = 0.0f;
	framesTimeAccumulator = 0.0f;
	framesCounter = 0;
	framesPerSecond = 0;

}

/**
 * Destructor, do nothing.
 */
Timer::~Timer()
{

}

/**
 * Method used to update actual and previous time and count elapsed time. Use SDL_GetTicks to get actual time
 * from operation system.
 */
void Timer::updateTimerData()
{
	actualTime = (float)SDL_GetTicks()/1000.0f;
	elapsedTime = actualTime - previousTime;
	previousTime = actualTime;
}

/**
 * Method used to update frame counter per second and time accumulator.
 */
void Timer::updateFramesData()
{
	framesCounter++;
	framesTimeAccumulator += elapsedTime;
}

/**
 * Method used to if second has elapsed.   
 * @return  return true if second has elapsed.
 */
bool Timer::isSecondElapsed()
{
	return (framesTimeAccumulator >= 1.0f);
}

/**
 * Method used to update frame per second value which can be calculated as frameCounter divided by frames 
 * accumulator.
 */
void Timer::updateFpsData()
{
	framesPerSecond = framesCounter / framesTimeAccumulator;
}

/**
 * Method used to reset frames counter and accumulator for next use(next second calculation).
 */
void Timer::resetFrameData()
{
	framesCounter = 0;
	framesTimeAccumulator = 0.0f;
}

/**
 * Accessor to elapsedTime.
 * @return elapsed time in second between frames.
 */
float Timer::getElapsedTime() const
{
	return elapsedTime;
}

/**
 * Accessor to frame per second value.
 * @return frames per second.
 */
float Timer::getFramesPerSecond() const
{
	return framesPerSecond;
}
