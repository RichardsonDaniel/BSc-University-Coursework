#pragma once
#ifndef SCREENGAME_H
#define SCREENGAME_H

#include <vector>
#include <iostream>
#include <stack>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "rt3d.h"

#include "Screen.h"
#include "Character.h"
#include "SkyBox.h"
#include "Environment.h"
#include "Camera.h"

#define DEG_TO_RADIAN 0.017453293

class ScreenGame : public Screen
{
public:
	ScreenGame(void);
	~ScreenGame(void);

	void draw(SDL_Window * window);
	void update();
	void checkEvents();

	glm::vec3 moveForward(glm::vec3 pos, GLfloat angle, GLfloat d) {
		return glm::vec3(pos.x + d*std::sin(angle*DEG_TO_RADIAN), pos.y, pos.z - d*std::cos(angle*DEG_TO_RADIAN));
	}

	glm::vec3 moveRight(glm::vec3 pos, GLfloat angle, GLfloat d) {
		return glm::vec3(pos.x + d*std::cos(angle*DEG_TO_RADIAN), pos.y, pos.z + d*std::sin(angle*DEG_TO_RADIAN));
	}

	// Detect and handle collisions between characters and the environment objects
	void detectCollisions(Character * character, Environment * environment);


private:
	Character * goblin; // Default starting goblin
	Character * yoshi; // Optional goblin to switch to

	Character * currentChar; // Selected character to update 

	Camera * camera;

	SkyBox * skyBox;

	Environment * ground;
	Environment * ground2;
	Environment * ground3;

	Environment * building1;
	Environment * building2;
	Environment * building3;
	Environment * building4;
	Environment * building5;
	Environment * building6;
	Environment * building7;
	Environment * building7two;
	Environment * building7three;
	Environment * building8;
	Environment * exitCover;
	Environment * exitCover2;

	Environment * road1;
	Environment * road2;
	Environment * roadConnector;

	Environment * fence1;
	Environment * fence2;
	Environment * fence3;

	Environment * collidableEnvironment[13]; // Array for only required environment objects to be collidable

	GLuint shaderProgram;
	GLuint skyBoxShader;

	std::stack<glm::mat4> mvStack; 

	bool inception;
};
#endif

