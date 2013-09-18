#ifndef EXPLOSIONEFFECT_HPP
#define EXPLOSIONEFFECT_HPP

#include "Particle.hpp"
#include "../ResourceManager/ResourceManager.hpp"
namespace Engine
{

/**
 * Class represents one one game special effects occure when collision is detected.
 */
class ExplosionEffect : public ParticleSystem
{
private:
	Math::Vector3D origin;
	float effectTime;
	Resource::PResource texture;

	virtual void onInitialize(Particle* p);
	virtual void onUpdate(Particle* p, const float elapsedTime);

public:
	ExplosionEffect(const Math::Vector3D& origin);
	~ExplosionEffect();

	void renderEffect();
};
}

#endif