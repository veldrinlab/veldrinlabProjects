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
#include "AnimationFrameCoords.hpp"


namespace Game
{
/**
 * Class represents main game world object - Polygon Hero class. Store pointer to sword, can be controlled by gamepad.
 * @remarks optimization
 */
class PlayerWii : public Engine::SceneEntity
{
private:
	Resource::PResource texture;
	Animation playerAnimation[2];
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
	
	PlayerWii();
public:

	PlayerWii(const char* textureFileName, const Math::Vector3D& position);
	~PlayerWii();

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
	void stomp();
	void stompStop();

	float stompTime;
	bool stompButton;
	bool stompAttack;

	void damaged();
	int getHealthPoints() const;
	int getMana() const;
	bool isAttacking() const;
	bool isJumping;
	bool isRage() const;

	AnimationFrameCoords jumpCoords[16];

	Sword* getSword() const;
	void setSword(Sword* sword);
};

}
#endif
