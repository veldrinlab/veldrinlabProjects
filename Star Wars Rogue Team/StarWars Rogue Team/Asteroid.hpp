/**
 * File contains declaration of Asteroid class.
 * @file    Asteroid.hpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2010-12-19
 * @version 1.0
 */

#ifndef ASTEROID_HPP
#define ASTEROID_HPP

#include "SceneEntity.hpp"
#include "Shader.hpp"
#include "VBO.hpp"
#include "EnemyPrototype.hpp"
#include "ResourceManager/ResourceManager.hpp"

using namespace resMan;

namespace game
{
/**
 * Class represents Asteroid object which is part of space scene. If X-wing or Tie-fighter collide with
 * asteroid they might be destroyed.
 * @remarks
 */
class Asteroid : public SceneEntity, public EnemyPrototype
{
private:
	PResource mesh;
	PResource texture;
	Shader shader;
	VBO* entityVBO;
	Asteroid();
public:
	Asteroid(const char* meshFileName, const char* textureFileName, const Vector3D& position);
	~Asteroid();

	void updateEntity(const float elapsedTime);
	void renderEntity();
	virtual EnemyPrototype* clone();

};

}
#endif
