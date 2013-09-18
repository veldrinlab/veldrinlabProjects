/**
 * File contains declaration of AT-ST enemy class.
 * @file    ATST.hpp
 * @author  Szymon Jab³oñski
 * @date    2011-01-07
 * @version 1.0
 */

#ifndef ATST_HPP
#define ATST_HPP

#include "SceneEntity.hpp"
#include "LaserBlast.hpp"
#include "Shader.hpp"
#include "VBO.hpp"
#include "EnemyPrototype.hpp"
#include "ResourceManager/ResourceManager.hpp"
#include "ResourceManager/Mesh.hpp"
#include "ResourceManager/Texture.hpp"
#include "ShootedLasers.hpp"

using namespace resMan;

namespace game
{

/**
 * Class represents one of enemy Imperial units - AT-ST mesh. It is static enemy which player need to
 * destroy on Battle of Hoth. Rendering use Vertex Buffer Object and bilboarding. When player ship is 
 * near enough, enemy Unit will shoot laser blast.
 */
class ATST: public SceneEntity, public EnemyPrototype
{
private:
	PResource mesh;
	PResource texture;
	Shader shader;
	VBO* entityVBO;
	float blasterAccumulator;
	Vector3D* enemyPosition;
	Quaternion* enemyOrientation;
	ShootedLasers* shootedLasers;

	ATST();
public:
	ATST(const char* meshFileName, const char* textureFileName, const Vector3D& position);
	~ATST();

	void updateEntity(const float elapsedTime);
	void renderEntity();
	void setEnemyPosition(Vector3D* position);
	void setEnemyOrientation(Quaternion* orientation);
	virtual EnemyPrototype* clone();
	virtual void setScene(ShootedLasers* shootedLasers);
};

}
#endif
