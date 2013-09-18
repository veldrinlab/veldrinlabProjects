/**
 * File contains definition of Configuration class.
 * @file    Configuraton.cpp
 * @author  Szymon "Veldrin" Jab³oñski.
 * @date    2011-08-06
 */

#include "Configuration.hpp"

using namespace std;
using namespace boost;


/**
 * Class default constructor. Initialize and prepares configuration script and
 * set all class variables to default. Name of configuration script MUST be config.lua.
 */
Configuration::Configuration()
{
	configurationScript = new AyumiScript("null");
	resolutionHeight = 1024;
	resolutionWidth = 768;
	minVert = 100;
	maxVert = 100000;
	prepareConfigScript();
}

/**
 * Class destructor, free allocated memory for configurationScript and StateMachine state objects.
 */
Configuration::~Configuration()
{
	delete configurationScript;
}

/**
 * Private method which is used to prepare configuration script. By using Luabind engine register Configuration class
 * to Lua namespace and bind global pointer to engine configuration object.
 */
void Configuration::prepareConfigScript()
{
	luabind::module(configurationScript->getVirtualMachine())
	[
		luabind::class_<Configuration>("Configuration")
		.def("setWidth",&Configuration::setWidth)
		.def("setHeight",&Configuration::setHeight)
		.def("setMinVert",&Configuration::setMinVert)
		.def("setMaxVert",&Configuration::setMaxVert)
		.def("setInput",&Configuration::setInput)
	];

	luabind::globals(configurationScript->getVirtualMachine())["Config"] = this;
}

/**
 * Method is used to execute configuration script. Need to be called only once. After that user can configure engine
 * by seeter methods from game code, for example Options menu.
 * @param	name is 
 */
void Configuration::configureEngine(const string& scriptPath)
{
	configurationScript->setScriptFile(scriptPath.c_str());
	configurationScript->executeScript();
}

/**
 * Accessor to resolution height private member.
 * @return	resolution height value.
 */
int Configuration::getHeight() const
{
	return resolutionHeight;
}

/**
 * Accessor to resolution width private member.
 * @return	resolution width value.
 */
int Configuration::getWidth() const
{
	return resolutionWidth;
}

int Configuration::getMinVert() const
{
	return minVert;
}

int Configuration::getMaxVert() const
{
	return maxVert;
}

string* Configuration::getInput() const
{
	return input;
}
		
/**
 * Setter for private resolution height member.
 * @param	height is new constant resolution height value.
 */
void Configuration::setHeight(const int height)
{
	this->resolutionHeight = height;
}

/**
 * Setter for private resolution width member.
 * @param	width is new constant resolution width value.
 */
void Configuration::setWidth(const int width)
{
	this->resolutionWidth = width;
}

void Configuration::setMinVert(const int min)
{
	this->minVert = min;
}

void Configuration::setMaxVert(const int max)
{
	this->maxVert = max;
}

void Configuration::setInput(const string& name)
{
	input = new string(name);
}
