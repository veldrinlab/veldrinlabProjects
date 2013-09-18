#version 330 core

uniform samplerRect ColorMapSampler;

in vec2 TexCoord;
out vec4 fragColor;

void main()
{
	float r = texture(ColorMapSampler, TexCoord).r;
	float g = texture(ColorMapSampler, TexCoord).g;
	float b = texture(ColorMapSampler, TexCoord).b; 
	
	float gray = (r + g + b)/3.0f;
	
	float color = clamp(2.0f*r - 2.0f*g -2.0f*b,0.0,1.0);
	
	//progowanie
	if(color < 0.3f)
		color = 0.0f;
	else
		color = 1.0;
		
	fragColor = vec4(color,color,color,1.0);
}	
