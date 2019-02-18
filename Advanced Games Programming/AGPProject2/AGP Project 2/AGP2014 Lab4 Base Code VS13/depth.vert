// Vertex Shader – file "depth.vert"

#version 330

uniform mat4 modelview;
uniform mat4 projection;

in  vec3 in_Position;
in  vec3 in_Color;
out vec3 ex_Color;

void main(void)
{
// simple vert that uses in colour as out colour and multiplies position
	mat4 MVP = projection*modelview;
	ex_Color = in_Color;
	gl_Position = MVP * vec4(in_Position, 1.0);
}