/**
 * Definition of ResourceManager class.
 *
 * models, textures and audio files.
 * @file    ResourceManager.h
 * @author  Adam Sznajder
 * @date    2010-10-29
 * @version 1.0
 */

#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include "ResourceType.hpp"
#include "Resource.hpp"
#include "Texture.hpp"
#include <boost/shared_ptr.hpp>
#include <string>
#include <vector>
#include <map>

namespace resMan
{

typedef boost::shared_ptr<Resource> PResource; // smart pointer to Resource objects.

/**
 * Class which will be responsible for loading and storing resources in the whole game. 
 * It's a singleton factory.
 */
class ResourceManager
{
private:
	static ResourceManager* instance; // Static pointer to singleton object.
	typedef PResource (*CreateResource)(std::string, std::string);
	typedef std::map<ResourceType, CreateResource> Creators;
	Creators resourceCreators; // Map of resource's names and their creators.
	std::map<std::string, PResource> loadedResources;
public:
	static ResourceManager* getInstance()
	{
		if (instance == NULL)
			instance = new ResourceManager();
		return instance;
	}
	void registerResource(ResourceType resType, CreateResource fun); // Method used to enroll production of a resource to a factory.
	PResource getResource(std::string name, std::string filepath, ResourceType resourceType); // Method used to return needed resource.
};

}

#endif
