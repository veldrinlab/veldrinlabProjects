/**
 * File contains declaration of GameHud class.
 * @file    GameHud.h
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2010-11-28
 * @version 1.0
 */

#ifndef GAMEHUD_H
#define GAMEHUD_H

#include "Texture.h"
#include "Mesh.h"

/**
 * Class represents game head up display showing player life number and gained points. GameHud must be last
 * rendered scene element.
 * @remarks 
 */
class GameHud
{
private:
	Texture* lifeTexture;
	Texture* pointsTexture;
	int lifeAmount;
	int points;

public:
	GameHud();
	~GameHud();

	void renderGameHud();
	void renderLifes();
	void renderPoints();

	void setLifeAmount(const int lifeAmount);
	void increasePoints();

};
#endif
