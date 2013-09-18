/**
 * File contains declaration of GameState module classes. Use State pattern.
 * @file    GameState.h
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2010-12-01
 * @version 1.0
 */

#ifndef GAMESTATE_H
#define GAMESTATE_H

namespace Game
{

class Game;

/**
 * Class represents abstract Game State.  All game states must extend GameState class and implement interface.
 * @remarks
 */
class GameState
{
public:
	Game* game;
	~GameState() {};
	virtual void performAction() = 0;

};

/**
 * Class represents game idle state which is on when application if building engine and loading resource.
 */
class IdleState : public GameState
{
public:
	IdleState(Game* game)
	{
		this->game = game;
	};

	void performAction();

};

/**
 * Class represents game main state - play. 
 */
class PlayState : public GameState
{
public:
	PlayState(Game* game)
	{
		this->game = game;
	};

	void performAction();

};}
#endif
