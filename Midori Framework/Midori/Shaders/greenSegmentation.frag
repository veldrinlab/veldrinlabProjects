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
	
	//test1
	//float color = clamp(2.0f*g - 2.0f*r -0.3f*b,0.0,1.0);
	//test2 && test4 super
	
	float color = clamp(2.0f*g - 2.0f*r -0.65f*b,0.0,1.0);
	
	//test3
	//float color = clamp(2.0f*g - 2.0f*r -0.45f*b,0.0,1.0);
	
	
	//progowanie
//	float prog = 30.0f/255.0f;
	if(color < 0.4f)
		color = 0.0f;
	else
		color = 1.0;
		
	// test1 - 0.2f
	// test2 - 0.4f && test4
		
	fragColor = vec4(color,color,color,1.0);
}	
