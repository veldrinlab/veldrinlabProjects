/**
 * File contains decalration of Extensions class.
 * @file    Extensions.hpp
 * @author  Szymon "Veldrin" Jab³oñski	
 * @date    2011-01-05
 * @version 1.0
 */

#ifndef EXTENSIONS_HPP
#define EXTENSIONS_HPP

#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include <GL/gl.h>

#include "../glext.h"

namespace Engine
{

/**
 * Class is used to initialize, vrificate and store OpenGL Extensions for such effects like shaders, Vertex Buffer
 * Objects and multi-texturing.
 */
class Extensions
{
public:
	static bool vboSupported;
	static bool shaderSupported;
	static bool multiTextureSupported;

	// VBO extensions
	static PFNGLGENBUFFERSARBPROC glGenBuffersARB;
	static PFNGLBINDBUFFERARBPROC glBindBufferARB;
	static PFNGLBUFFERDATAARBPROC glBufferDataARB;
	static PFNGLDELETEBUFFERSARBPROC glDeleteBuffersARB;

	// Shaders extensions
	static PFNGLCREATEPROGRAMPROC glCreateProgram;
	static PFNGLCREATESHADERPROC glCreateShader;
	static PFNGLSHADERSOURCEPROC glShaderSource;
	static PFNGLCOMPILESHADERPROC glCompileShader;
	static PFNGLATTACHSHADERPROC glAttachShader;
	static PFNGLDETACHSHADERPROC glDetachShader;
	static PFNGLDELETESHADERPROC glDeleteShader;
	static PFNGLDELETEPROGRAMPROC glDeleteProgram;
	static PFNGLLINKPROGRAMPROC glLinkProgram;
	static PFNGLUSEPROGRAMPROC glUseProgram;
	static PFNGLGETUNIFORMLOCATIONPROC glGetUniformLocation;
	static PFNGLUNIFORM1FPROC glUniform1f;
	static PFNGLUNIFORM1IPROC glUniform1i;

	//multi-texturing
	static PFNGLACTIVETEXTUREPROC glActiveTexture;
	static PFNGLMULTITEXCOORD2FARBPROC glMultiTexCoord2fARB;

	static void defineAllExtensions();
	static void checkSupportedExtensions();
};

}
#endif
