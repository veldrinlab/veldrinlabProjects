/**
 * Fle contains declaration of Lighting class - one of Engine Special Effetcs and LightState,
 * represents information of each light. 
 * @file    Lighting.h
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2010-11-18
 * @version 1.0
 */

#ifndef LIGHTING_H
#define LIGHTING_H

#include <SDL.h>
#include <SDL_opengl.h> 
#include <GL/gl.h>
#include <GL/glu.h>

#include <vector>


/**
 * Class represents information about one Light source.
 * @remarks 
 */
class LightState
{
public:
	float ambientLight[3];
	float diffuseLight[3];
	float lightPosition[4];
	float matAmbient[4];
	float matDiff[4];

	LightState();
	~LightState() {}
};

/**
 * Class represents Engine Special Effect - Lighting. Class store information about all lights and turn can
 * turn it on/off. Each light(cane be max. 8) are repsented by LightState object.
 * @remarks 
 */
class Lighting
{
private:
	std::vector<LightState> lights;
	LightState* environmentLight;

public:
	Lighting();
	~Lighting();
	void initializeEffect();
	void updateEffect() {}

	void lightsUp();
	void lightsDown();

	void changeSpectrum();

};
#endif
