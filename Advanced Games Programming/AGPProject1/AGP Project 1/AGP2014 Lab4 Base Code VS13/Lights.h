#pragma once
#ifndef Lights_H
#define Lights_H

#define DEG_TO_RADIAN 0.017453293
#define NUMLIGHTS 9	// max number of lights to check for in loops

#include <SDL.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <stack>
#include <sstream> 
#include "rt3d.h"
#include "rt3dObjLoader.h"

using namespace std;

class Lights
{
public:
	Lights(void);
	~Lights(void);

	void init();
	SDL_Window * setupRC(SDL_GLContext &context);
	void run();
	void update();
	void draw(SDL_Window * window);

	void setUniform(GLuint shader, const char * uniform, glm::vec3 val); // used for passing attenuation values to shader
	void setUniform(GLuint shader, rt3d::lightStruct iLightList[]);	// used for passing light array to shader
	void setUniformMatrix3fv(const GLuint program, const char* uniformName, const GLfloat *data);

	glm::vec3 moveForward(glm::vec3 pos, GLfloat angle, GLfloat d);
	glm::vec3 moveRight(glm::vec3 pos, GLfloat angle, GLfloat d);

private:
	SDL_Window * hWindow; // window handle
	SDL_GLContext glContext; // OpenGL context handle

	int currLights = 3;
	int set1limiter = 0;
	int set2limiter = 0;

	GLuint shaderProgram;

	glm::mat4 modelview;
	glm::mat3 normalmatrix;
	stack<glm::mat4> mvStack;

	GLuint meshIndexCount;
	GLuint meshObject;

	GLfloat r;

	glm::vec3 eye;
	glm::vec3 at;
	glm::vec3 up;

	rt3d::lightStruct light0;
	rt3d::lightStruct light1;
	rt3d::lightStruct light2;
	rt3d::lightStruct light3;
	rt3d::lightStruct light4;
	rt3d::lightStruct light5;
	rt3d::lightStruct light6;
	rt3d::lightStruct light7;
	rt3d::lightStruct light8;

	glm::vec4 lightPos0;
	glm::vec4 lightPos1;
	glm::vec4 lightPos2;
	glm::vec4 lightPos3;
	glm::vec4 lightPos4;
	glm::vec4 lightPos5;
	glm::vec4 lightPos6;
	glm::vec4 lightPos7;
	glm::vec4 lightPos8;

	rt3d::lightStruct * lightList;	// set as array for holding all the lights

	glm::vec4 lightPosList[NUMLIGHTS];	// array for holding light positions

	glm::vec3 attenuation;	// vec 3 to hold constant, linear and quadratic attenuation values

	rt3d::materialStruct material0;
	rt3d::materialStruct material1;
};
#endif
