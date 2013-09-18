#ifndef TOWER_HPP
#define TOWER_HPP

#include "../Engine/SceneEntity.hpp"
#include "../ResourceManager/ResourceManager.hpp"
#include "AnimationFrameCoords.hpp"

namespace Game
{
	class Tower : public Engine::SceneEntity
	{
	private:
		Tower();

	public:
		Resource::PResource texture;
		Resource::PResource light;

		Tower(const char* textureFileName, const Math::Vector3D& position, const int hpAmount);
		~Tower();

		void renderEntity();
		void updateEntity(const float elapsedTime);

		bool active;
		bool moving;

		int currentFrame;
		AnimationFrameCoords framesCoords[10];
		int framesCounter;

	};

}

#endif
