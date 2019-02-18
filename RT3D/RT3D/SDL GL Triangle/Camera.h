#pragma once
#ifndef CAMERA_H
#define CAMERA_H

#include "rt3d.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Character.h"

class Camera
{
public:
	Camera();
	~Camera(void);

	void update();
	void setFocus(Character * newFocus) { focus = newFocus; } // Changing focus of camera

	glm::vec3 getEye() { return eye; }
	glm::vec3 getAt() { return at; }
	glm::vec3 getUp() { return up; }

	void setEye(GLfloat newEye) { eye.y = newEye; }
	GLfloat getTempY() { return tempY; }

	glm::vec3 moveForward(glm::vec3 pos, GLfloat angle, GLfloat d) {
		return glm::vec3(pos.x + d*std::sin(angle*DEG_TO_RADIAN), pos.y, pos.z - d*std::cos(angle*DEG_TO_RADIAN));
	}

	glm::vec3 moveRight(glm::vec3 pos, GLfloat angle, GLfloat d) {
		return glm::vec3(pos.x + d*std::cos(angle*DEG_TO_RADIAN), pos.y, pos.z + d*std::sin(angle*DEG_TO_RADIAN));
	}
	
private:
	glm::vec3 eye;
	glm::vec3 at;
	glm::vec3 up;
	GLfloat tempY;
	Character * focus;
};
#endif

