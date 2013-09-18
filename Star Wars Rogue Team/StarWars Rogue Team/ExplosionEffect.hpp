/**
 * File contains declaration of one of game particle system special effects class  - ExplosionEffect.
 * @file    ExplosionEffect.hpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2010-12-02
 * @version 1.0
 */

#ifndef EXPLOSIONEFFECT_HPP
#define EXPLOSIONEFFECT_HPP

#include "Particle.hpp"
#include "ResourceManager/ResourceManager.hpp"

using namespace math;
using namespace resMan;

namespace specialFx
{
/**
 * Class represents one one game special effects occure when collision is detected.
 */
class ExplosionEffect : public ParticleSystem
{
private:
	Vector3D origin;
	float effectTime;
	PResource texture;

	virtual void onInitialize(Particle* p);
	virtual void onUpdate(Particle* p, const float elapsedTime);

public:
	ExplosionEffect(const Vector3D& origin);
	~ExplosionEffect();

	void renderEffect();
};
}
#endif 
