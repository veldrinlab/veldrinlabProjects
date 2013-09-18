/**
 * EntityManager.h
 *
 * EntityManaher class store all model/logic data of Game. Store all instances 
 * of game Entity objects. 
 *
 *  Created on: 2010-08-28
 *      Author: Szymon Jab³oñski - Veldrin
 */

#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include <vector>
#include <string>
#include "Entity.h"
#include "Player.h"
#include "ResourceManager.h"

class EntityManager
{
private:
	std::vector<Entity*> entityVector;
	ResourceManager *resourceManager;

public:
	EntityManager(std::string entityDataFileName, ResourceManager *resourceManager);
	~EntityManager();

	void updateEntities(float dt);

	void addEntity();
	void deleteEntity();

	std::vector<Entity*> getEntityMap();
	Entity* getPlayerEntity();
	

};
#endif