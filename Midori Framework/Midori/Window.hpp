#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SFML/Window.hpp>

namespace Midori
{
	struct Window
	{
		sf::Window* contextWindow; 
		sf::ContextSettings contextSettings;
		sf::VideoMode contextVideoMode;
	};
}
#endif
