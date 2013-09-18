/**
 * PlayerStrategy module contains Player strategy classes, encapsulated algotithm
 * of player movement, animation etc. depends on Player State and game input.
 *
 *  Created on: 2010-08-28
 *      Author: Szymon "Veldrin" Jab³oñski
 */


#ifndef PLAYERSTRATEGY_H
#define PLAYERSTRATEGY_H

class Player;

class PlayerStrategy
{
public:
	virtual void executeStrategy(Player* player, float dt) = 0;

};

class IdleStrategy : public PlayerStrategy
{
public:
	IdleStrategy(Player *player);
	void executeStrategy(Player* player, float dt);

};

class MoveRightStrategy : public PlayerStrategy
{
public:
	MoveRightStrategy(Player *player);
	void executeStrategy(Player* player, float dt);

};

class MoveLeftStrategy : public PlayerStrategy
{
public:
	MoveLeftStrategy(Player *player);
	void executeStrategy(Player* player, float dt);

};

class JumpStrategy : public PlayerStrategy
{
public:
	JumpStrategy(Player* player);
	void executeStrategy(Player* player, float dt);

};

class FallStrategy : public PlayerStrategy
{
public:
	FallStrategy(Player* player);
	void executeStrategy(Player* player, float dt);

};

#endif