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
	world = new World("Data/level1.png");
	player = new Player("Data/heroChar.png",Vector3D(400.0f,300.0f,0.0f));

	Sword* sword = new Sword("Data/sword.png",Vector3D(400.0f,300.0f,0.0f));
	player->setSword(sword);

	this->addEntityToScene(new Enemy("Data/jellyred.png",Vector3D(200.0f,50.0f,0.0f),player));
	this->addEntityToScene(new Enemy("Data/jellyred.png",Vector3D(800.0f,1000.0f,0.0f),player));
	this->addEntityToScene(new Enemy("Data/jellyred.png",Vector3D(0.0f,0.0f,0.0f),player));
	this->addEntityToScene(new Enemy("Data/jellyred.png",Vector3D(-200.0f,-50.0f,0.0f),player));
	this->addEntityToScene(new Enemy("Data/jellyred.png",Vector3D(800.0f,350.0f,0.0f),player));
	this->addEntityToScene(new Enemy("Data/jellyred.png",Vector3D(-200.0f,-450.0f,0.0f),player));
	this->addEntityToScene(new Enemy("Data/jellyred.png",Vector3D(-300.0f,-150.0f,0.0f),player));
	this->addEntityToScene(new Enemy("Data/jellyred.png",Vector3D(700.0f,1200.0f,0.0f),player));
	this->addEntityToScene(new Enemy("Data/jellyred.png",Vector3D(1200.0f,50.0f,0.0f),player));
	this->addEntityToScene(new Enemy("Data/jellyred.png",Vector3D(0.0f,150.0f,0.0f),player));
	this->addEntityToScene(new Enemy("Data/jellyred.png",Vector3D(800.0f,0.0f,0.0f),player));
	this->addEntityToScene(new Enemy("Data/jellyred.png",Vector3D(0.0f,600.0f,0.0f),player));
	this->addEntityToScene(new Enemy("Data/jellyred.png",Vector3D(-20.0f,650.0f,0.0f),player));
	this->addEntityToScene(new Enemy("Data/jellyred.png",Vector3D(820.0f,650.0f,0.0f),player));
	this->addEntityToScene(new Enemy("Data/jellyred.png",Vector3D(800.0f,50.0f,0.0f),player));
	this->addEntityToScene(new Enemy("Data/jellyred.png",Vector3D(0.0f,300.0f,0.0f),player));
	this->addEntityToScene(new Enemy("Data/jellyred.png",Vector3D(750.0f,500.0f,0.0f),player));
	this->addEntityToScene(new Enemy("Data/jellyred.png",Vector3D(200.0f,50.0f,0.0f),player));

	waveAccumulator = 0.0f;

	gameHud = new GameHud();
	audioManager = new AudioManager();
	audioManager->loadMusic("Data/theme.mid");
	audioManager->playMusic();
}

/**
 * Default destructor, free allocated memory and destroy current scene tree.
 */
SceneManager::~SceneManager()
{
	delete player;
	delete world;
	delete gameHud;
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
	waveAccumulator += elapsedTime;

	world->updateEntity(elapsedTime);
	player->updateEntity(elapsedTime);
	player->getSword()->updateEntity(elapsedTime);

	worldScene.erase(remove_if(worldScene.begin(), worldScene.end(), toDelete),worldScene.end());

	for(vector< boost::shared_ptr<SceneEntity> >::const_iterator i = worldScene.begin(); i != worldScene.end(); ++i)
			(*i)->updateEntity(elapsedTime);

	//sprawdzanie kolizji testowe

	//enemy -> hero collision
	for(vector< boost::shared_ptr<SceneEntity> >::const_iterator i = worldScene.begin(); i != worldScene.end(); ++i)
	{
		if(sqrt(pow(player->position.x - (*i)->position.x, 2) + pow(player->position.y - (*i)->position.y,2)) < player->collisionSphere.radius+(*i)->collisionSphere.radius-10)
			player->damaged();

		if(sqrt(pow(player->getSword()->position.x - (*i)->position.x, 2) + pow(player->getSword()->position.y - (*i)->position.y,2)) < player->getSword()->collisionSphere.radius+(*i)->collisionSphere.radius)
		{
			if(player->isAttacking())
			{
				(*i)->damaged();
				gameHud->increaseScore();
			}
		}

	}

	if(player->isDead)
		exit(0);

	this->gameHud->setHpAmount(player->getHealthPoints());
	this->gameHud->setMpAmount(player->getMana());

	//WaveManager
	if(waveAccumulator >= 10.0f)
	{
		waveAccumulator = 0.0f;
		this->addEntityToScene(new Enemy("Data/jellyred.png",Vector3D(200.0f,50.0f,0.0f),player));
		this->addEntityToScene(new Enemy("Data/jellyred.png",Vector3D(800.0f,1000.0f,0.0f),player));
		this->addEntityToScene(new Enemy("Data/jellyred.png",Vector3D(0.0f,0.0f,0.0f),player));
		this->addEntityToScene(new Enemy("Data/jellyred.png",Vector3D(-200.0f,-50.0f,0.0f),player));
		this->addEntityToScene(new Enemy("Data/jellyred.png",Vector3D(800.0f,350.0f,0.0f),player));
		this->addEntityToScene(new Enemy("Data/jellyred.png",Vector3D(-200.0f,-450.0f,0.0f),player));
		this->addEntityToScene(new Enemy("Data/jellyred.png",Vector3D(-300.0f,-150.0f,0.0f),player));
		this->addEntityToScene(new Enemy("Data/jellyred.png",Vector3D(700.0f,1200.0f,0.0f),player));
		this->addEntityToScene(new Enemy("Data/jellyred.png",Vector3D(1200.0f,50.0f,0.0f),player));
		this->addEntityToScene(new Enemy("Data/jellyred.png",Vector3D(0.0f,150.0f,0.0f),player));
		this->addEntityToScene(new Enemy("Data/jellyred.png",Vector3D(800.0f,0.0f,0.0f),player));
		this->addEntityToScene(new Enemy("Data/jellyred.png",Vector3D(0.0f,600.0f,0.0f),player));
		this->addEntityToScene(new Enemy("Data/jellyred.png",Vector3D(-20.0f,650.0f,0.0f),player));
		this->addEntityToScene(new Enemy("Data/jellyred.png",Vector3D(820.0f,650.0f,0.0f),player));
		this->addEntityToScene(new Enemy("Data/jellyred.png",Vector3D(800.0f,50.0f,0.0f),player));
		this->addEntityToScene(new Enemy("Data/jellyred.png",Vector3D(0.0f,300.0f,0.0f),player));
		this->addEntityToScene(new Enemy("Data/jellyred.png",Vector3D(750.0f,500.0f,0.0f),player));
		this->addEntityToScene(new Enemy("Data/jellyred.png",Vector3D(200.0f,50.0f,0.0f),player));
	}
	
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

/**
 * Accessor to player object.
 * @return	pointer to player object.
 */
Player* SceneManager::getPlayer() const
{
	return player;
}

/**
 * Accessor to world object.
 * @return	pointer to world object.
 */
World* SceneManager::getWorld() const
{
	return world;
}

/**
 * Accessor to game hud interface/.
 * @return	pointer to interface object.
 */
GameHud* SceneManager::getGameHud() const
{
	return gameHud;
}

}