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
#include "AudioManager.hpp"
#include "..\Game\GameState.hpp"

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
private:
	std::vector< boost::shared_ptr<SceneEntity> > worldScene;
	AudioManager* audioManager;

public:
	SceneManager();
	~SceneManager();

	void updateScene(const float elapsedTime);
	void addEntityToScene(SceneEntity* newEntity);
	
	std::vector< boost::shared_ptr<SceneEntity> >* getWorldScene();
};

}
#endif
