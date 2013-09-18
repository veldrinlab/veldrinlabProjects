/**
 * File contains definition of Collision Detection and Handling classes.
 * @file    CollisionDetector.cpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2010-11-24
 * @version 1.0
 */

#include "CollisionDetector.h"

using namespace std;
using namespace boost;

/**
 * Constructor with initialize parameters.
 * @param   handler is pointer to handler object.
 * @param   gameScene is pointer to game Scene.
 */
CollisionDetector::CollisionDetector(CollisionHandler* handler,SceneManager* gameScene)
{
	this->gameScene = gameScene;
	this->handler = handler;
}

/** 
 * Method is used to detect collision. Use Bounding Box algorithm.
 */
void CollisionDetector::detectCollision()
{
	vector<boost::shared_ptr<SceneEntity>>* scene = gameScene->getWorldScene();

	unsigned int size = scene->size();

	for(unsigned int i = 2; i < size; ++i)
	{
		BoundingBox firstBox;
		firstBox.max =  scene->at(i).get()->getBoundingBox()->max;
		firstBox.min =  scene->at(i).get()->getBoundingBox()->min;
		firstBox.max += scene->at(i).get()->position;
		firstBox.min += scene->at(i).get()->position;
		
		bool firstIsEvil = scene->at(i).get()->isEvil;
		bool firstHaveCollided = scene->at(i).get()->haveCollided;

		for(unsigned int j = 2; j < size; ++j)
		{
			if(i == j)
				continue;

			BoundingBox secondBox;
			bool secondIsEvil = scene->at(j).get()->isEvil;
			bool secondHaveCollided = scene->at(j).get()->haveCollided;

			secondBox.max =  scene->at(j).get()->getBoundingBox()->max;
			secondBox.min =  scene->at(j).get()->getBoundingBox()->min;
			secondBox.max += scene->at(j).get()->position;
			secondBox.min += scene->at(j).get()->position;

			if(!secondHaveCollided && !firstHaveCollided && firstIsEvil != secondIsEvil && isCollision(firstBox,secondBox))
			{
				scene->at(i).get()->haveCollided = true;
				scene->at(j).get()->haveCollided = true;
				handler->collisionCollection.push_back(Collision(scene->at(j).get()->position,i,j));
			}
		}
	}
}

/**
 * Method is used to check if there is collision between two game scene objects.
 * @param   firstBox is first object Bounding Box.
 * @param   secondBox is second object Bounding Box.
 * @return	true if it is collision 
 */
bool CollisionDetector::isCollision(const BoundingBox& firstBox, const BoundingBox& secondBox)
{
	if(firstBox.min.x <= secondBox.max.x && firstBox.max.x >= secondBox.min.x && 
		firstBox.min.z <= secondBox.max.z && firstBox.max.z >= secondBox.min.z )
		return true;

	return false;
}

/**
 * Constructor with initialize parameters.
 * @param   gameScene is pointer to game Scene.
 */
CollisionHandler::CollisionHandler(SceneManager* gameScene)
{
	this->gameScene = gameScene;
}

/**
 * Method is used to handle collision. The only collision on Scene can be collsion between LaserBlast
 * and SpaceShip/Invader object so we decrease SpaceShip/Invader heath points.
 */
void CollisionHandler::handleCollision()
{
	for(unsigned int i = 0; i < collisionCollection.size(); ++i)
	{
		this->gameScene->getWorldScene()->at(collisionCollection[i].firstID)->decreaseHP();
		this->gameScene->getWorldScene()->at(collisionCollection[i].secondID)->decreaseHP();
		this->gameScene->addSpecialEffect(collisionCollection[i].position);

		this->gameScene->getWorldScene()->at(collisionCollection[i].firstID)->haveCollided = false;
		this->gameScene->getWorldScene()->at(collisionCollection[i].firstID)->haveCollided = false;
	}

	collisionCollection.clear();

}
