#version 330 core

uniform mat4 modelViewMatrix;
uniform mat4 projectionMatrix;

in vec4 vertex;
in vec2 texCoord;

out vec2 TexCoord;

void main()
{
	gl_Position = projectionMatrix*modelViewMatrix*vertex;
	TexCoord = texCoord;
}	