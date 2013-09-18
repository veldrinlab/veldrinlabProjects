#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <GL/glew.h>

#include "Texture.hpp"
#include "Shader.hpp"

namespace Midori
{
	struct Image
	{
		GLuint vertexBuffer;
		GLuint indicesBuffer;
		GLuint vao;
		Texture* texture;
		Shader* shader;
	};
}
#endif
