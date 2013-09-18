#ifndef HEALTHBAR_HPP
#define HEALTHBAR_HPP

#include "../Engine/SceneEntity.hpp"
#include "../ResourceManager/ResourceManager.hpp"

namespace Game
{
	class HealthBar
	{
	public:

		int maxValue;
		Engine::SceneEntity* entity;

		HealthBar(Engine::SceneEntity* entity);
		~HealthBar();

		void renderHealthBar();
	
	};
}
#endif
