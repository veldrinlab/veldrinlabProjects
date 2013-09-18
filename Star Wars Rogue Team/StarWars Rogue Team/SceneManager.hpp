/**
 * File contains declaration of SceneManager class.
 * @file    SceneManager.h
 * @author  Szymon Jab³oñski
 * @date    2010-10-29
 * @version 1.0
 */

#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <boost/shared_ptr.hpp>
#include <vector>

#include "SceneEntity.hpp"
#include "SpecialFXManager.hpp"
#include "AudioManager.hpp"
#include "GameHud.hpp"
#include "Camera.hpp"
#include "Xwing.hpp"
#include "SkyBox.hpp"
#include "Terrain.hpp"
#include "ShootedLasers.hpp"

using namespace specialFx;
using namespace game;

namespace engine
{

/**
 * SceneManager class is used to build and store game scene structure. Class stores data of all world
 * entities and can update them by elapsedTime. SceneManager controls also SpecialFXManager which is used
 * to control Engine special effects. All game input signals are connected with instance of this class.
 * @remarks build scene tree/ choæ moze wystarczy nawet zwyczajna lista na auto_ptr.
 */
class SceneManager
{
private:
	std::vector< boost::shared_ptr<SceneEntity> > worldScene;
	SpecialFXManager* effectsManager;
	AudioManager* audioManager;
public:
	Camera* camera;
	Xwing* playerShip;
	SkyBox* skyBox;
	Terrain* terrain;

	GameHud* gameHud;
	ShootedLasers* shootedLasers;

	SceneManager();
	~SceneManager();

	void updateScene(const float elapsedTime);
	void updateSpecialEffects(const float elapsedTime);

	void addEntityToScene(SceneEntity* newEntity);
	
	std::vector< boost::shared_ptr<SceneEntity> >* getWorldScene();
	Xwing* getPlayerShip() const;
	Camera* getCamera() const;
	GameHud* getGameHud() const;
	SpecialFXManager* getSpecialFXManager() const;
	SkyBox* getSkyBox() const;
	Terrain* getTerrain() const;
};

}
#endif
