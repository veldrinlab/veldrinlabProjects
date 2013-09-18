/**
 * File contains declaration of SkyBox class.
 * @file    SkyBox.hpp
 * @author  Szymon Jab³oñski
 * @date    2010-10-16
 * @version 1.0
 */

#ifndef SKYBOX_HPP
#define SKYBOX_HPP

#include <SDL.h>
#include <SDL_opengl.h> 
#include <GL/gl.h>

#include "SceneEntity.hpp"
#include "ResourceManager/ResourceManager.hpp"

using namespace std;
using namespace resMan;

namespace engine
{

/**
 * SkyBox class represents one of the major World elements - background that makes scene look bigger and more realistic.
 * SkyBox object will be used in every game level that occurs on Earth. In other situation, there is another type
 * of scene background - SkyDome. SkyBox is simple cube with textured inner faces, Engine Camera is always set inside
 * the cube that represents SkyBox.
 * @remarks
 */
class SkyBox : public SceneEntity
{
private:
	PResource front;
	PResource back;
	PResource top;
	PResource bottom;
	PResource left;
	PResource right;
	GLuint skyBoxList;
	Vector3D center;
	Vector3D dimmension;

	void buildSkyBoxList();
public:
	SkyBox(const Vector3D& center, const Vector3D& dimmension, const int levelID);
	~SkyBox();

	void renderEntity();
	void updateEntity(const float elapsedTime) {}
};

}
#endif
