/**
 * File contains declaraion of AnimatedEntity class.
 * @file    AnimatedEntity.hpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2012-04-01
 */

#ifndef ANIMATEDENTITY_HPP
#define ANIMATEDENTITY_HPP

#include "SceneEntity.hpp"
#include "Animation.hpp"

namespace dse
{
	/**
	 * Class represents animated game scene entity.
	 */
	class AnimatedEntity : public dse::SceneEntity
	{
	public:
		int animation;
		std::vector<Animation*> animations;

		/**
		 * Method is used to set current animation.
		 * @param	anim is animation frame id.
		 */
		void setAnimation(const int anim)
		{
			this->animation = anim;
			animations[animation]->time=0;
		}

		/**
		 * Method is used to update animated entity frame.
		 * @param	dt is time step.
		 */
		void update(const float dt)
		{
			SetTexture(*animations[animation]->update(dt));
		}

		/**
		 * Class constructor with initialize paramters.
		 * @param	name is entity name.
		 * @pram	tex is entity texture name.
		 */
		AnimatedEntity(const std::string& name,const std::string& tex)
		{
			this->name = name;
			this->textureName = tex;
			animation = 0;
		}

		/**
		 * Class destructor, free allocated memory.
		 */
		virtual ~AnimatedEntity()
		{
			for(unsigned i=0;i<animations.size();i++)
				delete animations[i];
		}
	};
}
#endif

