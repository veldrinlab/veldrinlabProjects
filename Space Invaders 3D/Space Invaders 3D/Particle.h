/**
 * File contains declaration of Particle System classes.
 * @file    Particle.h
 * @author  Szymon "Veldrin" Jab�o�ski
 * @date    2010-12-01
 * @version 1.0
 */


#ifndef PARTICLE_H
#define PARTICLE_H

#include <SDL.h>
#include <SDL_opengl.h> 
#include <GL/gl.h>
#include <GL/glu.h>

#include "Texture.h"
#include "Random.h"

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
class ParticleSystem
{
protected:
	Particle *firstParticle;
	bool isDead;
	
	virtual void onInitialize(Particle *p) = 0;
	virtual void onUpdate(Particle *p, const float elapsedTime) = 0;

public:
	ParticleSystem(const int numParticles);
	virtual ~ParticleSystem();

	void initialize();
	void update(const float elapsedTime);
	virtual void renderEffect() = 0;

	bool isEnd()
	{
		return isDead;
	}
};
#endif
