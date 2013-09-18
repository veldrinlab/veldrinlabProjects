/**
 * Definition of Resource class.
 *
 * @file    Resource.h
 * @author  Adam Sznajder
 * @date    2010-10-29
 * @version 1.0
 */

#include "Resource.hpp"

using namespace std;

namespace resMan
{

/**
 * Accessor to the resourceType variable.
 * @return	type of the resource.
 */
ResourceType Resource::getResourceType()
{
	return resourceType;
}

/**
 * Accessor to the name variable.
 * @return	name of the resource.
 */
string Resource::getName()
{
	return *name;
}

/**
 * Accessor to the filepath variable.
 * @return	filepath to the resource.
 */
string Resource::getFilepath()
{
	return filepath;
}
}
