/**
 * File contains definition of SceneManager class.
 * @file    SceneManager.cpp
 * @author  Szymon Jab³oñski
 * @date    2010-10-29
 * @version 1.0
 */

#include "SceneManager.h"

using namespace std;
using namespace boost;

/**
 * Default constrcutor, creates current world scene. Used by LevelManager class.
 */
SceneManager::SceneManager(GameState* gameState)
{
	playerShip = new SpaceShip("Data/tie.vel","Data/tie.jpg",gameState);
	playerShip->setWorldScene(&(this->worldScene));
	worldScene.push_back(boost::shared_ptr<SceneEntity>(new SkyBox(0, 0, 0, 200, 200, 200)));
	worldScene.push_back(boost::shared_ptr<SceneEntity>(new Camera(Vector3D(0.0f,30.0f,50.0f))));
	worldScene.push_back(boost::shared_ptr<SceneEntity>(playerShip));
	initializeInvaders();

	gameHud = new GameHud();

	fog = new Fog();
	fog->initializeEffect();
	lighting = new Lighting();
	lighting->initializeEffect();
}

/**
 * Default destructor, free allocated memory and destroy current worlds scene.
 */
SceneManager::~SceneManager()
{
	delete gameHud;
	delete fog;
	delete lighting;
}

/**
 * Method used to update world scene.
 * @param	elapsedTime is time between frames in seconds.
 */
void SceneManager::updateScene(const float elapsedTime)
{
	vector<boost::shared_ptr<SceneEntity>> actualWorldScene;
	vector<boost::shared_ptr<ParticleSystem>> actualSpecialEffects;

	for(vector<boost::shared_ptr<SceneEntity>>::const_iterator i = worldScene.begin(); i != worldScene.end(); ++i)
	{
		if(!(*i)->isDead)
		{
			actualWorldScene.push_back((*i));
			(*i)->updateEntity(elapsedTime);
		}
	}

	for(vector<boost::shared_ptr<ParticleSystem>>::const_iterator i=specialEffects.begin(); i!=specialEffects.end(); ++i)
	{
		if(!(*i)->isEnd())
		{
			actualSpecialEffects.push_back((*i));
			(*i)->update(elapsedTime);
		}
	}

	this->worldScene = actualWorldScene;
	this->specialEffects = actualSpecialEffects;

	addShootedLasersToScene();
	gameHud->setLifeAmount(getPlayerShip()->healthPoints);


	//update lighting
	lighting->changeSpectrum();

}

/**
 * Method is used to initialize invaders.
 */
void SceneManager::initializeInvaders()
{
	float startX = -30.0f;
	float startZ = -80.0f;
	int counter = 0;

	for(int i = 0; i < 5; ++i)
		for(int j = 0; j < 3; ++j)
		{
			Invader* invader =  NULL;

			if(counter >=10)
			{
				invader = new Invader("Data/alien2-2.vel","Data/alien2-1.vel","Data/alien2tex.jpg","Data/alien2tex.jpg",Vector3D(startX+i*15,0.0f,startZ-j*25),&shootedLasers);
			}
			else
			{
				invader = new Invader("Data/alien1-2.vel","Data/alien1-1.vel","Data/alien1tex.jpg","Data/alien1tex.jpg",Vector3D(startX+i*15,0.0f,startZ-j*25),&shootedLasers);
			}

			++counter;
			worldScene.push_back(boost::shared_ptr<SceneEntity>(invader));
		}
}

/**
 * Method is used to add lasrs shooted by Inavaders to scene.
 */
void SceneManager::addShootedLasersToScene()
{
	for(vector<Vector3D>::const_iterator i = shootedLasers.begin(); i != shootedLasers.end(); ++i)
		worldScene.push_back(boost::shared_ptr<SceneEntity>(new LaserBlast("Data/laser.vel","Data/laser2.bmp",(*i) ,1.0f)));

	this->shootedLasers.clear();

}

/**
 * Method is used to add special effects to scene.
 * @param	position is effect origin vector.
 */
void SceneManager::addSpecialEffect(const Vector3D& position)
{
	specialEffects.push_back(boost::shared_ptr<ParticleSystem>(new ExplosionEffect(position)));
	specialEffects.push_back(boost::shared_ptr<ParticleSystem>(new DestroyEffect(position)));
	gameHud->increasePoints();

}

/**
 * Accessor to gameScene collection.
 * @return	scene collection.
 */
vector<boost::shared_ptr<SceneEntity>>* SceneManager::getWorldScene()
{
	return &worldScene;
}

/**
 * Accessor to gameScene special effects collection.
 * @return	scene special effects collection.
 */
vector<boost::shared_ptr<ParticleSystem>>* SceneManager::getSpecialEffects()
{
	return &specialEffects;
}

/**
 * Accessor to player ship object.
 * @return	player ship object.
 */
SpaceShip* SceneManager::getPlayerShip() const
{
	return playerShip;
}

/**
 * Accessor to game hud object.
 * @return	game hud object
 */
GameHud* SceneManager::getGameHud() const
{
	return gameHud;
}

/**
 * Accessor to Lights object.
 * @return	lights object.
 */
Lighting* SceneManager::getLightings() const
{
	return lighting;
}