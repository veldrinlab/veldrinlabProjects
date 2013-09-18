#ifndef SEGMENT_HPP
#define SEGMENT_HPP

#include <GL/glew.h>

#include "FrameBuffer.hpp"
#include "Invariants.hpp"

namespace Midori
{
	struct Segment
	{
		GLubyte id;
		FrameBuffer data;
		int vertexAmount;
		bool isPartOfObject;
		Invariants invariants;

		bool isNFragment;
		bool isYFragment;
	};
}
#endif
