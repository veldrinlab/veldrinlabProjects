/**
 * Declaration of QuitMenuState class.
 * @file    QuitMenuState.h
 * @author  Adam Sznajder
 * @date    2010-11-13
 * @version 1.0
 */

#ifndef QUITMENUSTATE_H
#define QUITMENUSTATE_H

#include "IMenuState.hpp"

namespace menu
{

/**
 * QuitMenuState is a IMenuState based class which is used in order to represent the state when "Quit" option is active in a menu.
 */
class QuitMenuState : public IMenuState
{
	public:
		QuitMenuState();
		QuitMenuState(SDL_Color initColor);
    ~QuitMenuState() {};
		virtual IMenuState* changeStateUp();
		virtual IMenuState* changeStateDown();
		virtual IMenuState* performAction();
		virtual void printMenuText(TTF_Font* font, SDL_Surface* screen);
};

}
#endif
