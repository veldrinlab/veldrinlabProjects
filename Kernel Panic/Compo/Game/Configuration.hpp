/**
 * File contains declaration of Configuration class. 
 * @file    Configuration.hpp
 * @author  Szymon Jab³oñski
 * @date    2010-12-21
 * @version 1.0
 */

#ifndef CONFIGURATION_HPP
#define CONFIGURATION_HPP

namespace Game
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
	Configuration();

public:
	static Configuration* getInstance()
	{
		if (!instance)
			instance = new Configuration();
		return instance;
	}

	void setHeight(const int newHeight);
	int getHeight() const;
	void setWidth(const int newWidth);
	int getWidth() const;
	void setColorDepth(const int colorDepth);
	int getColorDepth() const;
	void setFullscreen(const bool option);
	bool getFullscreen() const;
};

}
#endif