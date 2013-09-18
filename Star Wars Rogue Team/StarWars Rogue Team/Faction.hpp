/**
 * File contains declaration of Faction enumeration.
 * @file    Faction.h
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2010-12-25
 * @version 1.0
 */

#ifndef FACTION_H
#define FACTION_H

namespace game
{

/**
 * Class represents faction informaton. It is used to identify laser blast
 * or colliding objects.
 */
enum Faction
{
	IMPERIAL,
	REBELION,
	INDEPENDENT,
  LASER,
  ASTEROID
};

}
#endif
