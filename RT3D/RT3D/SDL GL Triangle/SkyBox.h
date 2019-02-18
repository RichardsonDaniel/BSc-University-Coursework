#pragma once
#ifndef SKYBOX_H
#define SKYBOX_H

#include "rt3d.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <stack>

class SkyBox
{
public:
	SkyBox(void);
	~SkyBox(void);

	void init(GLuint newShaderProgram);
	void draw(std::stack<glm::mat4> &mvStack);

	GLuint getShader() { return skyBoxShader; }
private:

	GLuint skyBoxVertCount;

	GLuint skyBoxIndexCount;
	
	GLuint skyBox;

	GLuint skyBoxTexture[6];
	
	GLfloat rotateAngle;

	GLuint skyBoxShader;
};
#endif

