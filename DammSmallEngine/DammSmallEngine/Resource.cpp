/**
 * File contains definition of Resource structure.
 * @file    Resource.cpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2012-03-20
 */

#include "Resource.hpp"

using namespace std;
using namespace sf;

namespace dse
{
	/**
	 * Method is used to load texture resource.
	 * @param	name is resource name id.
	 * @param	path is resource file path.
	 */
	void Resource::loadTexture(const string& name, const string& path)
	{
		Texture* texture = new Texture();
		if(!texture->LoadFromFile(path))
			cerr << "Can't load texture: " << name << " " << path << endl;
		textures.insert(Textures::value_type(name, texture));
	}

	/**
	 * Method is used to load sound resource.
	 * @param	name is resource name id.
	 * @param	path is resource file path.
	 */
	void Resource::loadSound(const string& name, const string& path)
	{
		SoundEffect* effect = new SoundEffect();
		if(!effect->buffer.LoadFromFile(path))
			cerr << "Can't load sound effect: " << name << " " << path << endl;
		effect->sound.SetBuffer(effect->buffer);
		effects.insert(SoundEffects::value_type(name, effect));
	}

	/**
	 * Method is used to load music resource.
	 * @param	name is resource name id.
	 * @param	path is resource file path.
	 */
	void Resource::loadMusic(const string& name, const string& path)
	{
		sf::Music* music = new sf::Music();
		if(!music->OpenFromFile(path))
			cerr << "Can't load sound effect: " << name << " " << path << endl;
		tracks.insert(SoundTracks::value_type(name, music));
	}

	/**
	 * Method is used to load font resource.
	 * @param	name is resource name id.
	 * @param	path is resource file path.
	 */
	void Resource::loadFont(const string& name, const string& path)
	{
		sf::Font* font = new sf::Font();
		if(!font->LoadFromFile(path))
			cerr << "Can't load font: " << name <<  " " << path << endl;
		fonts.insert(Fonts::value_type(name, font));
	}

	/**
	 * Method is used to load shader resource.
	 * @param	name is resource name id.
	 * @param	path is resource file path.
	 */
	void Resource::loadShader(const string& name, const string& path)
	{
		if(sf::Shader::IsAvailable())
		{
			sf::Shader* shader = new sf::Shader();
			if(!shader->LoadFromFile(path,static_cast<sf::Shader::Type>(1)))
				cerr << "Can't load shader" << name << " " << path << endl;
			shaders.insert(Shaders::value_type(name, shader));
		}
	}
}
