/**
 * EntityManager.cpp
 * File contains definition of EntityManager class.
 *
 *  Created on: 2010-08-28
 *      Author: Szymon Jab³oñski - Veldrin
 */

#include "EntityManager.h"

using namespace std;

//TODO: Entity Manager wczytywanie z pliku
EntityManager::EntityManager(string entityDataFileName,ResourceManager *resourceManager)
{
	this->resourceManager = resourceManager;


	//wczytanie z pliku danych o obiekatach w danym levelu i utworzenie mapy
	//na poczatek tylko Mario

	//wykorzystanie fabryki obiektów i metody fabrykuj¹cej

	this->entityVector.push_back(new Player(this->resourceManager->getPlayerSpriteSheet(),47,32));

}

EntityManager::~EntityManager()
{

}

void EntityManager::updateEntities(float dt)
{
	for(unsigned int i = 0; i < entityVector.size(); i++)
		entityVector[i]->updateEntity(dt);
}

void EntityManager::addEntity()
{

}

void EntityManager::deleteEntity()
{

}

vector<Entity*> EntityManager::getEntityMap()
{
	return entityVector;
}

Entity* EntityManager::getPlayerEntity()
{
	return entityVector[0];
}
