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
		lastTowerPlaced = 0;
		lastSppedUp = -1000;
		lastTowerStateChange = 0;
		time = 0;
		isDanger = false;

		world = new World("Data/background.png");
		kernel = new Kernel("Data/kernel.png",Vector3D(75.0f,75.0f,0.0f),100);
		kernel->setSize(150,150);
		gameHud = new GameHud();

		gameHud->bars.push_back(new HealthBar(kernel));


	playerWii = new PlayerWii("Data/heroChar.png",Vector3D(400.0f,300.0f,0.0f));
	playerWii->setSize(200,200);
	playerPad = new PlayerPad("Data/heroChar.png",Vector3D(400.0f,300.0f,0.0f));
	playerPad->setSize(75,150);

		gameHud->bars.push_back(new HealthBar(playerWii));
		gameHud->bars.push_back(new HealthBar(playerPad));

		Sword* sword = new Sword("Data/sword.png",Vector3D(400.0f,300.0f,0.0f));
		playerWii->setSword(sword);

		generateWaves();
		audioManager = new AudioManager();
		audioManager->loadMusic("Data/Too many assumptions.mp3");
		audioManager->playMusic();

	}


	/**
	* Default destructor, free allocated memory and destroy current scene tree.
	*/
	SceneManager::~SceneManager()
	{
		delete playerWii;
		delete playerPad;
		delete world;
		delete kernel;
		delete gameHud;
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

	bool toDelete2( boost::shared_ptr<Tower> entity)
	{
		return entity.get()->isDead;
	}

	/**
	* Method used to update world scene.
	* @param	elapsedTime is time between frames in seconds.
	*/
	void SceneManager::updateScene(const float elapsedTime)
	{
		time += elapsedTime;

		world->updateEntity(elapsedTime);
		playerPad->updateEntity(elapsedTime);

		playerWii->updateEntity(elapsedTime);
		playerWii->getSword()->updateEntity(elapsedTime);

		worldScene.erase(remove_if(worldScene.begin(), worldScene.end(), toDelete),worldScene.end());
		semaphores.erase(remove_if(semaphores.begin(), semaphores.end(), toDelete2),semaphores.end());

		for(vector< boost::shared_ptr<SceneEntity> >::const_iterator i = worldScene.begin(); i != worldScene.end(); ++i)
		{
			(*i)->velocity = Vector3D(20,20,0);
			(*i)->updateEntity(elapsedTime);

		}
		for(vector< boost::shared_ptr<Tower> >::const_iterator i = semaphores.begin(); i != semaphores.end(); ++i)
			(*i)->updateEntity(elapsedTime);


	// players update
	if(playerPad->isDead || playerWii->isDead || kernel->isDead)
		exit(0);

	updateWave(elapsedTime);

	if(kernel->healthPoints <= 30)
		isDanger = true;
	else
		isDanger = false;

	if(isDanger)
		dangerMode(elapsedTime);


	//sprawdzanie kolizji testowe
	

		//enemy -> hero collision
		for(vector< boost::shared_ptr<SceneEntity> >::const_iterator i = worldScene.begin(); i != worldScene.end(); ++i)
		{
			if(sqrt(pow(playerWii->position.x - (*i)->position.x, 2) + pow(playerWii->position.y - (*i)->position.y,2)) < playerWii->collisionSphere.radius+(*i)->collisionSphere.radius-10)
				playerWii->damaged();

			if(playerWii->stompAttack)
			{
				(*i)->damaged(5);
				printf("STOMP\n");
			}

			if(sqrt(pow(playerWii->getSword()->position.x - (*i)->position.x, 2) + pow(playerWii->getSword()->position.y - (*i)->position.y,2)) < playerWii->getSword()->collisionSphere.radius+(*i)->collisionSphere.radius)
			{
				if(playerWii->isAttacking())
				{
					(*i)->damaged();
	

					
				gameHud->score[4] += 10;
	for(int i = 4; i >0; --i)
	{
		if(gameHud->score[i] >=10)
		{
			gameHud->score[i] = gameHud->score[i]%10;
			gameHud->score[i-1]++;
		}
	}

					gameHud->calculateScore();
				}
			}
		}

		for(vector< boost::shared_ptr<SceneEntity> >::const_iterator i = worldScene.begin(); i != worldScene.end(); ++i)
		{
			if(sqrt(pow(playerPad->position.x - (*i)->position.x, 2) + pow(playerPad->position.y - (*i)->position.y,2)) < playerPad->collisionSphere.radius+(*i)->collisionSphere.radius-10)
				playerPad->damaged();
		}

		Utils::Random random;
		

		for(vector< boost::shared_ptr<SceneEntity> >::const_iterator i = worldScene.begin(); i != worldScene.end(); ++i)
		{
			
			if(sqrt(pow(kernel->position.x - (*i)->position.x, 2) + pow(kernel->position.y - (*i)->position.y,2)) < playerPad->collisionSphere.radius+(*i)->collisionSphere.radius-10)
				kernel->damaged();
		}


		for(vector< boost::shared_ptr<SceneEntity> >::const_iterator i = worldScene.begin(); i != worldScene.end(); ++i)
		{
			for(vector< boost::shared_ptr<Tower> >::const_iterator it = semaphores.begin(); it != semaphores.end(); ++it)
			{
				if(sqrt(pow((*i)->position.x - (*it)->position.x, 2) + pow((*i)->position.y - (*it)->position.y,2)) < (*i)->collisionSphere.radius+(*it)->collisionSphere.radius-10)
				{
					(*i)->velocity.set(0.0f,0.0f,0.0f);
					(*it)->damaged();
				}
			}
		}


		// hack na to, aby nie mozna bylo postawic wiezyczki za czesto
		if((time - this->lastTowerPlaced < 1) && playerPad->buildTower)
		{
			playerPad->buildTower = false;
		}

		if((time - this->lastTowerStateChange < 0.1) && (playerPad->probieren_active || playerPad->verhogen_active))
		{
			playerPad->probieren_active = false;
			playerPad->verhogen_active = false;
		}

		// hack na to, aby nie mozna bylo postawic wiezyczki za czesto
		if((time - this->lastSppedUp < 10.0) && playerPad->speedUp_active)
		{
			playerPad->speedUp_active = false;
		}

		printf("%d \n", playerPad->isSpeededUp?1:0);

		// koniec przyspieszania
		if((time - this->lastSppedUp > 10.0) && playerPad->isSpeededUp)
		{
			playerPad->isSpeededUp = false;
			playerPad->velocity /= 2;
			
		}

	//	printf("time: %f lastspeededup: %f", time, this->lastSppedUp);
		if((time - this->lastSppedUp > 10.0) && playerPad->speedUp_active)
		{			
			playerPad->velocity *= 2;
			playerPad->isSpeededUp = true;
			playerPad->speedUp_active = false;
			this->lastSppedUp = time;
		}



		if((time - this->lastTowerStateChange > 0.1) && (playerPad->probieren_active || playerPad->verhogen_active))
		{
			
			for(vector< boost::shared_ptr<Game::Tower> >::const_iterator i = semaphores.begin(); i != semaphores.end(); ++i)
			{
				if(sqrt(pow(playerPad->position.x - ((*i)->position.x + 75.0f), 2) + pow(playerPad->position.y - ((*i)->position.y + 75.0f ),2)) < playerPad->collisionSphere.radius+(*i)->collisionSphere.radius-10)
				{

					(*i)->moving = true;

					if(playerPad->probieren_active)
					{
						(*i)->active = true;
						
					}
					if(playerPad->verhogen_active)
					{
						(*i)->active = false;
						
					}
				}
			}
			this->lastTowerStateChange = time;
			playerPad->probieren_active = false;
			playerPad->verhogen_active = false;
		}
	
		if(playerPad->buildTower && (time - this->lastTowerPlaced > 1) && gameHud->points >=100)
		{	

				gameHud->score[4] -= 10;
	for(int i = 4; i >0; --i)
	{
		if(gameHud->score[i] >=10)
		{
			gameHud->score[i] = gameHud->score[i]%10;
			gameHud->score[i-1]++;
		}
	}
			gameHud->calculateScore();

			playerPad->buildTower = false;

			Tower* tower = new Tower("Data/samafor.png",Vector3D(playerPad->position.x -75.0f,playerPad->position.y -75.0f,0.0f),100);
			tower->setSize(240,-75);
			//this->addEntityToScene(tower);
			semaphores.push_back(boost::shared_ptr<Game::Tower>(tower));
			gameHud->bars.push_back(new HealthBar(tower));

			this->lastTowerPlaced = time;	
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
	* Accessor to gameScene collection.
	* @return	scene collection.
	*/
	vector< boost::shared_ptr<Game::Tower> >* SceneManager::getSemaphores()
	{
		return &semaphores;
	}



	/**
	* Accessor to player object.
	* @return	pointer to player object.
	*/
	PlayerPad* SceneManager::getPlayer() const
	{
		return playerPad;
	}

	PlayerWii* SceneManager::getPlayerWii() const
	{
		return playerWii;
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

	void SceneManager::dangerMode(const float elapsedTime)
	{
		this->world->dangerKurwa = true;

		// danger text
		if(gameHud->danger)
		{

			if(gameHud->up)
			{
				if(gameHud->blendAccumulator < 1.0f)
					gameHud->blendAccumulator += elapsedTime;
				else
					gameHud->up = !gameHud->up;
			}

			if(!gameHud->up)
			{
				if(gameHud->blendAccumulator > 0.0f)
				{
					gameHud->blendAccumulator -= elapsedTime;
				}
				else
				{
					gameHud->up = !gameHud->up;
				}
			}
		}
	}

	void SceneManager::generateWaves()
	{
		waveAccumulator = 0.0f;
		currentWave = 0;

		waves.push_back(10);
		waves.push_back(13);
		waves.push_back(15);
		waves.push_back(13);
		waves.push_back(19);
	}

	void SceneManager::updateWave(const float elapsedTime)
	{
		waveAccumulator += elapsedTime;

		if(waveAccumulator >= 2.5f)
		{
			killKernel(currentWave);
			waveAccumulator = 0.0f;
			currentWave = currentWave % 5;
		}
	}

	void SceneManager::killKernel(const int waveId)
	{
		Enemy* enemy = NULL;
		for(unsigned int i = 0; i < waves.at(waveId); ++i)
		{
			float x = generator.getFloat(0.0f,1024.0f);
			float y = generator.getFloat(700.0f,1000.0f);

			enemy = new Enemy("Data/jellyred.png",Vector3D(x,y,0.0f));
			this->addEntityToScene(enemy);
			gameHud->bars.push_back(new HealthBar(enemy));
		}
	}
}