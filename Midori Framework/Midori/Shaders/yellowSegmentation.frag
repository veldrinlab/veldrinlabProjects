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
	
	float color = clamp(0.34f*r + 0.66f*g - 1.30f*b,0.0,1.0);
	
	//progowanie
	if(color < 0.20f)
		color = 0.0f;
	else
		color = 1.0;
		
	//dla test 2 && test4 -> 0.20f
	//dlat test 1 -> 0.15f
	
	
	fragColor = vec4(color,color,color,1.0);
}	
