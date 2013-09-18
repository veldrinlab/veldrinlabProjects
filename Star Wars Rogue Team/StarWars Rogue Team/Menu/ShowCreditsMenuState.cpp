/**
 * Definition of ShowCreditsMenuState class.
 * @file    ShowCreditsMenuState.cpp
 * @author  Adam Sznajder
 * @date    2010-11-13
 * @version 1.0
 */

#include "ShowCreditsMenuState.hpp"
#include "CreditsMenuState.hpp"

namespace menu
{

/**
 * Constructor.
 */
ShowCreditsMenuState::ShowCreditsMenuState()
{
	backgroundColor.r = 0;
	backgroundColor.g = 0;
	backgroundColor.b = 0;
}

/**
 * Constructor.
 * @param bgColor init color.
 */
ShowCreditsMenuState::ShowCreditsMenuState(SDL_Color bgColor)
{
	backgroundColor = bgColor;
}

/**
 * Method used to change state up.
 * @return new state.
 */
IMenuState* ShowCreditsMenuState::changeStateUp()
{
	ShowCreditsMenuState* state = new ShowCreditsMenuState();
	return state;
}

/**
 * Method used to change state down.
 * @return new state.
 */
IMenuState* ShowCreditsMenuState::changeStateDown()
{
	return changeStateUp();
}

/**
 * Method used to perform dedicated to this state action.
 * @return new state.
 */
IMenuState* ShowCreditsMenuState::performAction()
{
	CreditsMenuState* state = new CreditsMenuState();
	return state;
}

/**
 * Method used to display text on the screen.
 * @param font - font which will be used to write text.
 * @param screen - pointer to screen on which we will display everything.
 */
void ShowCreditsMenuState::printMenuText(TTF_Font* font, SDL_Surface* screen)
{
	SDL_Color activeForeground, foregroundColor;
	int x = 265;
	int y = 320;

	activeForeground.r = foregroundColor.r = 255;
	foregroundColor.g = 255;
	foregroundColor.b = 51;
	activeForeground.g = 0;
	activeForeground.b = 0;

	displayOneText(font, screen, "Mamo, mamo! Jestem hakerem!", foregroundColor, x, y);
	y += 50;
	x -= 100;
	displayOneText(font, screen, "Adas kocha Anie", foregroundColor, x, y);
	y += 50;
	x += 70;
	displayOneText(font, screen, "Background: http://insd.swcombine.com/", foregroundColor, x, y);
	y += 100;
	x += 30;
	displayOneText(font, screen, "PRESS [ENTER] TO GO BACK", activeForeground, x, y);

	SDL_UpdateRect( screen,NULL,NULL, NULL, NULL );
};

}