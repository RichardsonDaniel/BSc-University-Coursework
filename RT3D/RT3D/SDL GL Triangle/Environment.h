#pragma once
#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include "rt3d.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <stack>
#include "rt3dObjLoader.h"
#include "rect.h"

class Environment
{
public:
	// Type(building, fence..), texture, object file, Position xyz, Scale xyz, Rotation, Shader program
	Environment(std::string typeName, char *fnameTexture, char *fobj, GLfloat idx, GLfloat idy, GLfloat idz, GLfloat iscaleX, GLfloat iscaleY, GLfloat iscaleZ, GLfloat iRotate, GLuint newShaderProgram);
	~Environment(void);

	void draw(std::stack<glm::mat4> &mvStack);

	rect getRect(); // Return collision rectangle

private:
	GLuint shaderProgram;
	GLuint meshIndexCount;
	GLuint meshObject;
	GLuint texture;

	glm::vec3 pos;
	glm::vec3 scale;
	GLfloat scaleX, scaleY, scaleZ;
	GLfloat rotateAngle;

	rect r;

	std::string type;
};
#endif

