
//shadow.frag

#version 330

struct materialStruct
{
	vec4 ambient;
	vec4 diffuse;
	vec4 specular;
	float shininess;
};

struct lightStruct
{
	vec4 ambient;
	vec4 diffuse;
	vec4 specular;
	vec4 position;
	vec3 coneDirection;
	float coneFallOff;
	vec3 attenuation;
	int active;
	int type;
};

struct fogStruct
{
	float maxDist;
	float minDist;
	vec3 color;
};

uniform sampler2DShadow depthTexture;
uniform sampler2D textureUnit0;

const int NUMLIGHTS = 11;
uniform lightStruct lights[NUMLIGHTS];

uniform materialStruct material;
uniform vec3 attenuation;

uniform fogStruct fog;

in vec4 shadow_coord;
in vec3 world_coord;
in vec3 eye_coord;
in vec3 ex_LightDirection;
in vec3 ex_View;
in vec3 ex_Normal;
in vec2 ex_TexCoord;
in vec3 ex_Position;

out vec4 out_Color;

vec4 ambientI;
vec4 col;
vec4 litColour;
float depthProj;

vec4 combineLights(lightStruct light)
{
	if(light.active == 1) {
		// Calculate light distance
		float lightDistance = distance(light.position.xyz, ex_Position);

		// Calculate light direction
		//vec3 lightDirection = normalize(light.position.xyz - ex_Position.xyz);


		// to light source from vertex
		vec3 lightDirection;
		if(light.type != 2) {
			lightDirection = normalize(light.position.xyz - ex_Position.xyz);	// point and spot light
		} else {
			lightDirection = vec3(normalize(light.position));	// directional light
		}
	

		// Calculate attenuation
		float ex_attenuation = 1 / light.attenuation.x + light.attenuation.y * lightDistance + light.attenuation.z * lightDistance*lightDistance;

		// Ambient intensity
		ambientI = light.ambient * material.ambient;
	
		// Diffuse intensity
		vec4 diffuseI = light.diffuse * material.diffuse;
	
		if(light.type == 1)
		{
			if((dot(lightDirection, -light.coneDirection.xyz)) > light.coneFallOff)
			{

				col += diffuseI * max(dot(normalize(ex_Normal),normalize(ex_LightDirection)),0.0);

				// Calculate R - reflection of light
				vec3 R = reflect(normalize(-lightDirection),normalize(ex_Normal));
	
				// Specular intensity
				vec4 specularI = light.specular * material.specular;
				col += specularI * pow(max(dot(R,lightDirection),0), material.shininess);

				litColour = vec4(col.rgb / ex_attenuation, 1.0);	
			}
			else
			{
				litColour = vec4(0.0f, 0.0f, 0.0f, 1.0f);
			}
		} 
		else
		{
			col += diffuseI * max(dot(normalize(ex_Normal),normalize(ex_LightDirection)),0.0);

			// Calculate R - reflection of light
			vec3 R = reflect(normalize(-lightDirection),normalize(ex_Normal));
	
			// Specular intensity
			vec4 specularI = light.specular * material.specular;
			col += specularI * pow(max(dot(R,lightDirection),0), material.shininess);

			litColour = vec4(col.rgb / ex_attenuation, 1.0);
		}
	} else
	{
		litColour = vec4(0.0f, 0.0f, 0.0f, 1.0f);
	}

	return litColour;
}

void main(void)
{
	vec4 combinedColor = vec4(0.0);

	// Iterate over and combine lights
	for(int i = 0; i < NUMLIGHTS; i++) 
	{
		combinedColor += combineLights(lights[i]);	
	}

	float dist = abs(ex_Position.z);
	float fogFactor = (fog.maxDist - dist) / (fog.maxDist - fog.minDist);
	fogFactor = clamp(fogFactor, 0.0, 1.0);

	depthProj = textureProj(depthTexture, shadow_coord);

	vec4 finalcolor = combinedColor * depthProj;
	
	vec4 shadowedcolor = ((ambientI + finalcolor) * texture(textureUnit0, ex_TexCoord));

	vec3 color = mix(fog.color, vec3(shadowedcolor), fogFactor);

	out_Color = min(vec4(color, 1.0), vec4(1.0));
}