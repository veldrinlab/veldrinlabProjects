/**
 * File contains declaration of SpecialFXManger class.
 * @file    SpecialFXManager.hpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2010-11-18
 * @version 1.0
 */

#ifndef SPECIALFXMANAGER_HPP
#define SPECIALFXMANAGER_HPP

#include <boost/shared_ptr.hpp>
#include <vector>

#include "SpecialFX.hpp"
#include "Lighting.hpp"
#include "Fog.hpp"
#include "MotionBlur.hpp"

namespace specialFx
{
/**
 * SpecialFXManager class is used to store, initialize and remove Game Scene Special Effects like Fog
 * or Lighting.
 * @remarks 
 */
class SpecialFXManager
{
	typedef boost::shared_ptr<SpecialFX> EffectPtr;
	typedef std::vector<EffectPtr> SpecialEffects;

private:
	SpecialEffects effects;

public:
	SpecialFXManager();
	~SpecialFXManager();

	void addSpecialEffect(SpecialFX* specialEffect);

	void initializeEffects();
	void updateEffects(const float elapsedTime);
	void renderEffects();

	MotionBlur* getMotionBlur();
};
}
#endif
