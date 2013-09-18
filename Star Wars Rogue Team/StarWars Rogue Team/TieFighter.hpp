/**
 * File contains declaration of TieFighte class.
 * @file    TieFighter.hpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2011-12-20
 * @version 1.0
 */

#ifndef TIEFIGHTER_HPP
#define TIEFIGHTER_HPP

#include "SceneEntity.hpp"
#include "Shader.hpp"
#include "VBO.hpp"
#include "LaserBlast.hpp"
#include "ResourceManager/ResourceManager.hpp"
#include "EnemyPrototype.hpp"
#include "ShootedLasers.hpp"

using namespace resMan;
using namespace engine;

namespace game
{

/** 
 * Class represents one of player Enemy ship, Imperial TieFighter ship object. TieFighter like Xwing has two
 * laser blasters and is trying to destroy player Xwing. The only difference between these ships is endurance.
 */
class TieFighter : public SceneEntity, public EnemyPrototype
{
private:
	PResource mesh;
	PResource texture;
	VBO* entityVBO;
	Vector3D moveDirection;
	Quaternion* orientation;
	Shader shader;
	float blasterAccumulator;
	float angle;
	Vector3D* enemyPosition;
	Quaternion* enemyOrientation;
	/*std::vector<boost::shared_ptr<SceneEntity>>*/ShootedLasers* shootedLasers;

	TieFighter();
public:
	TieFighter(const char* meshFileName, const char* textureFileName, const Vector3D& position);
	~TieFighter();

	void updateEntity(const float elapsedTime);
	void renderEntity();

	virtual void setScene(/*std::vector<boost::shared_ptr<SceneEntity>>*/ ShootedLasers* shootedLasers);
	void setEnemyPosition(Vector3D* position);
	void setEnemyOrientation(Quaternion* orientation);
	virtual EnemyPrototype* clone();
};

}
#endif
