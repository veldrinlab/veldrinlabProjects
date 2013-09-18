/**
 * File contains declaraion of Configuration class.
 * @file    Configuration.hpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2011-08-06
 */

#ifndef CONFIGURATION_HPP
#define CONFIGURATION_HPP

#include "Singleton.hpp"

namespace dse
{
	/**
	 * Class represents Ayumi Engine Configuration. It implements singleton interface
	 * pattern for global, thread-safe scope. Configuration is initialize by AyumiScript Data script.
	 */
	class Configuration : public Singleton<Configuration>
	{
		friend Singleton<Configuration>;

	private:
		int resolutionHeight;
		int resolutionWidth;
		bool fullscreenEnabled;

		Configuration();
		Configuration(const Configuration& engineConfig);
		virtual ~Configuration();

	public:
		int getHeight() const;
		int getWidth() const;
		bool isFullscreenEnabled() const;
		void setHeight(const int height);
		void setWidth(const int width);
		void setFullscreen(const bool full);
	};
}
#endif
