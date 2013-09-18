/**
 * Definition of IMenuState class.
 * @file    IMenuState.cpp
 * @author  Adam Sznajder
 * @date    2010-11-13
 * @version 1.0
 */

#include "IMenuState.hpp"

namespace menu
{

/**
* Method used to display on a screen only one string.
* @param	font is the pointer to TTF_Font which will be used to type a text on the screen.
* @param	screen is the pointer to the screen on which we will type.
* @param	text is the text to type.
* @param	foregroundColor is the color which will be used to type not active options.
* @param	x is the x axis location.
* @param	y is the y axis location.
*/
void IMenuState::displayOneText(TTF_Font* font, SDL_Surface* screen, const char* text, SDL_Color foregroundColor, int x, int y) throw(TextCreationException)
{
	SDL_Surface *sText;
	SDL_Rect dest = {x, y, 0, 0};

	if (!(sText= TTF_RenderUTF8_Shaded(font, text, foregroundColor, backgroundColor)))
	{
		if(sText != NULL)
				SDL_FreeSurface(sText);
		throw new TextCreationException();
	}

	SDL_BlitSurface( sText, NULL, screen, &dest );
	SDL_FreeSurface( sText );
}

}
