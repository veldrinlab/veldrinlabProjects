/**
 * Definition of BattleOfMindorMenuState class.
 * @file    BattleOfMindorMenuState.cpp
 * @author  Adam Sznajder
 * @date    2010-12-21
 * @version 1.0
 */

#include "BattleOfMindorMenuState.hpp"
#include "BattleOfHothMenuState.hpp"
#include "ChooseLevelMenuState.hpp"
#include "Configuration.hpp"
#include "Game.hpp"

namespace menu
{

/**
 * Constructor.
 */
BattleOfMindorMenuState::BattleOfMindorMenuState()
{
	backgroundColor.r = 0;
	backgroundColor.g = 0;
	backgroundColor.b = 0;
}

/**
 * Constructor.
 * @param bgColor init color.
 */
BattleOfMindorMenuState::BattleOfMindorMenuState(SDL_Color bgColor)
{
	backgroundColor = bgColor;
}

/**
 * Method used to change state up.
 * @return new state.
 */
IMenuState* BattleOfMindorMenuState::changeStateUp()
{
	ChooseLevelMenuState* state = new ChooseLevelMenuState();
	return state;
}

/**
 * Method used to change state down.
 * @return new state.
 */
IMenuState* BattleOfMindorMenuState::changeStateDown()
{
	BattleOfHothMenuState* state = new BattleOfHothMenuState();
	return state;
}

/**
 * Method used to perform dedicated to this state action.
 * @return new state.
 */
IMenuState* BattleOfMindorMenuState::performAction()
{
	Configuration* conf = Configuration::getInstance();
	conf->setLevel(FIRST);
	Game *game = new Game();
	game->performAction();

	return NULL;
}

/**
 * Method used to display text on the screen.
 * @param font - font which will be used to write text.
 * @param screen - pointer to screen on which we will display everything.
 */
void BattleOfMindorMenuState::printMenuText(TTF_Font* font, SDL_Surface* screen)
{
	SDL_Color activeForeground, foregroundColor;
	int x = 370;
	int y = 320;

	activeForeground.r = foregroundColor.r = 255;
	foregroundColor.g = 255;
	foregroundColor.b = 51;
	activeForeground.g = 0;
	activeForeground.b = 0;
	
	Configuration* conf = Configuration::getInstance();
	displayOneText(font, screen, "Intro", foregroundColor, x, y);
	y += 50;
	x -= 45;
	displayOneText(font, screen, "Battle of Mindor", activeForeground, x, y);
	y += 50;
	x += 10;
	displayOneText(font, screen, "Battle of Hoth", foregroundColor, x, y);

	SDL_UpdateRect( screen, NULL, NULL, NULL, NULL );
};

}