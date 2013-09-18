#ifndef FRAMEBUFFER_HPP
#define FRAMEBUFFER_HPP

#include <GL/glew.h>

namespace Midori
{
	struct FrameBuffer
	{
		GLuint frameBuffer;
		GLuint colorBuffer;	
	};
}
#endif
