#ifndef MIDORIAPI_HPP
#define MIDORIAPI_HPP

#include <iostream>
#include <fstream>
#include <string>

#include "Window.hpp"
#include "View.hpp"
#include "Image.hpp"
#include "Shader.hpp"
#include "Vertex.hpp"
#include "DefinedData.hpp"
#include "FrameBuffer.hpp"
#include "Configuration.hpp"

#define WIDTH  1024
#define HEIGHT 768
#define MIN_VERTEX 100
#define MAX_VERTEX 100000

namespace Midori
{
	void createWindow(Midori::Window* app);
	void configureContext();
	void configureView(Midori::View* view);

	void loadTexture(Midori::Texture* texture, const std::string& path);
	void releaseTexture(Midori::Texture* texture);

	void loadShader(Midori::Shader* shader, const std::string& vertex, const std::string& fragment); 
	void releaseShader(Midori::Shader* shader);
	char* loadShaderSource(const char* shaderFileName);

	void createImage(Midori::Image* image, Midori::Texture* texture, Midori::Shader* shader);
	void releaseImage(Midori::Image* image);

	void createFrameBuffer(Midori::FrameBuffer* fbo, const int width, const int height);
	void releaseFrameBuffer(Midori::FrameBuffer* fbo);

	void renderImage(Midori::Image* image, Midori::View* view, bool rotated = false);
	void renderToTexture(Midori::FrameBuffer* fbo, Midori::Image* image, Midori::View* view, Midori::Shader* shader);
	void renderSegmentToTexture(Midori::FrameBuffer* fbo, Midori::Image* image, Midori::View* view, Midori::Shader* shader, FrameBuffer* frames, GLfloat color);
}
#endif
