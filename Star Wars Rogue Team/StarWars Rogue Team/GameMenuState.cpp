/**
 * Definition of GameMenuState class.
 * @file    GameMenuState.cpp
 * @author  Adam Sznajder
 * @date    2010-11-13
 * @version 1.0
 */

#include "GameMenuState.hpp"
#include "ChooseLevelMenuState.hpp"
#include "Menu/OptionsMenuState.hpp"
#include "Menu/QuitMenuState.hpp"

namespace menu
{

/**
 * Constructor.
 */
GameMenuState::GameMenuState()
{
	backgroundColor.r = 0;
	backgroundColor.g = 0;
	backgroundColor.b = 0;
}

/**
 * Constructor.
 * @param bgColor init color.
 */
GameMenuState::GameMenuState(SDL_Color bgColor)
{
	backgroundColor = bgColor;
}

/**
 * Method used to perform dedicated to this state action.
 * @return new state.
 */
IMenuState* GameMenuState::performAction()
{
	ChooseLevelMenuState* state = new ChooseLevelMenuState();

	return state;
}

/**
 * Method used to change state up.
 * @return new state.
 */
IMenuState* GameMenuState::changeStateUp()
{
	QuitMenuState* state = new QuitMenuState();
	return state;
}

/**
 * Method used to change state down.
 * @return new state.
 */
IMenuState* GameMenuState::changeStateDown()
{
	OptionsMenuState* state = new OptionsMenuState();
	return state;
}

/**
 * Method used to display text on the screen.
 * @param font - font which will be used to write text.
 * @param screen - pointer to screen on which we will display everything.
 */
void GameMenuState::printMenuText(TTF_Font* font, SDL_Surface* screen)
{
	SDL_Color activeForeground, foregroundColor;
	int x = 370;
	int y = 320;

	activeForeground.r = foregroundColor.r = 255;
	foregroundColor.g = 255;
	foregroundColor.b = 51;
	activeForeground.g = 0;
	activeForeground.b = 0;

	displayOneText(font, screen, "New Game", activeForeground, x, y);
	y += 50;
	x += 13;
	displayOneText(font, screen, "Options", foregroundColor, x, y);
	y += 50;
	x += 5;
	displayOneText(font, screen, "Credits", foregroundColor, x, y);
	y += 50;
	x += 10;
	displayOneText(font, screen, "Quit", foregroundColor, x, y);

	SDL_UpdateRect( screen,NULL,NULL, NULL, NULL );
};

}