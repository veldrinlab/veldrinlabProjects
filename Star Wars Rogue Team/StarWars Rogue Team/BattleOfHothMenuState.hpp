/**
 * Declaration of BattleOfHothMenuState class.
 * @file    BattleOfHothMenuState.h
 * @author  Adam Sznajder
 * @date    2010-11-13
 * @version 1.0
 */

#ifndef BattleOfHothMenuState_H
#define BattleOfHothMenuState_H

#include "Menu/IMenuState.hpp"

namespace menu
{

/**
 * BattleOfHothMenuState is a IMenuState based class which is used in order to
 * show when "Play Battle of Hoth" option is active.
 */
class BattleOfHothMenuState : public IMenuState
{
	public:
		BattleOfHothMenuState();
		BattleOfHothMenuState(SDL_Color backgroundClr);
    ~BattleOfHothMenuState() {};
		virtual IMenuState* changeStateUp();
		virtual IMenuState* changeStateDown();
		virtual IMenuState* performAction();
		virtual void printMenuText(TTF_Font* font, SDL_Surface* screen);
};

}
#endif