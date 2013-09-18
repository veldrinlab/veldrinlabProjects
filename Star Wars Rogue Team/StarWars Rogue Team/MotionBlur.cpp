/**
 * File contains definition of MotionBlur class.
 * @file    MotionBlur.cpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2010-11-19
 * @version 1.0
 */

#include "MotionBlur.hpp"

namespace specialFx
{

/**
 * Constructor with initialization values.
 * @param   effectRation is value represents blur effect.
 */
MotionBlur::MotionBlur(const float effectRatio)
{
	this->blurRatio = effectRatio;
}

/**
 * Default constructor, set default, best looking values.
 */
MotionBlur::MotionBlur()
{
	blurRatio = 0.9f;
}

/**
 * Destructor, nothing to do.
 */
MotionBlur::~MotionBlur()
{

}

/**
 * Method used to initialize and turn on special effect.
 */
void MotionBlur::initializeEffect()
{
	glAccum(GL_LOAD, 1);
}

/**
 * Method used to update special effect for Renderer.
 * @param	elapsedTime is time which indicates how long the effect is running.
 */
void MotionBlur::updateEffect(const float elapsedTime)
{
	//nothing to do
}

/**
 * Method is used to render Motion Blur effect by using accumulation buffer.
 */
void MotionBlur::renderEffect()
{
	if (blurRatio > 0)
	{
		glAccum(GL_MULT, blurRatio);
		glAccum(GL_ACCUM, 1.0f - blurRatio);
		glAccum(GL_RETURN, 1);
	}
}

/**
 * Method is used to set blur ratio value.
 * @param	effectRation is blur ratio.
 */
void MotionBlur::setBlurRatio(const float effectRatio)
{
	this->blurRatio = effectRatio;

}

}
