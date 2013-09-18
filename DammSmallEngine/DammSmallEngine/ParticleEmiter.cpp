/**
 * File contains definition of ParticleEmiter class.
 * @file    ParticleEmiter.cpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2011-08-06
 */

#include "ParticleEmiter.hpp"

namespace dse
{
	/**
	 * Class constructor with initialize variables.
	 * @param	numParticles is amount init particles.
	 */
	ParticleEmiter::ParticleEmiter(const int numParticles)
	{
		lifeTime = 0;
		firstParticle = nullptr;
		srand(static_cast<unsigned int>(time(0)));
		isDead = false;

		Particle* p = nullptr;
		for(int i=0; i < numParticles; ++i)
		{
			p = new Particle();
			p->next = firstParticle;
			firstParticle = p;
		}
	}

	/**
	 * Class destructor, free allocated memory for particles.
	 */
	ParticleEmiter::~ParticleEmiter()
	{
		if(firstParticle == nullptr)
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
	 * Method is used initialize particle effect.
	 */
	void ParticleEmiter::initializeEffect()
	{
		Particle* p = firstParticle;
		while(p)
		{
			onInitialize(p);
			p = p->next;
		}
	}

	/**
	 * Method is used to update particle effect.
	 * @param	elapsedTime is update time step between frames.
	 */
	void ParticleEmiter::updateEffect(const float elapsedTime)
	{ 
		Particle* p = firstParticle;
		while(p)
		{
			onUpdate(p, elapsedTime);
			p = p->next;
		}
	}
}
