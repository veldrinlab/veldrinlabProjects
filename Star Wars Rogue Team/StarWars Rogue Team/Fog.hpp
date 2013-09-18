/**
 * Fle contains declaration of Fog class - one of Engine Special Effects.
 * @file    Fog.hpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2010-11-18
 * @version 1.0
 */

#ifndef FOG_HPP
#define FOG_HPP

#include "SpecialFX.hpp"

namespace specialFx
{
/**
 * Fog class represents one of Engine Special effects - fog.
 * @remarks 
 */
class Fog : public SpecialFX
{
private:
	GLfloat fogDensity;
	GLuint fogMode;
	GLfloat fogColor[4]; //use color class

public:
	Fog(const GLfloat fogDensity,const GLuint fogMode, const GLfloat* fogColor);
	Fog();
	~Fog();
	void initializeEffect();
	void updateEffect(const float elapsedTime) {};

};
}
#endif
