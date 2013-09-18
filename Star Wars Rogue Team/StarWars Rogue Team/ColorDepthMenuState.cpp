/**
 * Definition of ColorDepthMenuState class.
 * @file    ColorDepthMenuState.cpp
 * @author  Adam Sznajder
 * @date    2010-12-21
 * @version 1.0
 */

#include "ColorDepthMenuState.hpp"
#include "Menu/OptionsMenuState.hpp"
#include "ResolutionMenuState.hpp"
#include "Configuration.hpp"
#include "BackMenuState.hpp"

using namespace game;

namespace menu
{

/**
 * Constructor.
 */
ColorDepthMenuState::ColorDepthMenuState()
{
	backgroundColor.r = 0;
	backgroundColor.g = 0;
	backgroundColor.b = 0;
}

/**
 * Constructor.
 * @param bgColor init color.
 */
ColorDepthMenuState::ColorDepthMenuState(SDL_Color bgColor)
{
	backgroundColor = bgColor;
}

/**
 * Method used to change state up.
 * @return new state.
 */
IMenuState* ColorDepthMenuState::changeStateUp()
{
	ResolutionMenuState* state = new ResolutionMenuState();
	return state;
}

/**
 * Method used to change state down.
 * @return new state.
 */
IMenuState* ColorDepthMenuState::changeStateDown()
{
	BackMenuState* state = new BackMenuState();
	return state;
}

/**
 * Method used to perform dedicated to this state action.
 * @return new state.
 */
IMenuState* ColorDepthMenuState::performAction()
{
	Configuration* conf = Configuration::getInstance();
	if (conf->getColorDepth() == 16)
		conf->setColorDepth(24);
	else
		conf->setColorDepth(16);
	return this;
}

/**
 * Method used to display text on the screen.
 * @param font - font which will be used to write text.
 * @param screen - pointer to screen on which we will display everything.
 */
void ColorDepthMenuState::printMenuText(TTF_Font* font, SDL_Surface* screen)
{
	SDL_Color activeForeground, foregroundColor;
	int x = 335;
	int y = 300;

	activeForeground.r = foregroundColor.r = 255;
	foregroundColor.g = 255;
	foregroundColor.b = 51;
	activeForeground.g = 0;
	activeForeground.b = 0;
	
	Configuration* conf = Configuration::getInstance();
	if (!conf->getFullscreen())
		displayOneText(font, screen, "Full Screen: false", foregroundColor, x, y);
	else displayOneText(font, screen, "Full Screen: true", foregroundColor, x, y);
	y += 50;
	x -= 15;
	if (conf->getHeight() == 600)
		displayOneText(font, screen, "Resolution: 800x600", foregroundColor, x, y);
	else displayOneText(font, screen, "Resolution: 1024x768", foregroundColor, x, y);
	y += 50;
	x += 10;
	if (conf->getColorDepth() == 16)
		displayOneText(font, screen, "Color Depth: 16bit", activeForeground, x, y);
	else displayOneText(font, screen, "Color Depth: 24bit", activeForeground, x, y);
	y += 100;
	x += 30;
	displayOneText(font, screen, "   Back", foregroundColor, x, y);

	SDL_UpdateRect( screen,NULL,NULL, NULL, NULL );
};

}
