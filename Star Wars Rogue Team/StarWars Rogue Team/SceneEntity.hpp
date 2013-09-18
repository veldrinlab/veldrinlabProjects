/**
 * File contains declaration of SceneEntity class.
 * @file    SceneEntity.hpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2010-11-08
 * @version 1.0
 */

#ifndef SCENE_ENTITY_HPP
#define SCENE_ENTITY_HPP

#include "SceneNode.hpp"
#include "BoundingBox.hpp"
#include "Quaternion.hpp"
#include "Faction.hpp"

using namespace math;
using namespace game;

namespace engine
{

/**
 * SceneEntity class extends SceneNode class. It represents an object in the game world. All objects of game scene
 * are instances of SceneEntity class.
 * @remarks 
 */
class SceneEntity : public SceneNode
{
public:
	Vector3D position;
	Vector3D velocity;
	Vector3D acceleration;
	BoundingBox* collisionBox;
	Faction faction;
	
	int healthPoints;
	bool isDead;
	bool haveCollided;

	SceneEntity() {};
	virtual ~SceneEntity() {};

	virtual void updateEntity(const float elapsedTime) = 0;
	virtual void renderEntity() = 0;

	/**
	 * Accessor to SceneEntity Bounding Box.
	 * @return	entity bounding box.
	 */
	BoundingBox* getBoundingBox()
	{
		return collisionBox;
	}

	/**
	 * Method is used to decrease health points when entity is hit by LaserBlast.
	 */
	void decreaseHP()
	{
		healthPoints--;
	}
};

}
#endif
