/**
 * File contains declaration of Resource structure.
 * @file    Resource.hpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2012-03-20
 */

#ifndef RESOURCE_HPP
#define RESOURCE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <iostream>
#include <string>
#include <map>

namespace dse
{
	/**
	 * Structure represents sound effect data.
	 */
	struct SoundEffect
	{
		sf::SoundBuffer buffer;
		sf::Sound sound;
	};

	typedef std::map<std::string, sf::Texture*> Textures;
	typedef std::map<std::string, sf::Music*> SoundTracks;
	typedef std::map<std::string, SoundEffect*> SoundEffects;
	typedef std::map<std::string, sf::Font*> Fonts;
	typedef std::map<std::string, sf::Shader*> Shaders;

	/**
	 * Structure represents engine resource manager.
	 */
	struct Resource
	{
		Textures textures;
		SoundTracks tracks;
		SoundEffects effects;
		Fonts fonts;
		Shaders shaders;

		Resource() {};
		~Resource() {};

		void loadTexture(const std::string& name, const std::string& path);
		void loadSound(const std::string& name, const std::string& path);
		void loadMusic(const std::string& name, const std::string& path);
		void loadFont(const std::string& name, const std::string& path);
		void loadShader(const std::string& name, const std::string& path);
	};
}
#endif
