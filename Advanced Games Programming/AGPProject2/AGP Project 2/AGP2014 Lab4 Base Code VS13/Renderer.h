#pragma once

#define NUMLIGHTS 11

#include "rt3dObjLoader.h"
#include "rt3d.h"
#include "Shaders.h"
#include "particlesList.h"
#include <unordered_map>

#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/glm.hpp>
#include <stack>
#include <vector>
#include <sstream> 
#include <ctime>
#include "Light.h"
#include <SDL_ttf.h>

using namespace std;

typedef unordered_map<std::string, GLuint> texturemap;

class Renderer
{
public:
	Renderer();
	~Renderer();

	void init();
	void update();

	void renderDepth(glm::vec3 coords, glm::vec3 size, glm::vec4 iLightPos, glm::vec3 iLightConeDirection); 
	void renderProp(string textureID, glm::vec3 coords, glm::vec3 size,glm::vec3 iLightConeDirection[], Light iLightList[], glm::vec4 iLightPosList[] );
	void renderLightProps(glm::vec4 lightPosition);
	void renderLight(Light iLightList[], glm::vec4 iLightPosList[]);
	void renderParticles(string ID, GLfloat size, glm::vec4 iLightPos);
	
	void setDepthFBO();

	void setUniform(GLuint shader, const char * uniform, int val); // sends texture to shader
	void setUniform(GLuint shader, const char * uniform, glm::vec3 val);	// used for passing attenuation values to shader
	void setUniform(GLuint shader, Light iLightList[]);	// used for passing light array to shader
	void setUniform(GLuint shader, GLfloat val1, GLfloat val2, glm::vec3 val3); // used for passing fog values to shader
	void setUniformMatrix3fv(const GLuint program, const char * uniform, const GLfloat *data);

	GLuint textToTexture(const char * str/*, TTF_Font *font, SDL_Color colour, GLuint &w,GLuint &h*/);

	float col1 = 1.0;
	float col2 = 1.5;
	float col3 = 1.0;

	ParticlesList * getParticleLight();
	
	glm::vec3 getEye();
	GLfloat getRotate();
	glm::vec3 getParticleCubePosition();
	GLuint getFBO();

	void setEye(glm::vec3 newEye);
	void setRotate(GLfloat newRotate);
	void setParticleCubePosition(glm::vec3 newParticleCubePosition);

private:
	Shaders shaderManager;
	texturemap textureMap;

	GLuint meshIndexCount;
	GLuint meshObjects[2]; // these are example sizes not all are used yet

	glm::mat4 projection;
	stack<glm::mat4> mvStack;
	GLuint size;

	vector<GLfloat> cubeVerts;
	vector<GLfloat> cubeNorms;
	vector<GLfloat> cubeTex_coords;
	vector<GLuint> cubeIndices;
	vector<GLfloat> lightVerts;
	vector<GLfloat> lightNorms;
	vector<GLfloat> lightTex_coords;
	vector<GLuint> lightIndices;

	GLuint depthFBO;
	GLfloat rotate;

	glm::vec3 eye;
	glm::vec3 at;
	glm::vec3 up;

	rt3d::lightStruct light0;
	glm::vec3 particleCubePosition;

	rt3d::materialStruct material0;
	rt3d::materialStruct material1;

	glm::mat4 biasMatrix;

	glm::vec3 attenuation;

	ParticlesList * particleLight;
	ParticlesList * particleLight1;
	ParticlesList * particleLight2;
	ParticlesList * particleLight3;

	TTF_Font * textFont;
	GLuint labels[2];
	
	// fog
	float fog1 = 0.5;
	float fog2 = 0.5;
	float fog3 = 0.5;
	GLfloat fogMaxDist;
	GLfloat fogMinDist;
	glm::vec3 fogColour;

	glm::mat4 shadow;
};

