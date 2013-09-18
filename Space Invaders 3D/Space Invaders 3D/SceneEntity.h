/**
 * File contains declaration of SceneEntity class.
 * @file    SceneEntity.h
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2010-11-08
 * @version 1.0
 */

#ifndef SCENE_ENTITY_H
#define SCENE_ENTITY_H

#include "Mesh.h"
#include "Texture.h"
#include "BoundingBox.h"

/**
 * SceneEntity class extedns SceneNode class. It represents an object in the game world. All objects of game scene
 * are instance of SceneEntity class.
 * @remarks 
 */
class SceneEntity
{
public:
	Vector3D position;
	Vector3D velocity;
	Vector3D acceleration;
	BoundingBox* collisionBox;
	int healthPoints;
	bool isDead;
	bool isEvil;
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
	 * Method is used to decrease heth points when entity is hitted by LaserBlast.
	 */
	void decreaseHP()
	{
		healthPoints--;
	}
};
#endif
