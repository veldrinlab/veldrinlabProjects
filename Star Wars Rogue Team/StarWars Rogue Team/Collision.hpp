/**
 * File contains declaraion of Collision Detection and Handling classes.
 * @file    CollisionDetector.hpp
 * @author  Szymon "Veldrin" Jab³oñski and Katarzyna Na³êcz
 * @date    2011-01-10
 * @version 1.0
 */

#ifndef COLLISION_HPP
#define COLLISION_HPP

#include <vector>

#include "SceneManager.hpp"
#include "Faction.hpp"

using namespace math;

namespace engine
{

/**
 * Class represents Collision object. Each collsion is defined by position of collision
 * and collided objects ID (index in worldScene).
 */
class Collision
{
public:
	Collision(const Vector3D& position, const int firstID, const int secondID, SceneManager* gameScene)
	{
		this->position = position;
		this->firstID = firstID;
		this->secondID = secondID;
		this->gameScene = gameScene;
	}

	Vector3D position;
	int firstID;
	int secondID;
	SceneManager* gameScene;

	virtual void handleCollision() = 0;
};

class CollisionXwingAsteroid : public Collision
{
public:
  CollisionXwingAsteroid(const Vector3D& position, const int firstID, const int secondID, SceneManager* gameScene)
    : Collision(position, firstID, secondID, gameScene) {}

  void handleCollision()
  {
    gameScene->getWorldScene()->at(firstID)->isDead  = true;
    gameScene->getWorldScene()->at(secondID)->isDead = true;

    gameScene->getWorldScene()->at(firstID)->haveCollided  = false;
    gameScene->getWorldScene()->at(secondID)->haveCollided = false;
  }
};

class CollisionXwingImperialShip : public Collision
{
public:
  CollisionXwingImperialShip(const Vector3D& position, const int firstID, const int secondID, SceneManager* gameScene)
    : Collision(position, firstID, secondID, gameScene) {}

  void handleCollision()
  {
    gameScene->getWorldScene()->at(firstID)->isDead  = true;
    gameScene->getWorldScene()->at(secondID)->isDead = true;

    gameScene->getWorldScene()->at(firstID)->haveCollided  = false;
    gameScene->getWorldScene()->at(secondID)->haveCollided = false;
  }
};

class CollisionXwingLaserBlast : public Collision
{
public:
  CollisionXwingLaserBlast(const Vector3D& position, const int firstID, const int secondID, SceneManager* gameScene)
    : Collision(position, firstID, secondID, gameScene) {}

  void handleCollision()
  {
    gameScene->getWorldScene()->at(firstID)->decreaseHP();
    gameScene->getWorldScene()->at(secondID)->decreaseHP();

    gameScene->getWorldScene()->at(firstID)->haveCollided  = false;
    gameScene->getWorldScene()->at(secondID)->haveCollided = false;
  }
};

class CollisionTieFighterLaserBlast : public Collision
{
public:
  CollisionTieFighterLaserBlast(const Vector3D& position, const int firstID, const int secondID, SceneManager* gameScene)
    : Collision(position, firstID, secondID, gameScene) {}

  void handleCollision()
  {
    gameScene->getWorldScene()->at(firstID)->decreaseHP();
    gameScene->getWorldScene()->at(secondID)->decreaseHP();

    gameScene->getWorldScene()->at(firstID)->haveCollided  = false;
    gameScene->getWorldScene()->at(secondID)->haveCollided = false;
  }
};

class CollisionLaserBlastLaserBlast : public Collision
{
public:
  CollisionLaserBlastLaserBlast(const Vector3D& position, const int firstID, const int secondID, SceneManager* gameScene)
    : Collision(position, firstID, secondID, gameScene) {}

  void handleCollision()
  {
    gameScene->getWorldScene()->at(firstID)->decreaseHP();
    gameScene->getWorldScene()->at(secondID)->decreaseHP();

    gameScene->getWorldScene()->at(firstID)->haveCollided  = false;
    gameScene->getWorldScene()->at(secondID)->haveCollided = false;
  }
};

/* TODO to jest kolizja pozosta³ych obiektów */
class CollisionObjectObject : public Collision
{
public:
  CollisionObjectObject(const Vector3D& position, const int firstID, const int secondID, SceneManager* gameScene)
    : Collision(position, firstID, secondID, gameScene) {}

  void handleCollision()
  {

  }
};

}
#endif