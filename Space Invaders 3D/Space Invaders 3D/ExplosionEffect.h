/**
 * File contains declaration of one of game particle system special effects class  - ExplosionEffect.
 * @file    ExplosionEffect.h
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2010-12-02
 * @version 1.0
 */

#ifndef EXPLOSIONEFFECT_H
#define EXPLOSIONEFFECT_H

#include "Particle.h"

/**
 * Class represents one one game special effects occure when collision is detected.
 */
class ExplosionEffect : public ParticleSystem
{
private:
	Vector3D origin;
	float effectTime;
	Texture* texture;

	virtual void onInitialize(Particle* p);
	virtual void onUpdate(Particle* p, const float elapsedTime);

public:
	ExplosionEffect(const Vector3D& origin);
	~ExplosionEffect();

	void renderEffect();
};

#endif 