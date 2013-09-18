/**
 * File contains declaration of LaserBlast class. 
 * @file    LaseBlast.h
 * @author  Szymon "Veldrin" Jab³onski
 * @date    2010-11-26
 * @version 1.0
 */

#ifndef LASERBLAST_H
#define LASERBLAST_H

#include "SceneEntity.h"
#include "Shader.h"
#include "VBO.h"

/**
 * Class represents main characters SpaceShip weapon - LaserBlast which can be used to destroy enemt Invaders.
 * LasersBlasts are also 3D scene entietes, class extends SceneEntity.
 */
class LaserBlast : public SceneEntity
{
private:
	Mesh* mesh;
	Texture* texture;
	Vector3D moveDirection;
	VBO* entityVBO;
	Shader shader;

public:
	LaserBlast(const char* meshFileName, const char* textureFileName,const Vector3D& position, float diretion);
	~LaserBlast();

	void updateEntity(const float elapsedTime);
	void renderEntity();
	
};
#endif
