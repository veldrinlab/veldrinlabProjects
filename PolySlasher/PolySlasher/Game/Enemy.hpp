/**
 * File contains declaration of Enemy class.
 * @file    Enemy.hpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2011-02-28
 * @version 1.0
 */

#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "../Engine/SceneEntity.hpp"
#include "../ResourceManager/ResourceManager.hpp"
#include "Player.hpp"


namespace Game
{
/**
 * Class represents world evil power - Enemy. Store pointer to Player object.
 * @remarks optimization.
 */
class Enemy : public Engine::SceneEntity
{
private:
	Resource::PResource texture;
	Math::Vector3D moveDirection;
	Player* player;
	Enemy();
public:
	Enemy(const char* textureFileName, const Math::Vector3D& position, Player* player);
	~Enemy();

	void updateEntity(const float elapsedTime);
	void renderEntity();

};

}
#endif
