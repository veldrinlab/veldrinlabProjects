/**
 * File contains definition of EnemyPrototype class.
 * @file    EnemyPrototype.hpp
 * @author  Adam Sznajder
 * @date    2011-01-01
 * @version 1.0
 */

#ifndef ENEMY_PROTOTYPE_HPP
#define ENEMY_PROTOTYPE_HPP

#include <boost/shared_ptr.hpp>
#include <vector>
#include "SceneEntity.hpp"
#include "ShootedLasers.hpp"

namespace game
{

/**
 * Abstract class which is base for enemies classes in order
 * to assure possibility of producing objects of those classes
 * in EnemyPrototypeFactory.
 */
class EnemyPrototype
{
public:
	virtual EnemyPrototype* clone()=0;
	virtual void setScene(ShootedLasers *shooted) { };
};

}
#endif