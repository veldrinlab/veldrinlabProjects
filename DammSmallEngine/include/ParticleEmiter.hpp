/**
 * File contains declaraion of ParticleEmiter class.
 * @file    ParticleEmiter.hpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2011-08-06
 */

#ifndef PARTICLEEMITER_HPP
#define PARTICLEEMITER_HPP

#include "Particle.hpp"

namespace dse
{
	/**
	 * Class represents particle emiter. Is is used to create particle effects. 
	 */
	class ParticleEmiter
	{
	protected:
		Particle *firstParticle;
		bool isDead;
		float lifeTime;
	
		virtual void onInitialize(Particle* p) = 0;
		virtual void onUpdate(Particle* p, const float elapsedTime) = 0;

	public:
		ParticleEmiter(const int numParticles);
		virtual ~ParticleEmiter();

		virtual void initializeEffect();
		virtual void updateEffect(const float elapsedTime);
		
		/**
		 * Accessor to private member, check if emiter is dead.
		 * @return	true if dead, false otherwise.
		 */
		bool isEnd() const
		{
			return isDead;
		}

		/**
		 * Accessor to private emiter first particle.
		 * @return	pointer to particle list first particle.
		 */
		Particle* get()
		{
			return firstParticle;
		}
	};
}
#endif
