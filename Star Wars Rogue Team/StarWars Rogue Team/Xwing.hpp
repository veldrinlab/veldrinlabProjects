/**
 * File contains declaration of X-wing class.
 * @file    Xwing.hpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2010-12-21
 * @version 1.0
 */

#ifndef XWING_HPP
#define XWING_HPP

#include "SceneEntity.hpp"
#include "Camera.hpp"
#include "LaserBlast.hpp"
#include "Shader.hpp"
#include "VBO.hpp"
#include "ResourceManager/ResourceManager.hpp"

using namespace math;
using namespace resMan;

namespace engine 
{
	class SceneManager;
}

using namespace engine;

namespace game
{
 
/**
 * Class represents one Rebellion ships object - Xwing, which is player's default ship. The user can control
 * flying and shooting. Xwing like Tie-Fighter has two laser blasters. The only difference between these
 * ships is endurance.
 */
class Xwing : public SceneEntity
{
private:
	PResource mesh;
	PResource texture;
	VBO* entityVBO;
	Camera* camera;
	Vector3D moveDirection;
	Vector3D rotation;
	Quaternion* orientation;
	Shader shader;
	int currentID;
	float blasterAccumulator;
	SceneManager* scene;

public:
	Xwing(Camera* camera,const char* meshFileName, const char* textureFileName);
	~Xwing();

	void updateEntity(const float elapsedTime);
	void renderEntity();
	void shootLaserBlast();

	void accelerateShip();
	void slowDownShip();
	void steerShip();
	void rotateLeft();
	void rotateRight();
	void shootLasers();

	void setScene(SceneManager* worldScene);

};

}
#endif
