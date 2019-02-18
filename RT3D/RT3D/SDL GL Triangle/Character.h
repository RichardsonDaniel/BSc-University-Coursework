#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H

#include "rt3d.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <stack>
#include "md2model.h"
#include "rect.h"

#define DEG_TO_RADIAN 0.017453293

class Character
{
public:
	// Texture, mesh, Position for xyz, Scale for xyz, shader program
	Character(char *fnameTexture, char *fnameMesh, GLfloat idx, GLfloat idy, GLfloat idz, GLfloat iScaleX, GLfloat iScaleY, GLfloat iScaleZ, GLuint newShaderProgram);
	~Character(void);
	void init();
	void draw(std::stack<glm::mat4> &mvStack);
	void update();

	glm::vec3 getPos() { return pos; }
	void setPos(glm::vec3 newpos) { pos = newpos; }

	void setRotate(GLfloat newRotate) { rotateAngle = newRotate; }
	GLfloat getRotate() { return rotateAngle; }

	rect getRect(); // Get collision rectangle
	bool collidingWith(rect &r); // Check if colliding

	GLfloat getMoveValue() { return moveValue; }
	void setMoveValue(GLfloat newValue) { moveValue = newValue; }

	glm::vec3 moveForward(glm::vec3 pos, GLfloat angle, GLfloat d) {
		return glm::vec3(pos.x + d*std::sin(angle*DEG_TO_RADIAN), pos.y, pos.z - d*std::cos(angle*DEG_TO_RADIAN));
	}

	glm::vec3 moveRight(glm::vec3 pos, GLfloat angle, GLfloat d) {
		return glm::vec3(pos.x + d*std::cos(angle*DEG_TO_RADIAN), pos.y, pos.z + d*std::sin(angle*DEG_TO_RADIAN));
	}
	
private:
	GLuint vertCount;
	md2model tmpModel;
	GLuint meshObject;
	GLuint texture;
	GLuint shaderProgram;

	glm::vec3 pos;
	GLfloat moveValue;
	glm::vec3 scale;
	int currentAnim;
	GLfloat rotateAngle;

	rect r;
};
#endif

