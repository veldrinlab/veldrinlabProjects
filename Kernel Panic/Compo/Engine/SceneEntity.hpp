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
#include "../Utils/BoundingSphere.hpp"

namespace Engine
{

/**
 * SceneEntity class extends SceneNode class. It represents an object in the game world. All objects of game scene
 * are instances of SceneEntity class.
 * @remarks 
 */
class SceneEntity : public SceneNode
{
public:
	Math::Vector3D position;
	Math::Vector3D velocity;
	Math::Vector3D acceleration;
	
	//for hud
	int healthPoints;
	int height;
	int width;


	bool isDead;
	bool isVisible;
	Utils::BoundingSphere collisionSphere;

	/**
	 * Default constructor.
	 */
	SceneEntity() {};
	virtual ~SceneEntity() {};

	virtual void updateEntity(const float elapsedTime) = 0;
	virtual void renderEntity() = 0;

	/**
	 * Method is used to decrease hp amount.
	 */
	void damaged(int power = 2)
	{
		healthPoints -= power;
	}

	void setSize(const int h, const int w)
    {
		height = h;
		width = w;
	}

};

}
#endif
