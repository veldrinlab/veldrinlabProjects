#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "../Engine/SceneEntity.hpp"
#include "../ResourceManager/ResourceManager.hpp"
#include "PlayerPad.hpp"


namespace Game
{

class Enemy : public Engine::SceneEntity
{
private:
	Resource::PResource texture;
	Math::Vector3D moveDirection;
	PlayerPad* player;


	Math::Vector3D kernelPosition;

	Enemy();
public:

	Enemy(const char* textureFileName, const Math::Vector3D& position, PlayerPad* player);
	Enemy(const char* textureFileName, const Math::Vector3D& position);

	~Enemy();

	void updateEntity(const float elapsedTime);
	void renderEntity();

};

}
#endif
