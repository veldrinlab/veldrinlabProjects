/**
 * Declaration of BattleOfMindorMenuState class.
 * @file    BattleOfMindorMenuState.h
 * @author  Adam Sznajder
 * @date    2010-11-13
 * @version 1.0
 */

#ifndef BattleOfMindorMenuState_H
#define BattleOfMindorMenuState_H

#include "Menu/IMenuState.hpp"

namespace menu
{

/**
 * BattleOfMindorMenuState is a IMenuState based class which is used in order to
 * show when "Play Battle of Mindor" option is active.
 */
class BattleOfMindorMenuState : public IMenuState
{
	public:
		BattleOfMindorMenuState();
		BattleOfMindorMenuState(SDL_Color backgroundClr);
    ~BattleOfMindorMenuState() {};
		virtual IMenuState* changeStateUp();
		virtual IMenuState* changeStateDown();
		virtual IMenuState* performAction();
		virtual void printMenuText(TTF_Font* font, SDL_Surface* screen);
};

}
#endif