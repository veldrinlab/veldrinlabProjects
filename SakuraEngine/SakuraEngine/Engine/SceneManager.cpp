/**
 * File contains definition of SceneManager class.
 * @file    SceneManager.cpp
 * @author  Szymon Jab³oñski & Adam Sznajder
 * @date    2010-10-29
 * @version 1.0
 */

#include "SceneManager.hpp"

using namespace std;
using namespace boost;
using namespace Game;
using namespace Math;

namespace Engine
{

/**
 * Default constructor, creates current world scene. Used by LevelManager class.
 */
SceneManager::SceneManager()
{
	audioManager = new AudioManager();
}

/**
 * Default destructor, free allocated memory and destroy current scene tree.
 */
SceneManager::~SceneManager()
{
	delete audioManager;
}

/**
 * Function is to used to check if entity is dead.
 * @param	entity is pointer to Entity object.
 * @return	dead or not.
 */
bool toDelete( boost::shared_ptr<SceneEntity> entity)
{
	return entity.get()->isDead;
}

/**
 * Method used to update world scene.
 * @param	elapsedTime is time between frames in seconds.
 */
void SceneManager::updateScene(const float elapsedTime)
{

}

/**
 * Method is used to add entity to scene.
 * @param	newEntity is pointer to new entity object.
 */
void SceneManager::addEntityToScene(SceneEntity* newEntity)
{
	worldScene.push_back(boost::shared_ptr<SceneEntity>(newEntity));
}

/**
 * Accessor to gameScene collection.
 * @return	scene collection.
 */
vector< boost::shared_ptr<SceneEntity> >* SceneManager::getWorldScene()
{
	return &worldScene;
}
}