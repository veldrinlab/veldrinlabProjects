/**
 * File contains declaration of GameState module classes. Use State pattern.
 * @file    GameState.h
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2010-12-01
 * @version 1.0
 */

#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "StarDestroyer.hpp"
#include "AudioManager.hpp"
#include "Camera.hpp"
#include "Configuration.hpp"
#include "Level.hpp"
#include "SkyBox.hpp"

using namespace math;

namespace game
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

};

/**
 * Class represents game pause state - when player click pause key, game will pause.
 */
class PauseState : public GameState
{
private:
	PResource pause;

public:

	PauseState(Game* game)
	{
		this->game = game;
		ResourceManager* resManager = ResourceManager::getInstance();
		pause = resManager->getResource(std::string("Pause"), std::string("Data/pause.png"), TEXTURE);
	};

	~PauseState()
	{

	}

	void performAction();

};

/**
 * Class represents game over state which is on when player space ship had been destroyed by Invaders.
 */
class GameOverState : public GameState
{
private:
	PResource gameOver;

public:
	GameOverState(Game* game)
	{
		this->game = game;
		ResourceManager* resManager = ResourceManager::getInstance();
		gameOver = resManager->getResource(std::string("GameOver"), std::string("Data/gameover.png"), TEXTURE);
	};

	~GameOverState()
	{

	}

	void performAction();

};


class IntroState : public GameState
{
private:
	PResource longTime;
	PResource logo;
	AudioManager* introMusic;
	SkyBox* space;
	StarDestroyer* destroyer;
	float timeAccumulator;
	float blendAccumulator;

public:
	IntroState(Game* game)
	{
		this->game = game;
		ResourceManager* resManager = ResourceManager::getInstance();
		longTime = resManager->getResource(std::string("LongTime"), std::string("Data/longTime.jpg"),TEXTURE);
		logo = resManager->getResource(std::string("Logo"), std::string("Data/logo.png"),TEXTURE);
		timeAccumulator = 0.0f;
		blendAccumulator = -3.0f;
		space = new SkyBox(Vector3D(0,0,0),Vector3D(2000,2000,2000),0);
		introMusic = new AudioManager();
	};

	~IntroState()
	{
		delete introMusic;
	}

	void performAction();
};

}
#endif
