/**
 * File contains declaration of World class.
 * @file    World.hpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date	2011-02-27
 * @version 1.0
 */

#ifndef WORLD_HPP
#define WORLD_HPP

#include "../Engine/SceneEntity.hpp"
#include "../ResourceManager/ResourceManager.hpp"

namespace Game
{

/**
 * Class represents game virtual world. In our case it is just background.
 */
class World : public Engine::SceneEntity
{
private:
	Resource::PResource texture;

	World() {};
public:
	World(const char* textureFileName);
	~World();

	void updateEntity(const float elapsedTime);
	void renderEntity();

};

}

#endif