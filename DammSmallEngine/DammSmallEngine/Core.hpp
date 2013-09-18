/**
 * File contains declaration of Core structure.
 * @file    Core.hpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2012-03-20
 */

#ifndef CORE_HPP
#define CORE_HPP

#include <SFML/Graphics.hpp>

#include "Configuration.hpp"
#include "Timer.hpp"
#include "Resource.hpp"
#include "SceneEntity.hpp"

namespace dse
{
	/**
	 * Structure represents engine core data.
	 */
	struct Core
	{
		sf::RenderWindow* window; 
		Timer* timer;
		sf::View* view;
		Resource* resources;

		Core();
		~Core();

		void createWindow();
		void configureView();
		void initializeCore();

		sf::Texture* getTexture(const std::string& name);
		sf::Font* getFont(const std::string& name);
		sf::Shader* getShader(const std::string& name);
	
		void playMusic(const std::string& name);
		void stopMusic(const std::string& name);
		void playSoundEffect(const std::string& name);
		void stopSoundEffect(const std::string& name);
	};
}
#endif
