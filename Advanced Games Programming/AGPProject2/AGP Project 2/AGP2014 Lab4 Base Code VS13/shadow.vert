
//shadow.vert

#version 330 core

// needed uniforms
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform mat4 shadow;
uniform vec3 lightPosition;
uniform mat3 normalmatrix;

// passed in from rt3d
in vec3 in_Position;
in vec3 in_Normal;
in vec2 in_TexCoord;

out vec4 shadow_coord;
out vec3 world_coord;
out vec3 eye_coord;
out vec3 ex_Normal;
out vec3 ex_View;
out vec3 ex_LightDirection;
out vec2 ex_TexCoord;
out vec3 ex_Position;

void main(void)
{

	// vertex into eye coordinates
	mat4 modelview = view*model;
	ex_Position = vec3((modelview) * vec4(in_Position,1.0));

	// Find V - in eye coordinates, eye is at (0,0,0)
	ex_View = normalize(-ex_Position).xyz;

	// Surface normal in eye coordinates
	ex_Normal = normalize(normalmatrix * in_Normal);

	// calculates position of world
	vec4 world_pos = (model * vec4(in_Position,1.0)); 

	// calculates eye positon
	vec4 eye_pos = view * world_pos; 

	// calculates clip position
	vec4 clip_pos = projection * eye_pos; 

	// world coordinates
	world_coord = world_pos.xyz; 

	// eye coordinates
	eye_coord = eye_pos.xyz;

	// coordinates of each shadow
	
	shadow_coord = (shadow * vec4(in_Position,1.0)); 

	// in tex coords are passed out
	ex_TexCoord = in_TexCoord;

	// new position is the clip position
	gl_Position = clip_pos;
}
