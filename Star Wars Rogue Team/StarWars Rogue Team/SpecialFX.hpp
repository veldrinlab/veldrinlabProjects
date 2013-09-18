/**
 * File contains declaration of abstarct base class of Engine Special Effects.
 * @file    SpecialFX.h
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2010-11-18
 * @version 1.0
 */

#ifndef SPECIALFX_H
#define SPECIALFX_H

#include <SDL.h>
#include <SDL_opengl.h> 
#include <GL/gl.h>

namespace specialFx
{
/**
 * Abstract class reresents base class for all Engine Special Effects such as Fog or Motion Blur. All effects
 * must implement initialize method. 
 * @remarks 
 */
class SpecialFX
{
public:
	virtual ~SpecialFX() {};
	virtual void initializeEffect() = 0;
	virtual void updateEffect(const float elapsedTime) {} ;
	virtual void renderEffect() {};
};
}
#endif
