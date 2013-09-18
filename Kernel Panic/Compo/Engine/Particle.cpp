/**
 * File contains definition of Particle System classes.
 * @file    Particle.cpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2010-12-01
 * @version 1.0
 */

#include "Particle.hpp"

namespace Engine
{

/**
 * Default constructor, 
 */
Particle::Particle()
{
	next = NULL;
}

/**
 * Destructor, nothing to do.
 */
Particle::~Particle()
{

}

/**
 * Constructor with initialize parameters.
 * @param	numParticles is number of partciles in system.
 * @param	texture is partciles texture.
 */
ParticleSystem::ParticleSystem(const int numParticles)
{
	firstParticle = NULL;
	srand(SDL_GetTicks());

	Particle *p;
	for(int i=0;i<numParticles;i++)
	{
		p = new Particle();
		p->next = firstParticle;
		firstParticle = p;
	}
}

/**
 * Destructor, free alocated memory.
 * @remarks	use smart_ptr.
 */
ParticleSystem::~ParticleSystem()
{
	if(firstParticle==NULL)
		return;

	Particle* p = firstParticle;
	Particle* q = firstParticle->next;
	while(q)
	{
		delete p;
		p = q;
		q = q->next;
	}
	delete p;
}

/**
 * Method is used to initialize particle system.
 */
void ParticleSystem::initialize()
{
	Particle* p = firstParticle;
	while(p)
	{
		onInitialize(p);
		p = p->next;
	}
}

/**
 * Method is used to update particle system - update all particles.
 * @param	elapsedTime is time between frames.
 */
void ParticleSystem::update(const float elapsedTime)
{ 
	Particle* p = firstParticle;
	while(p)
	{
		//p->velocity += p->accelration * elapsedTime;
		p->position += p->velocity * elapsedTime;
		onUpdate(p, elapsedTime);
		p = p->next;
	}
}

}
