/**
 * File contains definition of SceneManager class.
 * @file    SceneManager.cpp
 * @author  Szymon Jab³oñski & Adam Sznajder
 * @date    2010-10-29
 * @version 1.0
 */

#include "SceneManager.hpp"
#include "LevelManager.hpp"
#include "EnemyPrototype.hpp"
#include "Configuration.hpp"
#include <vector>

using namespace std;
using namespace boost;

namespace engine
{

/**
 * Default constructor, creates current world scene. Used by LevelManager class.
 */
SceneManager::SceneManager()
{
	terrain = NULL;

	shootedLasers = new ShootedLasers();
	camera = new Camera();
	camera->initCamera();
	playerShip = new Xwing(camera,"Data/xWing.vel","Data/xWingTexture.jpg");
	playerShip->setScene(this);

	Configuration* config = Configuration::getInstance();
	LevelManager* levelManager = new LevelManager(config->getLevel());
	levelManager->prepareLevelScene(this);

	effectsManager = new SpecialFXManager();
	effectsManager->addSpecialEffect(new Lighting());
	effectsManager->addSpecialEffect(new MotionBlur(0.0f));
	//effectsManager->addSpecialEffect(new Fog());
	gameHud = new GameHud();
	//audioManager = new AudioManager();
	//audioManager->loadMusic("Data/theme.mp3");
	//audioManager->playMusic();
}

/**
 * Default destructor, free allocated memory and destroy current scene tree.
 */
SceneManager::~SceneManager()
{
	delete gameHud;
	delete effectsManager;
	delete audioManager;
}

/**
 * Method used to update world scene.
 * @param	elapsedTime is time between frames in seconds.
 */
void SceneManager::updateScene(const float elapsedTime)
{
	//update sta³ych czynnikow
	camera->updateEntity(elapsedTime);
	skyBox->updateEntity(elapsedTime);
	if(terrain != NULL)
		terrain->updateEntity(elapsedTime);

	playerShip->updateEntity(elapsedTime);


	vector< boost::shared_ptr<SceneEntity> > actualWorldScene;

	for(vector< boost::shared_ptr<SceneEntity> >::const_iterator i = worldScene.begin(); i != worldScene.end(); ++i)
	{
		if(!(*i)->isDead)
		{
			actualWorldScene.push_back((*i));
			(*i)->updateEntity(elapsedTime);
		}
	}

	this->worldScene = actualWorldScene;
	updateSpecialEffects(elapsedTime);


	for(vector< boost::shared_ptr<SceneEntity> >::const_iterator i = shootedLasers->getShootedLasers()->begin(); i != shootedLasers->getShootedLasers()->end(); ++i)
		worldScene.push_back((*i));

	shootedLasers->getShootedLasers()->clear();


	////tutaj wykrywamy kolizcje chwilowo

	//BoundingBox player;
	//player.max = playerShip->getBoundingBox()->max + playerShip->position;
	//player.min = playerShip->getBoundingBox()->min + playerShip->position;


	//for(vector< boost::shared_ptr<SceneEntity> >::const_iterator i = worldScene.begin(); i != worldScene.end(); ++i)
	//{
	//	BoundingBox enemy;
	//	enemy.max = (*i)->getBoundingBox()->max + (*i)->position;
	//	enemy.min = (*i)->getBoundingBox()->min + (*i)->position;
	//	
	//	if((player.min.x < enemy.max.x) && (player.max.x > enemy.min.x) && 
	//	   (player.min.y < enemy.max.y) && (player.max.y > enemy.min.y) &&
 //          (player.min.z < enemy.max.z) && (player.max.z > enemy.min.z))
	//	{
	//		printf("Kolizaj! player \n");
	//		playerShip->decreaseHP();
	//		(*i)->decreaseHP();
	//	}
	//}

	////reszta obiektow
	//for(vector< boost::shared_ptr<SceneEntity> >::const_iterator i = worldScene.begin(); i != worldScene.end(); ++i)
	//{
	//	BoundingBox first;
	//	first.max = (*i)->getBoundingBox()->max + (*i)->position;
	//	first.min = (*i)->getBoundingBox()->min + (*i)->position;

	//	for(vector< boost::shared_ptr<SceneEntity> >::const_iterator j =  i; j != worldScene.end(); ++j)
	//	{
	//		BoundingBox second;
	//		second.max = (*j)->getBoundingBox()->max + (*j)->position;
	//		second.min = (*j)->getBoundingBox()->min + (*j)->position;

	//		if((first.min.x < second.max.x) && (first.max.x > second.min.x) && 
	//	   (first.min.y < second.max.y) && (first.max.y > second.min.y) &&
 //          (first.min.z < second.max.z) && (first.max.z > second.min.z))
	//	{
	//		printf("Kolizja obiekty\n!");
	//		(*i)->decreaseHP();
	//		(*j)->decreaseHP();
	//	}
	//	}

	//}



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
 * Method used to call SpecialFXManager to update special effects that must be updated like Motion Blur
 * or Particle System.
 */
void SceneManager::updateSpecialEffects(const float elapsedTime)
{
	effectsManager->updateEffects(elapsedTime);
}

/**
 * Accessor to gameScene collection.
 * @return	scene collection.
 */
vector< boost::shared_ptr<SceneEntity> >* SceneManager::getWorldScene()
{
	return &worldScene;
}

/**
 * Accessor to player X-wing object.
 * @return	player X-wing object.
 */
Xwing* SceneManager::getPlayerShip() const
{
	return playerShip;
}

/**
 * Accessor to scene camera object.
 * @return	scene camera object.
 */
Camera* SceneManager::getCamera() const
{
	return camera;
}

/**
 * Accessor to game hud.
 * @return	game hud.
 */
GameHud* SceneManager::getGameHud() const
{
	return gameHud;
}

/**
 * Accessor to SoecialFXManager.
 * @return	pointer to SpecialFXManager object.
 */
SpecialFXManager* SceneManager::getSpecialFXManager() const
{
	return effectsManager;
}

SkyBox* SceneManager::getSkyBox() const
{
	return skyBox;
}

Terrain* SceneManager::getTerrain() const
{
	return terrain;
}

}

