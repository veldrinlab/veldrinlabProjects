/**
 * File contains declaration of SceneManager class.
 * @file    SceneManager.hpp
 * @author  Szymon Jab³oñski
 * @date    2010-10-29
 * @version 1.0
 */

#ifndef SCENEMANAGER_HPP
#define SCENEMANAGER_HPP

#include <boost/shared_ptr.hpp>
#include <vector>
#include <algorithm>

#include "SceneEntity.hpp"
#include "../Game/GameHud.hpp"
#include "../Game/World.hpp"
#include "../Game/Enemy.hpp"
#include "../Game/PlayerPad.hpp"
#include "../Game/PlayerWii.hpp"
#include "../Game/Kernel.hpp"
#include "../Game/Tower.hpp"

#include "AudioManager.hpp"
#include "../Utils/Random.hpp"


namespace Engine
{

struct Wave
{
	unsigned int waveId;
	unsigned int enemyAmount;
	std::vector<Game::Enemy*> enemies;

};

}


namespace Engine
{

/**
 * SceneManager class is used to build and store game scene structure. Class stores data of all world
 * entities and can update them by elapsedTime. SceneManager controls also SpecialFXManager which is used
 * to control Engine special effects. All game input signals are connected with instance of this class.
 * @remarks build scene tree/ choæ moze wystarczy nawet zwyczajna lista na auto_ptr.
 */
class SceneManager
{
public:
	Game::PlayerPad* player;
	Game::World* world;
	Game::Kernel* kernel;
	Game::GameHud* gameHud;

	Game::PlayerPad* playerPad;
	Game::PlayerWii* playerWii;


	AudioManager* audioManager;

	bool isDanger;
	float lastTowerPlaced;
	float lastSppedUp;
	float lastTowerStateChange;
	float time;

	std::vector< boost::shared_ptr<SceneEntity> > worldScene; // enemies
	std::vector< boost::shared_ptr<Game::Tower> > semaphores; 


	SceneManager();
	~SceneManager();

	void updateScene(const float elapsedTime);
	void addEntityToScene(SceneEntity* newEntity);
	
	std::vector< boost::shared_ptr<SceneEntity> >* getWorldScene();
	std::vector< boost::shared_ptr<Game::Tower> >* getSemaphores();
	Game::PlayerPad* getPlayer() const;
	Game::PlayerWii* getPlayerWii() const;
	Game::World* getWorld() const;
	Game::GameHud* getGameHud() const;


	// Wave Manager

	Utils::Random generator;
	float waveAccumulator;
	int currentWave;

	std::vector<int> waves;

	void dangerMode(const float elapsedTime);
	void generateWaves();
	void updateWave(const float elapsedTime);
	void killKernel(const int waveId);

};

}
#endif
