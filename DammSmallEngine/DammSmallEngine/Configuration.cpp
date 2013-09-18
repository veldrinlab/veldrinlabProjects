/**
 * File contains definition of Configuration class.
 * @file    Configuraton.cpp
 * @author  Szymon "Veldrin" Jab³oñski.
 * @date    2011-08-06
 */

#include "Configuration.hpp"

namespace dse
{
	/**
	 * Class default constructor. Initialize and prepares configuration script and
	 * set all class variables to default. Name of configuration script MUST be config.lua.
	 */
	Configuration::Configuration()
	{
		resolutionWidth = 800;
		resolutionHeight = 450;
		fullscreenEnabled = true;
	}

	/**
	 * Class destructor, free allocated memory for configurationScript and StateMachine state objects.
	 */
	Configuration::~Configuration()
	{

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

	bool Configuration::isFullscreenEnabled() const
	{
		return fullscreenEnabled;
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

	void Configuration::setFullscreen(const bool enabled)
	{
		this->fullscreenEnabled = enabled;
	}
}
