/**
 * File contains declaration of StarDestroyer class.
 * @file    StarDestroyer.hpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2010-12-18
 * @version 1.0
 */

#ifndef STARDESTROYER_HPP
#define STARDESTROYER_HPP

#include "SceneEntity.hpp"
#include "Shader.hpp"
#include "VBO.hpp"
#include "LaserBlast.hpp"
#include "ResourceManager/ResourceManager.hpp"
#include "EnemyPrototype.hpp"
#include "ShootedLasers.hpp"

using namespace math;
using namespace resMan;
using namespace engine;

namespace game 
{

/**
 * Class represents one of the player's enemies, Imperial Star Destroyer ship. Object can't be destroyed, it is
 * part of the game Intro sequence and in-game level environment object.
 */
class StarDestroyer : public SceneEntity, public EnemyPrototype
{
private:
	PResource mesh;
	PResource texture;
	VBO* entityVBO;
	Vector3D moveDirection;
	Quaternion orientation;
	Shader shader;
	float blasterAccumulator;
	Vector3D* enemyPosition;
	Quaternion* enemyOrientation;
	/*std::vector<boost::shared_ptr<SceneEntity>>*/ ShootedLasers* shootedLasers;
	
public:
	StarDestroyer(const char* meshFileName, const char* textureFileName,const Vector3D& moveDirection,const Quaternion& orientation);
	~StarDestroyer();

	void updateEntity(const float elapsedTime);
	void renderEntity();
	virtual void setScene(/*std::vector<boost::shared_ptr<SceneEntity>>*/ShootedLasers* shootedLasers);
	void setEnemyPosition(Vector3D* position);
	void setEnemyOrientation(Quaternion* orientation);
	virtual EnemyPrototype* clone();
};

}
#endif
