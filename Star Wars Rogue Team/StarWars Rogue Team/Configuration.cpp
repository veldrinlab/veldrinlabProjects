#include "Configuration.hpp"

namespace game
{

Configuration* Configuration::instance = 0L;

/**
 * Constructor.
 */
Configuration::Configuration()
{
	height = 600;
	width = 800;
	colorDepth = 16;
	fullscreen = false;
}

/**
 * Setter of height variable.
 * @param	newHeight is the new height to set.
 */
void Configuration::setHeight(int newHeight)
{
	height = newHeight;
}

/**
 * Setter of width variable.
 * @param	newWidth is the new width to set.
 */
void Configuration::setWidth(int newWidth)
{
	width = newWidth;
}

/**
 * Setter of fullscreen variable.
 * @param	option is the new fullscreen flag to set.
 */
void Configuration::setFullscreen(bool option)
{
	fullscreen = option;
}

/**
 * Setter of colorDepth variable.
 * @param	newDepth is the new color depth to set.
 */
void Configuration::setColorDepth(int newDepth)
{
	colorDepth = newDepth;
}

/**
 * Accessor to height variable.
 * @return	current height.
 */
int Configuration::getHeight()
{
	return height;
}

/**
 * Accessor to width variable.
 * @return	current width.
 */
int Configuration::getWidth()
{
	return width;
}

/**
 * Accessor to fullscreen variable.
 * @return current fullscreen flag.
 */
bool Configuration::getFullscreen()
{
	return fullscreen;
}

/**
 * Accessor to colorDepth variable.
 * @return current color depth.
 */
int Configuration::getColorDepth()
{
	return colorDepth;
}

/**
 * Setter of initLevel variable.
 * @param	level is the new value of initLevel to set.
 */
void Configuration::setLevel(Level level)
{
	initLevel = level;
}

/**
 * Accessor to initLevel variable.
 * @return	current level.
 */
Level Configuration::getLevel()
{
	return initLevel;
}

}