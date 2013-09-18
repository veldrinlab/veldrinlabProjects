/**
 * File contains definition of SpecialFXManger class.
 * @file    SpecialFXManager.cpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2010-11-18
 * @version 1.0
 */

#include "SpecialFXManager.hpp"

using namespace std;

namespace specialFx
{

/**
 * Default constrcutor.
 */
SpecialFXManager::SpecialFXManager()
{

}

/**
 * Destructor, noting to do.
 */
SpecialFXManager::~SpecialFXManager()
{

}

/**
 * Method is used to add new special effect to special effect collection.
 * @param   specialEffect is new specialEffect.
 */
void SpecialFXManager::addSpecialEffect(SpecialFX* specialEffect)
{
	specialEffect->initializeEffect();
	effects.push_back(EffectPtr(specialEffect));
}

/**
 * Method used to initialize all special effects which is controlled by Manager.
 */
void SpecialFXManager::initializeEffects()
{
	for(SpecialEffects::const_iterator i = effects.begin(); i!=effects.end(); ++i)
		(**i).initializeEffect();

}

/**
 * Method used to update all special effects which is controlled by Manager.
 * @param	elapsedTime is the time which represents how long effect is running.
 */
void SpecialFXManager::updateEffects(const float elapsedTime)
{
	for(SpecialEffects::const_iterator i = effects.begin(); i!=effects.end(); ++i)
		(**i).updateEffect(elapsedTime);
}

/**
 * Method is used to render all special effects which is controlled by Manager.
 */
void SpecialFXManager::renderEffects()
{
		for(SpecialEffects::const_iterator i = effects.begin(); i!=effects.end(); ++i)
		(**i).renderEffect();
}

/**
 * Accessor to private memebr.
 * @return	pointer to MotionBlur effect object.
 */
MotionBlur* SpecialFXManager::getMotionBlur()
{
	return static_cast<MotionBlur*>(effects.at(1).get());
}

}
