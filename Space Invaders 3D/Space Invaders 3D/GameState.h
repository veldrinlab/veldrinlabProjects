/**
 * File contains declaration of GameState module classes. Use State pattern.
 * @file    GameState.h
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2010-12-01
 * @version 1.0
 */

#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "Texture.h"

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

};

/**
 * Class represents game pause state - when player click pause key, game will pause.
 */
class PauseState : public GameState
{
private:
	Texture* pause;

public:

	PauseState(Game* game)
	{
		this->game = game;
		pause = new Texture("Data/pause.png");
	};

	~PauseState()
	{
		delete pause;
	}

	void performAction();

};

/**
 * Class represents game over state which is on when player space ship had been destroyed by Invaders.
 */
class GameOverState : public GameState
{
private:
	Texture* gameOver;

public:
	GameOverState(Game* game)
	{
		this->game = game;
		gameOver = new Texture("Data/gameover.png");

	};

	~GameOverState()
	{
		delete gameOver;
	}

	void performAction();

};
#endif
