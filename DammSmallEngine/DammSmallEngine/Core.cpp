/**
 * File contains definition of Core structure.
 * @file    Core.cpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2012-03-20
 */

#include "Core.hpp"

using namespace sf;
using namespace std;

namespace dse
{
	/**
	 * Class default constructor.
	 */
	Core::Core()
	{
		timer = new Timer();
		resources = new Resource();
	}

	/**
	 * Class destructor, free allocated memory.
	 */
	Core::~Core()
	{
		delete resources;
		delete timer;
		delete window;
		delete view;
	}

	/**
	 * Method is used to create application window.
	 */
	void Core::createWindow()
	{
		const int width = Configuration::getInstance()->getWidth();
		const int height = Configuration::getInstance()->getHeight();
		const bool isFull = Configuration::getInstance()->isFullscreenEnabled();
		if(isFull)
			window = new RenderWindow(VideoMode(width,height,32),"DammSmallEngine", Style::Fullscreen, ContextSettings());
		else
			window = new RenderWindow(VideoMode(width,height,32),"DammSmallEngine", Style::Close, ContextSettings());
	}

	/**
	 * Method is used to configure engine view.
	 */
	void Core::configureView()
	{
		const float width = static_cast<float>(Configuration::getInstance()->getWidth());
		const float height = static_cast<float>(Configuration::getInstance()->getHeight());	
		view = new sf::View(sf::FloatRect(0, 0, width, height));
		window->SetView(*view);
	}

	/**
	 * Method is used to initialize engine core.
	 */
	void Core::initializeCore()
	{
		createWindow();
		configureView();
	}

	/**
	 * Method is used to get texture resource.
	 * @param	name is texture id.
	 * @return	pointer to texture resource.
	 */
	Texture* Core::getTexture(const string& name)
	{
		Textures::const_iterator it = resources->textures.find(name);

		if(it != resources->textures.end())
			return it->second;
		else
		{
			cerr << "Can't get texture: " << name << endl;
			return nullptr;
		}
	}

	/**
	 * Method is used to get font resource.
	 * @param	name is font id.
	 * @return	pointer to font resource.
	 */
	Font* Core::getFont(const string& name)
	{
		Fonts::const_iterator it = resources->fonts.find(name);

		if(it != resources->fonts.end())
			return it->second;
		else
		{
			cerr << "Can't get font: " << name << endl;
			return nullptr;
		}
	}

	/**
	 * Method is used to get shader resource.
	 * @param	name is shader id.
	 * @return	pointer to shader resource.
	 */
	sf::Shader* Core::getShader(const string& name)
	{
		Shaders::const_iterator it = resources->shaders.find(name);

		if(it != resources->shaders.end())
			return it->second;
		else
		{
			cerr << "Can't get shader: " << name << endl;
			return nullptr;
		}
	}
	
	/**
	 * Method is used to play music.
	 * @param	name is music id.
	 */
	void Core::playMusic(const string& name)
	{
		if(resources->tracks[name] != nullptr)
			resources->tracks[name]->Play();
	}

	/**
	 * Method is used to stop music.
	 * @param	name is music id.
	 */
	void Core::stopMusic(const string& name)
	{
		if(resources->tracks[name] != nullptr)
			resources->tracks[name]->Stop();
	}

	/**
	 * Method is used to play effect.
	 * @param	name is sound effect id.
	 */
	void Core::playSoundEffect(const string& name)
	{
		if(resources->effects[name] != nullptr)
			resources->effects[name]->sound.Play();
	}

	/**
	 * Method is used to stop effect.
	 * @param	name is sound effect id.
	 */
	void Core::stopSoundEffect(const string& name)
	{
		if(resources->effects[name] != nullptr)
			resources->effects[name]->sound.Stop();
	}
}
