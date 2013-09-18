#ifndef EXTENSIONS_H
#define EXTENSIONS_H

#include <SDL.h>
#include <SDL_opengl.h>
#include <GL/gl.h>

#include "glext.h"

/**
 * @remarsk	dodac sprawdzanie dostepnosci danej grupy rozszerzeñ.
 */
class Extensions
{
public:
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

	static void defineAllExtensions();

};
#endif
