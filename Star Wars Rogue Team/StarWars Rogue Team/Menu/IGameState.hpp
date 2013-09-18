/**
 * File contains declaration of IGameState which is an abstract class used in "State" pattern.
 * @file    IGameState.h
 * @author  Adam Sznajder
 * @date    2010-11-19
 * @version 1.0
 */

#ifndef IGAME_STATE_H
#define IGAME_STATE_H

class IGameState
{
	public:
		virtual void performAction() = 0;
};
#endif