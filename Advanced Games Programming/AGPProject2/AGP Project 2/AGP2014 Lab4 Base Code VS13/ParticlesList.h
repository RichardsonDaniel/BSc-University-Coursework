#pragma once
#include "Particle.h"
#include <iostream>
#include <time.h>
#include <GL\glew.h>

class ParticlesList
{
public:
	ParticlesList(int number, glm::vec3 pos, float colour1, float colour2, float colour3);
	~ParticlesList();
	void update(glm::vec3 cubePos);
	void draw();
	void particleTimer(int mSeconds);
	void checkParticleTimer();
	glm::vec3 getPositions(int id);
	bool getParticleOn();

private:
	int numParticles;
	Particle * particleList;
	GLuint vao[1];
	GLuint vbo[2];
	GLfloat * positions;
	GLfloat * colours;
	GLfloat * velocities;
	int alarm;
	bool particleOn;
};

