/**
 * Declaration of Menu class.
 * @file    Menu.h
 * @author  Adam Sznajder
 * @date    2010-11-13
 * @version 1.0
 */

#ifndef MENU_H
#define MENU_H

#include <SDL.h>
#include <SDL_ttf.h>
#include "Menu/IMenuState.hpp"
#include "Menu/IGameState.hpp"
#include "Menu/MenuStateContext.hpp"
#include "Menu/CreditsMenuState.hpp"
#include "Menu/OptionsMenuState.hpp"
#include "Menu/QuitMenuState.hpp"
#include "GameMenuState.hpp"
#include "FontException.hpp"
#include "Menu/TextCreationException.hpp"
#include <iostream>

namespace menu
{

/**
 * Menu is a class which represents main menu of the whole game.
 */
class Menu
{
	private:
		SDL_Surface* screen;
		TTF_Font* font;
		MenuStateContext* stateContext;
		const char* backgroundPath; 
		void menuUp();
		void menuDown();
		void displayMenuBackground();
	public:
		Menu();
		~Menu();
		void configureMenu(const char* fontPath, const char* background, int fontSize) throw(TextCreationException, FontException);
		void showMenu();
};

}
#endif
