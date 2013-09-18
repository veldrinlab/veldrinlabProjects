/**
 * File contains declaration of Configuration class. 
 * @file    Configuration.hpp
 * @author  Adam Sznajder
 * @date    2010-12-21
 * @version 1.0
 */

#ifndef CONFIGURATION_HPP
#define CONFIGURATION_HPP

#include "Level.hpp"

namespace game
{

/**
 * Configuration class is a singleton which is used to store all configuration data.
 */
class Configuration
{
private:
	static Configuration* instance;	
	int height;
	int width;
	short int colorDepth;
	bool fullscreen;
	Level initLevel;
	Configuration();
public:
	static Configuration* getInstance()
	{
		if (!instance)
			instance = new Configuration();
		return instance;
	}
	void setHeight(int newHeight);
	int getHeight();
	void setLevel(Level level);
	Level getLevel();
	void setWidth(int newWidth);
	int getWidth();
	void setColorDepth(int colorDepth);
	int getColorDepth();
	void setFullscreen(bool option);
	bool getFullscreen();
};

}
#endif