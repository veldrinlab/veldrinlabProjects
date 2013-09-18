/**
 * Definition of MenuStateContext class.
 * @file    MenuStateContext.cpp
 * @author  Adam Sznajder
 * @date    2010-11-13
 * @version 1.0
 */

#include "MenuStateContext.hpp"

namespace menu
{

/**
 * Constructor.
 * @param initState - initial state of the menu.
 */
MenuStateContext::MenuStateContext(IMenuState* initState)
{
	activeState = initState;
}

/**
 * Method used to perform action connected with current state.
 * @return boolean value which indicates whether we have to close the whole application.
 */
bool MenuStateContext::performAction()
{
	IMenuState* tempState = activeState->performAction();
	if (!tempState)
		return true;
	activeState = tempState;
	return false;
}

/**
 * Method used to signal closing the game.
 * @return boolean value which is always true and it means that we have to close the whole application.
 */
bool MenuStateContext::performQuitMenuAction()
{
	return true;
}

/**
 * Destructor.
 */
MenuStateContext::~MenuStateContext()
{
	delete activeState;
}

/**
 * Method used to change the state of menu to the new one (upper).
 */
void MenuStateContext::changeStateUp()
{
	IMenuState* oldState = activeState;
	activeState = activeState->changeStateUp();
	delete oldState;
}

/**
 * Method used to change the state of menu to the new one (bottom).
 */
void MenuStateContext::changeStateDown()
{
	IMenuState* oldState = activeState;
	activeState = activeState->changeStateDown();
	delete oldState;
}

/**
 * Method used to print menu for current state.
 * @param font - pointer to TTF_Font object which will be used to type some text on the screen.
 * @param screen - pointer to the screen on which everything will be displaied.
 */
void MenuStateContext::printMenu(TTF_Font* font, SDL_Surface* screen)
{
	activeState->printMenuText(font, screen);
};

}
