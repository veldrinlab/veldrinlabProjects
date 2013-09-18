/**
 * File contains definition of EnemyPrototypeFactory class.
 * @file    EnemyPrototypeFactory.hpp
 * @author  Adam Sznajder
 * @date    2010-01-07
 * @version 1.0
 */

#ifndef ENEMY_PROTOTYPE_FACTORY_HPP
#define ENEMY_PROTOTYPE_FACTORY_HPP

#include "EnemyPrototype.hpp"
#include <vector>
#include <string>
#include <map>

namespace game
{

/**
 * EnemyPrototypeFactory is a singleton class which is implemented as prototype factory.
 * It will be used in order to create clones of enemies. It's essential to remember that
 * when we want to create a clone of some enemy we first have to register it by giving
 * sample object which is EnemyPrototype based and will be used by the factory as a prototype.
 */
class EnemyPrototypeFactory
{
private:
	static EnemyPrototypeFactory* instance; // Static pointer to singleton object.
	std::map<std::string, EnemyPrototype*> prototypes; // Map of prototypes' names and their sample instances.
public:
	static EnemyPrototypeFactory* getInstance()
	{
		if (instance == NULL)
			instance = new EnemyPrototypeFactory();
		return instance;
	}
	bool registerEnemy(std::string name, EnemyPrototype* enemyPrototype); // Method used to enroll production of a resource to a factory.
	EnemyPrototype* createEnemy(std::string name); // Method used to return needed resource.
};

}
#endif