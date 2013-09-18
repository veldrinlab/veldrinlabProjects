/**
 * File contains declaration of GameHud class.
 * @file    GameHud.hpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2010-11-28
 * @version 1.0
 */

#ifndef GAMEHUD_HPP
#define GAMEHUD_HPP

#include <math.h>

#include "ResourceManager/ResourceManager.hpp"

using namespace resMan;

namespace game
{

/**
 * Class represents game head up display showing player life status and crosshair. GameHud must be last
 * rendered scene element.
 * @remarks 
 */
class GameHud
{
private:
	PResource shieldTexture;
	PResource crosshairTexture;
	int shieldStatus;

public:
	GameHud();
	~GameHud();

	void renderGameHud();

	void renderShieldStatus();
	void renderCrosshair();

};

}
#endif
