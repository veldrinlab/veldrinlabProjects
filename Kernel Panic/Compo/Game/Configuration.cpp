/**
 * File contains definition of Configuration class. 
 * @file    Configuration.hpp
 * @author  Szymon Jab³oñski
 * @date    2010-12-21
 * @version 1.0
 */

#include "Configuration.hpp"

namespace Game
{

/**
 * Static member init.
 */
Configuration* Configuration::instance = 0L;

/**
 * Constructor.
 */
Configuration::Configuration()
{
	height = 768;
	width = 1024;
	colorDepth = 32;
	fullscreen = false;
}

/**
 * Setter of height variable.
 * @param	newHeight is the new height to set.
 */
void Configuration::setHeight(const int newHeight)
{
	height = newHeight;
}

/**
 * Setter of width variable.
 * @param	newWidth is the new width to set.
 */
void Configuration::setWidth(const int newWidth)
{
	width = newWidth;
}

/**
 * Setter of fullscreen variable.
 * @param	option is the new fullscreen flag to set.
 */
void Configuration::setFullscreen(const bool option)
{
	fullscreen = option;
}

/**
 * Setter of colorDepth variable.
 * @param	newDepth is the new color depth to set.
 */
void Configuration::setColorDepth(const int newDepth)
{
	colorDepth = newDepth;
}

/**
 * Accessor to height variable.
 * @return	current height.
 */
int Configuration::getHeight() const
{
	return height;
}

/**
 * Accessor to width variable.
 * @return	current width.
 */
int Configuration::getWidth() const
{
	return width;
}

/**
 * Accessor to fullscreen variable.
 * @return current fullscreen flag.
 */
bool Configuration::getFullscreen() const
{
	return fullscreen;
}

/**
 * Accessor to colorDepth variable.
 * @return current color depth.
 */
int Configuration::getColorDepth() const
{
	return colorDepth;
}

}