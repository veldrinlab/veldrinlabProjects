/**
 * Timer.cpp
 * File contains definition of Timer class.
 *
 *  Created on: 2010-07-09
 *      Author: Szymon Jab³oñski - Veldrin
 */

#include "Timer.h"


Timer::Timer()
{
	isQpcUsed = (QueryPerformanceFrequency (&frequency) != 0);
	fpsTime= 0.0f;
	frames = 0;
	time = getTicks();
}

Timer::~Timer()
{

}

float Timer::getTicks()
{
   if (!isQpcUsed)
	   return GetTickCount() / 1000.0f;
   else
   {
      LARGE_INTEGER ticks;
      QueryPerformanceCounter (&ticks);
      return (float)(ticks.QuadPart / (double)frequency.QuadPart);
   }
}

void Timer::updateTimerData()
{
	newTime = getTicks();
	timeDifference = newTime - time;
	time = newTime;
}

void Timer::updateFramesData()
{
	++frames;
	fpsTime += timeDifference;

}

bool Timer::isSecondEnded()
{
	return (fpsTime >= 1.0f);
}

void Timer::updateFpsData()
{
	fps = frames / fpsTime;
}

void Timer::resetFpsCounter()
{
	frames = 0;
	fpsTime = 0.0f;
}

float Timer::getTime()
{
	return time;
}

void Timer::setTime(float time)
{
	this->time = time;
}

float Timer::getNewTime()
{
	return newTime;
}

void Timer::setNewTime(float newTime)
{
	this->newTime = newTime;
}

float Timer::getTimeDifference()
{
	return timeDifference;
}

void Timer::setTimeDifference(float timeDifference)
{
	this->timeDifference = timeDifference;
}

float Timer::getFps()
{
	return fps;
}

void Timer::setFps(float fps)
{
	this->fps = fps;
}

float Timer::getFpsTime()
{
	return fpsTime;
}

void Timer::setFpsTime(float fpsTime)
{
	this->fpsTime = fpsTime;
}

unsigned Timer::getFrames()
{
	return frames;
}

void Timer::setFrames(unsigned frames)
{
	this->frames = frames;
}
