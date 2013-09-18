varying vec3 vertex_light_position;
varying vec3 vertex_light_half_vector;
varying vec3 vertex_normal;

void main()
{            
    	gl_TexCoord[0] = gl_MultiTexCoord0;
    
	// Calculate the normal value for this vertex, in world coordinates (multiply by gl_NormalMatrix)
	vertex_normal = normalize(gl_NormalMatrix * gl_Normal);
	// Calculate the light position for this vertex
	vertex_light_position = normalize(gl_LightSource[0].position.xyz);

	// Calculate the light's half vector
	vertex_light_half_vector = normalize(gl_LightSource[0].halfVector.xyz);

	// Set the position of the current vertex 
	gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;

}