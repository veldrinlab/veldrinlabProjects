/**
 * File contains declaraion of SceneEntity class.
 * @file    SceneEntity.hpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2012-03-20
 */

#ifndef SCENEENTITY_HPP
#define SCENEENTITY_HPP

#include <SFML/Graphics.hpp>
#include <string>

namespace dse
{
	/**
	 * Structure represents entity node, can be used to create entity hierarchy.
	 */
	struct EntityNode
	{
		EntityNode* parent;
		EntityNode* child;
	};

	/**
	 * Class represents game scene entity. It extends drawable sf::Sprite.
	 */
	class SceneEntity : public sf::Sprite, public EntityNode
	{
	public:
		std::string name;
		std::string textureName;
		bool isVisible;
		bool isDead;
		sf::Vector2f velocity;
		sf::Vector2f acceleration;
		sf::Vector2f position;
		float orientation;
		float rotation;
		
		SceneEntity(const std::string& name, const std::string& textureName);
		virtual ~SceneEntity() {};
		virtual void updateEntity(const float elapsedTime) {};
	};
}
#endif
