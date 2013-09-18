/**
 * File contains declaration of Particle System classes.
 * @file    Particle.hpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2010-12-01
 * @version 1.0
 */

#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include <SDL.h>
#include <SDL_opengl.h> 
#include <GL/gl.h>
#include <GL/glu.h>

#include "SpecialFX.hpp"
#include "Random.hpp"
#include "ResourceManager/ResourceManager.hpp"

using namespace math;

namespace specialFx
{
#define FRAND ((float)(rand()-rand())/RAND_MAX)

/**
 * Class represents basic part of ParticleSystem - Particle which represents particle state.
 * @remarks	maybe add ParticleState class, or just change class name.
 */
class Particle
{
public:
	Particle *next;

	Vector3D position;
	Vector3D velocity;
	Vector3D accelration;
	Vector3D rotation;
	Color color;
	float lifeTime;
	float size;
	bool isDied;

	Particle();
	~Particle();

};

/**
 * Class represents ParticleSystem which is abstract base class of all particle effects emiters.
 * @remarks	maybe make something like System and Emitters.
 */
class ParticleSystem : public SpecialFX
{
protected:
	Particle *firstParticle;
	bool isDead;
	
	virtual void onInitialize(Particle *p) = 0;
	virtual void onUpdate(Particle *p, const float elapsedTime) = 0;

public:
	ParticleSystem(const int numParticles);
	virtual ~ParticleSystem();

	void initializeEffect();
	void updateEffect(const float elapsedTime);
	virtual void renderEffect() = 0;
	
	/**
	 * Method is used to check if particle is dead.
	 * @return	true is particle is dead.
	 */
	bool isEnd()
	{
		return isDead;
	}
};
}
#endif
