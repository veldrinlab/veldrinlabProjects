/**
 * File contains declaraion of Configuration class.
 * @file    Configuration.hpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2011-08-06
 */

#ifndef CONFIGURATION_HPP
#define CONFIGURATION_HPP

#include "AyumiScript.hpp"
#include "Singleton.hpp"

/**
 * Class represents Ayumi Engine Configuration. It implements singleton interface
 * pattern for global, thread-safe scope. Configuration is initialize by AyumiScript Data script.
 */
class Configuration : public Singleton<Configuration>
{
	friend Singleton<Configuration>;

private:
	AyumiScript* configurationScript;
	int resolutionHeight;
	int resolutionWidth;
	int minVert;
	int maxVert;
	std::string* input;

	Configuration();
	Configuration(const Configuration& engineConfig);
	virtual ~Configuration();

	void prepareConfigScript();

public:
	void configureEngine(const std::string& scriptPath);

	int getHeight() const;
	int getWidth() const;
	int getMinVert() const;
	int getMaxVert() const;
	std::string* getInput() const;

	void setHeight(const int height);
	void setWidth(const int width);
	void setMinVert(const int min);
	void setMaxVert(const int max);
	void setInput(const std::string& name);
};
#endif
