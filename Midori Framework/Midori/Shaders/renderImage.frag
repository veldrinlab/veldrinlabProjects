#version 330 core

uniform samplerRect ColorMapSampler;

in vec2 TexCoord;
out vec4 fragColor;

void main()
{
	fragColor = texture(ColorMapSampler,TexCoord);	
}	
