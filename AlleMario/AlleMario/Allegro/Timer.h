/**
 * Timer.h
 *
 * Timer class represents real time timer. It is used to synchronize game speed
 * for all typ of PC hardware configuration and simulate game physics
 * like objects moving etc. Also it is used to display Frame per second.
 *
 *  Created on: 2010-07-09
 *      Author: Szymon Jab³oñski - Veldrin
 */

#ifndef TIMER_H
#define TIMER_H

#include <windows.h>


class Timer
{
private:
	LARGE_INTEGER frequency;
	bool isQpcUsed;
	float time; 
	float newTime;
	float timeDifference;
	float fps;
	float fpsTime;
	unsigned frames;
	

public:
	Timer();
	~Timer();

	float getTicks();
	void updateTimerData();
	void updateFramesData();
	bool isSecondEnded();
	void updateFpsData();
	void resetFpsCounter();


	float getTime();
	void setTime(float time);
	float getNewTime();
	void setNewTime(float newTime);
	float getTimeDifference();
	void setTimeDifference(float timeDifference);
	float getFps();
	void setFps(float fps);
	float getFpsTime();
	void setFpsTime(float fpsTime);
	unsigned getFrames();
	void setFrames(unsigned frames);


};

#endif
