#version 330 core

uniform samplerRect ColorMapSampler;

uniform float color;

in vec2 TexCoord;
out vec4 fragColor;

void main()
{
	vec4 c = texture(ColorMapSampler,TexCoord);
	fragColor = vec4(0.0,0.0,0.0,1.0);
	if(c.x == color)
		fragColor = vec4(1.0,1.0,1.0,1.0);
}	
