/**
 * File contains declaration of EnemyPrototypeFactory class.
 * @file    EnemyPrototypeFactory.hpp
 * @author  Adam Sznajder
 * @date    2010-01-07
 * @version 1.0
 */

#include "EnemyPrototypeFactory.hpp"

namespace game
{

EnemyPrototypeFactory* EnemyPrototypeFactory::instance = NULL;

/**
 * Method used to register a Resource in a factory.
 * @param	name is the enemy's id.
 * @param	enemyPrototype is the sample object of the enemy used to create copies.
 * @return	information that enemy was registered successful.
 */
bool EnemyPrototypeFactory::registerEnemy(std::string name, EnemyPrototype* enemyPrototype)
{
	prototypes.insert(std::map<std::string, EnemyPrototype*>::value_type(name, enemyPrototype));
	return true;
}

/**
 * Method used to create enemy from a prototype.
 * @param	name is the enemy's id.
 * @return	copy of the enemy.
 */
EnemyPrototype* EnemyPrototypeFactory::createEnemy(std::string name)
{
	std::map<std::string, EnemyPrototype*>::const_iterator iterator = prototypes.find(name);
	if (iterator != prototypes.end())
		return (iterator->second)->clone();
	return NULL;
}

}