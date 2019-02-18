// mulitplelight.frag matching multiple light.vert
// Vertex shader for calculating multiple phong-shaded light sources
#version 330

// Some drivers require the following
precision highp float;

struct lightStruct
{
	vec4 ambient;
	vec4 diffuse;
	vec4 specular;
	vec4 position;
	vec3 coneDirection;
};

struct materialStruct
{
	vec4 ambient;
	vec4 diffuse;
	vec4 specular;
	float shininess;
};

const int numlights = 11;
uniform lightStruct lights[numlights];
uniform materialStruct material;

uniform vec3 attenuation;

in vec3 ex_Normal;
in vec3 ex_View;
in vec3 ex_Position;

layout(location = 0) out vec4 out_Color;

vec4 combineLights(lightStruct light) 
{
	// Calculate light distance
	float lightDistance = distance(light.position.xyz, ex_Position);

	// to light source from vertex
	vec3 lightDirection;

	if(light.position.w == 1.0) {
		lightDirection = normalize(light.position.xyz - ex_Position.xyz);	// point light
	} else {
		lightDirection = vec3(normalize(-light.position));	// directional light
	}

	// Calculate attenuation
	float ex_attenuation = attenuation.x + attenuation.y * lightDistance + attenuation.z * lightDistance*lightDistance;

	// Add ambient
	vec4 col = light.ambient * material.ambient;

	// Add diffuse
	vec4 diffuseI = light.diffuse * material.diffuse;
	col += diffuseI * max(dot(normalize(ex_Normal),normalize(lightDirection)),0);
	
	// Calculate R - reflection of light
	vec3 R = normalize(reflect(normalize(-lightDirection),normalize(ex_Normal)));
	
	// Add specular
	vec4 specularI = light.specular * material.specular;
	col += specularI * pow(max(dot(R,lightDirection),0), material.shininess);
	
	vec4 litColour = vec4(col.rgb / ex_attenuation, 1.0);

	litColour = min(litColour, vec4(1.0));
	return litColour;
}

void main(void) {
	// Iterate over and combine lights
	for(int i=0; i<lights.length(); i++) {
		out_Color += combineLights(lights[i]);
	}

	// Fragment colour
	out_Color = min(out_Color, vec4(1.0));
}