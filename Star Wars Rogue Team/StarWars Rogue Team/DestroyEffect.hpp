/**
 * File contains declaration of one of game particle system special effects class  - DestroyEffect.
 * @file    DestroyEffect.hpp
 * @author  Szymon "Veldrin" Jab�o�ski
 * @date    2010-12-02
 * @version 1.0
 */

#ifndef DESTROYEFFECT_HPP
#define DESTROYEFFECT_HPP

#include "Particle.hpp"
#include "ResourceManager/ResourceManager.hpp"

using namespace math;
using namespace resMan;

namespace specialFx
{
/**
 * Class represents one of game special effects which occure when some object have been destroyed.
 */
class DestroyEffect : public ParticleSystem
{
private:
	Vector3D origin;
	float effectTime;
	PResource texture;

	virtual void onInitialize(Particle* p);
	virtual void onUpdate(Particle* p, const float elapsedTime);

public:
	DestroyEffect(const Vector3D& origin);
	~DestroyEffect();

	void renderEffect();
};
}
#endif 
