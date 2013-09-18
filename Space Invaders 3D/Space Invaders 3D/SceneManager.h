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

#include "SkyBox.h"
#include "Camera.h"
#include "Fog.h"
#include "Lighting.h"
#include "SpaceShip.h"
#include "Invader.h"
#include "GameHud.h"
#include "GameState.h"

#include "DestroyEffect.h"
#include "ExplosionEffect.h"

/**
 * SceneManager class is used to build and store game scene structure. Class stores data of all world
 * entities and can update them by elapsedTime.  All game input signals are connected with instance of this class.
 * @remarks build scene tree/ choæ moze wystarczy nawet zwyczajna lista na auto_ptr.
 */
class SceneManager
{
private:
	std::vector<boost::shared_ptr<SceneEntity>> worldScene;
	SpaceShip* playerShip;
	GameHud* gameHud;
	std::vector<Vector3D> shootedLasers;
	std::vector<boost::shared_ptr<ParticleSystem>> specialEffects;
	Fog *fog;
	Lighting *lighting;

public:
	SceneManager(GameState *gameState);
	~SceneManager();

	void updateScene(const float elapsedTime);
	void initializeInvaders();
	void addShootedLasersToScene();
	void addSpecialEffect(const Vector3D& position);

	std::vector<boost::shared_ptr<SceneEntity>>* getWorldScene();
	std::vector<boost::shared_ptr<ParticleSystem>>* getSpecialEffects();
	SpaceShip* getPlayerShip() const;
	GameHud* getGameHud() const;
	Lighting* getLightings() const;
};
#endif
