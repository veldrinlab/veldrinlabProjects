/**
 * Definition of ResourceManager class.
 * @file    ResourceManager.h
 * @author  Adam Sznajder
 * @date    2010-10-29
 * @version 1.0
 */

#include "ResourceManager.hpp"

using namespace std;

namespace resMan
{

/**
 * Static pointer initialization.
 */
ResourceManager* ResourceManager::instance = NULL;

/**
 * Method used to register a Resource in a factory.
 * @param	resType is the type of registered resource.
 * @param	fun is the pointer to function which will be invoked in order to create new resource's object.
 */
void ResourceManager::registerResource(ResourceType resType, CreateResource fun)
{
	resourceCreators.insert(map<ResourceType, CreateResource>::value_type(resType, fun));
}

/**
 * Method used to return needed resource.
 * @param	name is the name of the resource which is unique for each resource.
 * @param	filepath is the path to the resource's file.
 * @param	resourceType is the type of the current resource.
 * @return	shared pointer to Resource object.
 */
PResource ResourceManager::getResource(string name, string filepath, ResourceType resourceType)
{
	if (!loadedResources.empty())
	{
		std::map<string, PResource>::const_iterator iterator = loadedResources.find(name);
		if (iterator != loadedResources.end())
			return iterator->second;
	}
	Creators::const_iterator i = resourceCreators.find(resourceType);
	PResource resource = (i->second)(name, filepath);
	resource.get()->loadResource();
	loadedResources.insert(map<string, PResource>::value_type(name, resource));

	return resource;
}

}
