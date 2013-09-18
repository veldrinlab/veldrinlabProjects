/**
 * File contains declaration of Player class.
 * @file    Player.hpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    
 * @version 1.0
 */

#ifndef PLAYER_HPP
#define PLAYER_HPP

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
class Player : public Engine::SceneEntity
{
private:
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
	Sword* sword;
	
	Player();
public:

	Player(const char* textureFileName, const Math::Vector3D& position);
	~Player();

	void updateEntity(const float elapsedTime);
	void renderEntity();

	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	void stopXAxisMove();
	void stopYAxisMove();
	void rightAttack();
	void leftAttack();
	void rageStart();

	void damaged();
	int getHealthPoints() const;
	int getMana() const;
	bool isAttacking() const;
	bool isRage() const;

	Sword* getSword() const;
	void setSword(Sword* sword);
};

}
#endif
