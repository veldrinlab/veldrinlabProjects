/**
 * File contains declaraion of Collision Detection and Handling classes.
 * @file    CollisionDetector.hpp
 * @author  Szymon "Veldrin" Jab³oñski and Katarzyna Na³êcz
 * @date    2010-11-24
 * @version 1.0
 */

#ifndef COLLISIONDETECTOR_HPP
#define COLLISIONDETECTOR_HPP

#include <boost/ptr_container/ptr_vector.hpp>
#include <vector>

#include "SceneManager.hpp"
#include "Faction.hpp"
#include "Collision.hpp"

using namespace std;
using namespace game;

namespace engine
{

/**
 * Class represents collision handler object. Store collection of collisions and handle specified events.
 */
class CollisionHandler
{
private:
	SceneManager* gameScene;

public:
    boost::ptr_vector<Collision> collisionCollection;

	CollisionHandler(SceneManager* gameScene);
	void handleCollision();
};

/**
 * Class represents collision detector. Object is used to detect collision is Scene, create Collision objects
 * and give them to CollisionHandler to handle it.
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
    /**
     * Simple factory method; creates collision object appropriate for type identifiers.
     */
    Collision* createCollisionObject(Faction firstTypeID, Faction secondTypeID, 
                                   const Vector3D& position, const int firstID, const int secondID,
                                   SceneManager* gameScene);
};

}
#endif
