/**
 * File contains declaration of LaserBlast class. 
 * @file    LaseBlast.hpp
 * @author  Szymon "Veldrin" Jab³onski
 * @date    2010-11-26
 * @version 1.0
 */

#ifndef LASERBLAST_HPP
#define LASERBLAST_HPP

#include "SceneEntity.hpp"
#include "Shader.hpp"
#include "VBO.hpp"
#include "ResourceManager/ResourceManager.hpp"

using namespace math;
using namespace resMan;
using namespace engine;

namespace game
{

/**
 * Class represents main characters SpaceShip weapon - LaserBlast which can be used to destroy enemy Invaders.
 * LasersBlasts are also 3D scene entietes, class extends SceneEntity.
 */
class LaserBlast : public SceneEntity
{
private:
	PResource mesh;
	PResource texture;
	VBO* entityVBO;
	int id;
	Shader shader;
	float lifeTime;
	Vector3D moveDirection;
	Quaternion orientation;

public:
	LaserBlast(const char* meshFileName, const char* textureFileName,const Vector3D& position, const Vector3D& diretion, const Quaternion& orientation,int id);
	~LaserBlast();

	void updateEntity(const float elapsedTime);
	void renderEntity();
	
};

}
#endif
