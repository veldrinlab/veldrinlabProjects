/**
 * File contains declaraion of Particle structure.
 * @file    Particle.hpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2011-08-06
 */

#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include <SFML/Graphics.hpp>

namespace dse
{
	/**
	 * Static method which is used to get random integer value.
	 * @param	a is random min.
	 * @param	b is random max.
	 * @return	random integer value.
	 */
	static int randInt(const int a, const int b)
	{
		return rand() % b + a;
	}

	/**
	 * Static method which is used to get random float value.
	 * @param	a is random min.
	 * @param	b is random max.
	 * @return	random float value.
	 */
	static float randFloat(const float a, const float b)
	{
		return ((b-a)*((float)rand()/RAND_MAX))+a;
	}

	/**
	 * Structure represents particle. It extends sfml drawable sf::Sprite class.
	 */
	struct Particle : public sf::Sprite
	{
		Particle* next;
		sf::Vector2f position;
		sf::Vector2f velocity;
		sf::Vector2f acceleration;
		sf::Color color;
		float rotationSpeed;
		float lifeTime;
		float rotation;
		float size;
		bool isDied;

		/**
		 * Class default constructor. Set default values.
		 */
		Particle()
		{
			next = nullptr;
			rotationSpeed = 0.0f;
			lifeTime = 0.0f;
			rotation = 0.0f;
			size = 0.0f;
			isDied = false;
		}

		/**
		 * Class destructor, free allocated memory.
		 */
		virtual ~Particle(){};
	};
}
#endif
