/**
 * File contains declaration of Sword class.
 * @file    
 * @author  Szymon "Veldrin" Jab³oñski
 * @date	2011-02-28
 * @version 1.0
 */

#ifndef SWORD_HPP
#define SWORD_HPP

#include "../Engine/SceneEntity.hpp"
#include "../ResourceManager/ResourceManager.hpp"

namespace Game
{
/**
 * Class represents main Player weapon - big bastard sword which is used to kill Enemies.
 * @remarks
 */
class Sword : public Engine::SceneEntity
{
private:
	Resource::PResource texture;
	float angle;
	Sword();
public:
	Sword(const char* textureFileName, const Math::Vector3D& position);
	~Sword();

	void updateEntity(const float elapsedTime);
	void renderEntity();

	void setAngle(const float angle);
	float getAngle() const;
};

}
#endif
