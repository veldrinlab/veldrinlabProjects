/**
 * Fle contains declaration of Lighting class - one of Engine Special Effetcs and LightState,
 * represents information of each light. 
 * @file    Lighting.hpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2010-11-18
 * @version 1.0
 */

#ifndef LIGHTING_HPP
#define LIGHTING_HPP

#include <vector>
#include "SpecialFX.hpp"

namespace specialFx
{
/**
 * Class represents information about one Light source.
 * @remarks 
 */
class LightState
{
public:
	float ambientLight[4];
	float diffuseLight[4];
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
class Lighting : public SpecialFX
{
private:
	std::vector<LightState> lights;
	LightState* environmentLight;

public:
	Lighting();
	~Lighting();
	void initializeEffect();
	void updateEffect(const float elapsedTime) {}

};
}
#endif
