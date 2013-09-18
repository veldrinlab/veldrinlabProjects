/**
 * Fle contains declaration of MotionBlur class - one of Engine Special Effetcs.
 * @file    MotionBlur.hpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2010-11-18
 * @version 1.0
 */

#ifndef MOTIONBLUR_HPP
#define MOTIONBLUR_HPP

#include <math.h>
#include "SpecialFX.hpp"

namespace specialFx
{
/**
 * MotionBlur class represents one of Engine Special effects - Motion Blur.
 * @remarks 
 */
class MotionBlur : public SpecialFX
{
private:
	float blurRatio;

public:
	MotionBlur(const float effectRatio);
	MotionBlur();
	~MotionBlur();

	void initializeEffect();
	void updateEffect(const float elapsedTime);
	void renderEffect();
	void setBlurRatio(const float effectRatio);

};
}
#endif
