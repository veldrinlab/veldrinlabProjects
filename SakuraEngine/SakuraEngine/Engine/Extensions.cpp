/**
 * File contains definition os Extensions class static methods.
 * @file    Extensions.cpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2011-01-05
 * @version 1.0
 */

#include "Extensions.hpp"

namespace Engine
{
/**
 * Initialize static class members.
 */
bool Extensions::vboSupported = false;
bool Extensions::shaderSupported = false;
bool Extensions::multiTextureSupported = false;

PFNGLGENBUFFERSARBPROC Extensions::glGenBuffersARB = NULL;
PFNGLBINDBUFFERARBPROC Extensions::glBindBufferARB = NULL;
PFNGLBUFFERDATAARBPROC Extensions::glBufferDataARB = NULL;
PFNGLDELETEBUFFERSARBPROC Extensions::glDeleteBuffersARB = NULL;

PFNGLCREATEPROGRAMPROC Extensions::glCreateProgram= NULL;
PFNGLCREATESHADERPROC Extensions::glCreateShader = NULL;
PFNGLSHADERSOURCEPROC Extensions::glShaderSource = NULL;
PFNGLCOMPILESHADERPROC Extensions::glCompileShader = NULL;
PFNGLATTACHSHADERPROC Extensions::glAttachShader = NULL;
PFNGLLINKPROGRAMPROC Extensions::glLinkProgram = NULL;
PFNGLUSEPROGRAMPROC Extensions::glUseProgram = NULL;
PFNGLDETACHSHADERPROC Extensions::glDetachShader = NULL;
PFNGLDELETESHADERPROC Extensions::glDeleteShader = NULL;
PFNGLDELETEPROGRAMPROC Extensions::glDeleteProgram = NULL;
PFNGLGETUNIFORMLOCATIONPROC Extensions::glGetUniformLocation = NULL;
PFNGLUNIFORM1FPROC Extensions::glUniform1f = NULL;
PFNGLUNIFORM1IPROC Extensions::glUniform1i = NULL;

PFNGLACTIVETEXTUREPROC Extensions::glActiveTexture = NULL;
PFNGLMULTITEXCOORD2FARBPROC Extensions::glMultiTexCoord2fARB = NULL;


/**
 * Method is used to get addresses of declared OpenG extensions.
 */
void Extensions::defineAllExtensions()
{
	glGenBuffersARB = (PFNGLGENBUFFERSARBPROC) SDL_GL_GetProcAddress("glGenBuffersARB");
	glBindBufferARB = (PFNGLBINDBUFFERARBPROC) SDL_GL_GetProcAddress("glBindBufferARB");
	glBufferDataARB = (PFNGLBUFFERDATAARBPROC) SDL_GL_GetProcAddress("glBufferDataARB");
	glDeleteBuffersARB = (PFNGLDELETEBUFFERSARBPROC) SDL_GL_GetProcAddress("glDeleteBuffersARB");

	glCreateProgram = (PFNGLCREATEPROGRAMPROC) SDL_GL_GetProcAddress("glCreateProgram");
    glCreateShader = (PFNGLCREATESHADERPROC)SDL_GL_GetProcAddress("glCreateShader");
    glShaderSource = (PFNGLSHADERSOURCEPROC) SDL_GL_GetProcAddress("glShaderSource");
    glCompileShader = (PFNGLCOMPILESHADERPROC)SDL_GL_GetProcAddress("glCompileShader");
    glAttachShader = (PFNGLATTACHSHADERPROC)SDL_GL_GetProcAddress("glAttachShader");
    glLinkProgram = (PFNGLLINKPROGRAMPROC)SDL_GL_GetProcAddress("glLinkProgram");
    glUseProgram = (PFNGLUSEPROGRAMPROC)SDL_GL_GetProcAddress("glUseProgram");
	glDetachShader = (PFNGLDETACHSHADERPROC)SDL_GL_GetProcAddress("glDetachShader");
	glDeleteShader = (PFNGLDELETESHADERPROC)SDL_GL_GetProcAddress("glDeleteShader");
	glDeleteProgram = (PFNGLDELETEPROGRAMPROC)SDL_GL_GetProcAddress("glDeleteProgram");

	glGetUniformLocation = (PFNGLGETUNIFORMLOCATIONPROC)SDL_GL_GetProcAddress("glGetUniformLocation");
	glUniform1f = (PFNGLUNIFORM1FPROC)SDL_GL_GetProcAddress("glUniform1f"); 
	glUniform1i = (PFNGLUNIFORM1IPROC)SDL_GL_GetProcAddress("glUniform1i");
	
	glActiveTexture = (PFNGLACTIVETEXTUREPROC)SDL_GL_GetProcAddress("glActiveTexture");
	glMultiTexCoord2fARB = (PFNGLMULTITEXCOORD2FARBPROC)SDL_GL_GetProcAddress("glMultiTexCoord2fARB");
}

/**
 * Method is used to check if extensions is supportd by User GPU.
 */
void Extensions::checkSupportedExtensions()
{
	if(glGenBuffersARB && glBindBufferARB && glBufferDataARB && glDeleteBuffersARB)
		vboSupported = true;

	if(glActiveTexture && glMultiTexCoord2fARB)
		multiTextureSupported = true;

	if(glCreateProgram && glCreateShader && glShaderSource && glCompileShader && glAttachShader && glLinkProgram
		&& glUseProgram && glDetachShader && glDeleteShader && glDeleteProgram && glGetUniformLocation
		&& glUniform1f && glUniform1i)
		shaderSupported = true;
}

}
