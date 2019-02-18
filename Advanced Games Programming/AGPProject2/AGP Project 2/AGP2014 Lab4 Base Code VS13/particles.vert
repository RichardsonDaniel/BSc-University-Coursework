// Vertex Shader – file "particles.vert"

#version 330

uniform mat4 modelview;
uniform mat4 projection;

in  vec3 in_Position;
in  vec3 in_Color;
out vec3 ex_Color;

void main(void)
{

	mat4 MVP = projection*modelview;
	ex_Color = in_Color;
	gl_Position = MVP * vec4(in_Position, 1.0);
}