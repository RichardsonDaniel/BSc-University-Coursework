// mulitplelight.vert matching multiplelight.frag
// Vertex shader for calculating multiple phong-shaded light sources
#version 330

uniform mat4 modelview;
uniform mat4 projection;
uniform mat3 normalmatrix;

in  vec3 in_Position;
in  vec3 in_Normal;
out vec3 ex_Normal;
out vec3 ex_View;
out vec3 ex_Position;

void main(void) {

	// vertex into eye coordinates
	ex_Position = vec3(modelview * vec4(in_Position,1.0));

	// Find View - in eye coordinates, eye is at (0,0,0)
	ex_View = normalize(-ex_Position).xyz;

	// surface normal in eye coordinates
	ex_Normal = normalize(normalmatrix * in_Normal);

    gl_Position = projection * vec4(ex_Position, 1.0);	
}