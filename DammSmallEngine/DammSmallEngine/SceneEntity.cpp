/**
 * File contains definition of SceneEntity class.
 * @file    SceneEntity.cpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2012-03-20
 */

#include "SceneEntity.hpp"

using namespace std;

namespace dse
{
	/**
	 * Class constructor with initialize variabes.
	 * @param	name is entity name.
	 * @param	textureName is entity texture name.
	 */
	SceneEntity::SceneEntity(const string& name, const string& textureName)
	{
		this->name = name;
		this->textureName = textureName;
		this->isDead = false;
		this->isVisible = true;
	}
}
