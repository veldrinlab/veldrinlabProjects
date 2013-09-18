/**
 * File contains definition of CollisionDetection and CollisionHandling classes.
 * @file    CollisionDetector.cpp
 * @author  Szymon "Veldrin" Jab³oñski and Katarzyna Na³êcz
 * @date    2010-11-24
 * @version 1.0
 */

#include "CollisionDetector.hpp"

using namespace std;
using namespace boost;

namespace engine
{

/**
 * Constructor with initialize parameters.
 * @param   handler is pointer to handler object.
 * @param   gameScene is pointer to game Scene.
 */
CollisionDetector::CollisionDetector(CollisionHandler* handler, SceneManager* gameScene)
{
	this->gameScene = gameScene;
	this->handler = handler;
}

/** 
 * Method is used to detect collision. Use Bounding Box algorithm.
 */
void CollisionDetector::detectCollision()
{
	vector< boost::shared_ptr<SceneEntity> >* scene = gameScene->getWorldScene();

	unsigned int size = scene->size();

	for(unsigned int i = 0; i < size; ++i)
	{
		BoundingBox firstBox;
		firstBox.max =  scene->at(i).get()->getBoundingBox()->max;
		firstBox.min =  scene->at(i).get()->getBoundingBox()->min;
		firstBox.max += scene->at(i).get()->position;
		firstBox.min += scene->at(i).get()->position;
		
		bool firstHaveCollided = scene->at(i).get()->haveCollided;

		for(unsigned int j = 3; j < size; ++j)
		{
			if(i == j)
				continue;

			BoundingBox secondBox;
			bool secondHaveCollided = scene->at(j).get()->haveCollided;

			secondBox.max =  scene->at(j).get()->getBoundingBox()->max;
			secondBox.min =  scene->at(j).get()->getBoundingBox()->min;
			secondBox.max += scene->at(j).get()->position;
			secondBox.min += scene->at(j).get()->position;

      Faction atypeID_1 = scene->at(i).get()->faction;
      Faction atypeID_2 = scene->at(j).get()->faction;

      if(isCollision(firstBox,secondBox))
			{
				scene->at(i).get()->haveCollided = true;
				scene->at(j).get()->haveCollided = true;
				//handler->collisionCollection.push_back(Collision(scene->at(j).get()->position,i,j));
        Faction typeID_1 = scene->at(i).get()->faction;
        Faction typeID_2 = scene->at(j).get()->faction;

        handler->collisionCollection.push_back(
          createCollisionObject(typeID_1, typeID_2, scene->at(j).get()->position, i, j, gameScene));
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
	if((firstBox.min.x < secondBox.max.x) && (firstBox.max.x > secondBox.min.x) && 
		 (firstBox.min.y < secondBox.max.y) && (firstBox.max.y > secondBox.min.y) &&
     (firstBox.min.z < secondBox.max.z) && (firstBox.max.z > secondBox.min.z))
  {
		return true;
  }

	return false;
}

Collision* CollisionDetector::createCollisionObject(Faction firstTypeID, Faction secondTypeID, 
                                   const Vector3D& position, const int firstID, const int secondID,
                                   SceneManager* gameScene)
{
  if((firstTypeID == REBELION) && (secondTypeID == ASTEROID))
    return new CollisionXwingAsteroid(position, firstID, secondID, gameScene);
  
  if((firstTypeID == REBELION) && (secondTypeID == IMPERIAL))
    return new CollisionXwingImperialShip(position, firstID, secondID, gameScene);

  if((firstTypeID == REBELION) && (secondTypeID == LASER))
    return new CollisionXwingLaserBlast(position, firstID, secondID, gameScene);

  if((firstTypeID == IMPERIAL) && (secondTypeID == LASER))
    return new CollisionTieFighterLaserBlast(position, firstID, secondID, gameScene);

  if((firstTypeID == LASER) && (secondTypeID == LASER))
    return new CollisionLaserBlastLaserBlast(position, firstID, secondID, gameScene);

  return new CollisionObjectObject(position, firstID, secondID, gameScene);
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
 * Method is used to handle collision.
 */
void CollisionHandler::handleCollision()
{
	for(unsigned int i = 0; i < collisionCollection.size(); ++i)
	{
		collisionCollection[i].handleCollision();

    
    //this->gameScene->getWorldScene()->at(collisionCollection[i].firstID)->decreaseHP();
		//this->gameScene->getWorldScene()->at(collisionCollection[i].secondID)->decreaseHP();
		////this->gameScene->addSpecialEffect(collisionCollection[i].position);

		//this->gameScene->getWorldScene()->at(collisionCollection[i].firstID)->haveCollided = false;
		//this->gameScene->getWorldScene()->at(collisionCollection[i].firstID)->haveCollided = false;
	}

	collisionCollection.clear();

}

}
