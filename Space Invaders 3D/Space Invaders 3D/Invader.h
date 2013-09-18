/**
 * File contains declaration of Invader class. 
 * @file    Invader.h
 * @author  Szymon "Veldrin" Jab³onski
 * @date    2010-11-26
 * @version 1.0
 */

#ifndef INVADER_H
#define INVADER_H

#include <vector>

#include "SceneEntity.h"
#include "LaserBlast.h"
#include "Shader.h"
#include "VBO.h"

/**
 * Class represents game character main enemy - alien Ivaders. Theres is three type of Invaders,
 * with different amount of health points. Invaders are attacking from universe - moving along to
 * zAxis with sinusoid movement. Invaders is one of 3D scene objects, extends SceneEntity.
 */
class Invader : public SceneEntity
{
private:
	Mesh* mesh1;
	Mesh* mesh2;
	int actualMesh;
	Texture* texture;
	VBO* entityVBO1;
	VBO* entityVBO2;
	Shader shader;
	int rotate;

	std::vector<Vector3D>* shootedLasers;

	Vector3D moveDirection;
	float animationAccumulator;
	float shootTimeAccumulator;

public:
	Invader(const char* meshFileName,const char* meshFileName2,const char *textureFileName2,const char* textureFileName, const Vector3D& position, std::vector<Vector3D>* shootedLasers);
	~Invader();

	void updateEntity(const float elapsedTime);
	void renderEntity();
};
#endif
