/**
 * File contains declaration of LevelManager class. 
 * @file    LevelManager.hpp
 * @author  Adam Sznajder
 * @date    2011-01-08
 * @version 1.0
 */

#ifndef LEVEL_MANAGER_HPP
#define LEVEL_MANAGER_HPP

#include "Level.hpp"
#include "EnemyPrototypeFactory.hpp"
#include "EnemyPrototype.hpp"

#include "StarDestroyer.hpp"
#include "TieFighter.hpp"
#include "Asteroid.hpp"
#include "ATST.hpp"
#include "Terrain.hpp"
#include "SkyBox.hpp"

#include "SceneManager.hpp"
#include "SceneEntity.hpp"

namespace game
{

/**
 * LevelManager is responsible for creating certain objects depending on current Level.
 */
class LevelManager
{
private:
	Level currentLevel;
public:
	LevelManager(Level initLevel);
	~LevelManager();
	void prepareLevelScene(SceneManager* sceneManager);
	void nextLevel();
	Level getLevel();
};

}
#endif
