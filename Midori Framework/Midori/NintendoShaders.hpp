#ifndef NINTENDOSHADERS_HPP
#define NINTENDOSHADERS_HPP

#include "MidoriApi.hpp"

namespace Midori
{
	struct NintendoShaders
	{
		Shader renderImage;
		Shader redSegmentation;
		Shader blueSegmentation;
		Shader greenSegmentation;
		Shader yellowSegmentation;
		Shader segmentFilter;
	};
}
#endif
