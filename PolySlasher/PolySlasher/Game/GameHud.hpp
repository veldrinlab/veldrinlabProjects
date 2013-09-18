/**
 * File contains declaration of GameHud class.
 * @file    GameHud.hpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2010-02-28
 * @version 2.0
 */

#ifndef GAMEHUD_HPP
#define GAMEHUD_HPP

#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include <stdlib.h>
#include <time.h>

#include "../ResourceManager/ResourceManager.hpp"

namespace Game
{

/**
 * Class represents game head up display showing player life status and crosshair. GameHud must be last
 * rendered scene element.
 * @remarks 
 */
class GameHud
{
private:
	Resource::PResource hpTexture;
	Resource::PResource mpTexture;
	Resource::PResource scoreTexture;
	Resource::PResource statTexture;

	int hpAmount;
	int mpAmount;
	int score[5];
	int points;

public:
	GameHud();
	~GameHud();

	void renderGameHud();
	void setHpAmount(const int hpAmount);
	void setMpAmount(const int mpAmount);
	void increaseScore();
	void resetScore();
	void calculateScore();
};

}
#endif

