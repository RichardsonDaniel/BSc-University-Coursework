#pragma once
#include <glm\glm.hpp>

class Particle
{
public:
	Particle();
	Particle(glm::vec3 pos, glm::vec3 vel, int life, glm::vec3 colo);
	~Particle();
	void reviveTick();
	void setSpawn(glm::vec3 pos);
	void setPosition(glm::vec3 pos);
	void updatePosition(glm::vec3 vel);
	void update();
	glm::vec3 getPosition();
	glm::vec3 getColour();
	glm::vec3 getVelocity();
	int getLifeTicks();

private:
	glm::vec3 position;
	glm::vec3 velocity;
	glm::vec3 colour;
	int lifeTick;
	int lifeCount;
	bool active;
	glm::vec3 spawn;
	
};

