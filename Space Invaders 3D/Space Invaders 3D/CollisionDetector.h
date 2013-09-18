/**
 * File contains declaraion of Collision Detection and Handling classes.
 * @file    CollisionDetector.h
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2010-11-24
 * @version 1.0
 */

#ifndef COLLISIONDETECTOR_H
#define COLLISIONDETECTOR_H

#include <vector>

#include "SceneManager.h"

/**
 * Class represents Collision object. Each collsion is defined by position of collision and collided objects ID.
 */
class Collision
{
public:
	Collision(const Vector3D& position, const int firstID, const int secondID)
	{
		this->position = position;
		this->firstID = firstID;
		this->secondID = secondID;
	}

	Vector3D position;
	int firstID;
	int secondID;
};

/**
 * Class represents collision handler object. Store collection of collisions and handle specified events.
 */
class CollisionHandler
{
private:
	SceneManager* gameScene;

public:
	std::vector<Collision> collisionCollection;

	CollisionHandler(SceneManager* gameScene);
	void handleCollision();

};

/**
 * Class represents collision detector. Object is used to detect collision is Scene, create Collision objects
 * and give them to CollisionHandler to handle ti.
 */
class CollisionDetector
{
private:
	SceneManager* gameScene;
	CollisionHandler* handler;

public:
	CollisionDetector(CollisionHandler* handler,SceneManager* gameScene);
	void detectCollision();
	bool isCollision(const BoundingBox& firstBox, const BoundingBox& secondBox);

};
#endif
