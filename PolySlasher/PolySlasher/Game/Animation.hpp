/**
 * File contains declaration of Animation structure/class.
 * @file    Animation.hpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2011-02.28
 * @version 1.0
 */

#ifndef ANIMATION_HPP
#define ANIMATION_HPP

/**
 * Class/structure stores data about sprite animation such as frame number, time accumulator, currentFrames etc.
 */
class Animation
{
public:
	int framesAmount;
	float frameTimeAccumulator;
	float frameTime[5];
	int currentFrameX;
	int currentFrameY;

	bool isRooling;

};
#endif
