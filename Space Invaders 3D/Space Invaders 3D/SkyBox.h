/**
 * File contains declaration of SkyBox class.
 * @file    SkyBox.h
 * @author  Szymon Jab³oñski
 * @date    2010-10-16
 * @version 1.0
 */

#ifndef SKYBOX_H
#define SKYBOX_H

#include "SceneEntity.h"
#include "Shader.h"

/**
 * SkyBox class represents one of major World element - background that make scene look bigger and more realistic.
 * SkyBox object will be used in every game level that occurs on Earth. In other situaltion, there is another type
 * of scene background - SkyDome. SkyBox is simple cube with textured inner faces, Engine Camera is always set inside
 * the cube that reprsents SkyBox.
 * @remarks use ResourceManager
 */
class SkyBox : public SceneEntity
{
private:
	Texture* front;
	Texture* back;
	Texture* top;
	Texture* bottom;
	Texture* left;
	Texture* right;
	GLuint skyBoxList;
	float width;
	float height;
	float length;
	float centerX;
	float centerY;
	float centerZ;

	void buildSkyBoxList();
	Shader shader;

public:
	SkyBox(float centerX, float centerY, float cenetrZ, float width, float height, float length);
	~SkyBox();

	void renderEntity();
	void updateEntity(const float elapsedTime) {}
};
#endif
