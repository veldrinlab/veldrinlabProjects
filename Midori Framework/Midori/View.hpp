#ifndef VIEW_HPP
#define VIEW_HPP

#include "CommonMath.hpp"

namespace Midori
{
	struct View
	{
		AyumiEngine::AyumiMath::Matrix4D modelMatrix;
		AyumiEngine::AyumiMath::Matrix4D viewMatrix;
		AyumiEngine::AyumiMath::Matrix4D projectionMatrix;
	};
}
#endif
