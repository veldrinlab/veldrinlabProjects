/**
 * File contains declaration of Player class.
 * @file    Player.hpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    
 * @version 1.0
 */

#ifndef PLAYERPAD_HPP
#define PLAYERPAD_HPP

#include "../Engine/SceneEntity.hpp"
#include "../ResourceManager/ResourceManager.hpp"
#include "Sword.hpp"
#include "Animation.hpp"


namespace Game
{
/**
 * Class represents main game world object - Polygon Hero class. Store pointer to sword, can be controlled by gamepad.
 * @remarks optimization
 */
class PlayerPad : public Engine::SceneEntity
{
public:
	Resource::PResource texture;
	Animation playerAnimation;
	Math::Vector3D moveDirection;
	bool damageOccurred;
	float angle;
	bool attacking;
	bool rage;
	int hpAccumulator;
	int mpAccumulator;
	int mana;
	int manaAccum;
	
	
	PlayerPad();
public:

	PlayerPad(const char* textureFileName, const Math::Vector3D& position);
	~PlayerPad();
	bool buildTower;
	bool speedUp_active;
	bool probieren_active;
	bool verhogen_active;

	bool isSpeededUp;


	void updateEntity(const float elapsedTime);
	void renderEntity();

	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	void stopXAxisMove();
	void stopYAxisMove();

	void Probieren();
	void Verhogen();
	void SpeedUp();
	void SetTower();

	void damaged();
	int getHealthPoints() const;
	int getMana() const;
	bool isAttacking() const;
	bool isRage() const;
};

}
#endif
