/**
 * File contains declaraion of Animation structure.
 * @file    Animation.hpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2012-04-01
 */

#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include <SFML/Graphics/Sprite.hpp>

#include <vector>
#include <math.h>

namespace dse
{
	/**
	 * Structure represents animation.
	 */
	struct Animation
	{
		float time;
		std::vector<sf::Texture*> frames;

		virtual sf::Texture* update(const float dt);
		
		/**
		 * Class default constructor.
		 */
		Animation()
		{
			time = 0;
		}

		/**
		 * Class destructor.
		 */
		virtual ~Animation()
		{

		}
	};
}
#endif
