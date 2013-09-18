/**
 * File contains declaration of one of game particle system special effects class  - DestroyEffect.
 * @file    DestroyEffect.h
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2010-12-02
 * @version 1.0
 */

#ifndef DESTROYEFFECT_H
#define DESTROYEFFECT_H

#include "Particle.h"

/**
 * Class represents one of game special effects which occure when some object have been destroyed.
 */
class DestroyEffect : public ParticleSystem
{
private:
	Vector3D origin;
	float effectTime;
	Texture* texture;

	virtual void onInitialize(Particle* p);
	virtual void onUpdate(Particle* p, const float elapsedTime);

public:
	DestroyEffect(const Vector3D& origin);
	~DestroyEffect();

	void renderEffect();
};
#endif 
