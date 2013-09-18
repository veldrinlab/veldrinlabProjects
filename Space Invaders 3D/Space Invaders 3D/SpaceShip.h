/**
 * File contains declaration of SpaceShip class. 
 * @file    SpaceShip.h
 * @author  Szymon "Veldrin" Jab³onski
 * @date    2010-11-26
 * @version 1.0
 */

#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <boost/shared_ptr.hpp>
#include <vector>

#include "LaserBlast.h"
#include "GameState.h"

#include "Shader.h"
#include "VBO.h"

/**
 * Class represents main game object - SpaceShip which is controlled by player. User can controll ship
 * in x/zAxis and shoot lasers to kill invaders. SpaceShip is one of 3D scene objects, extends SceneEntity.
 */
class SpaceShip : public SceneEntity
{
private:
	Mesh* mesh;
	Texture* texture;
	Vector3D moveDirection;
	float blasterAccumulator;
	std::vector<boost::shared_ptr<SceneEntity>>* worldScene;
	GameState* gameState;

	VBO* entityVBO;
	Shader shader;

public:
	SpaceShip(const char* meshFileName, const char *textureFileName, GameState* gameState);
	~SpaceShip();

	void updateEntity(const float elapsedTime);
	void renderEntity();

	void wKeyPressed();
	void sKeyPressed();
	void aKeyPressed();
	void dKeyPressed();
	void spaceKeyPressed();

	void setWorldScene(std::vector<boost::shared_ptr<SceneEntity>>* worldScene);

};
#endif
