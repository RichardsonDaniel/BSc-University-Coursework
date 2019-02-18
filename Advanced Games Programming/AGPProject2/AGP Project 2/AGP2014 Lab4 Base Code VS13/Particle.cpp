#include "Particle.h"

Particle::Particle()
{
}

//overloaded constructor
Particle::Particle(glm::vec3 pos, glm::vec3 vel, int life, glm::vec3 colo)
{
	position = pos;
	velocity = glm::vec3(vel.x, vel.y, vel.z);
	lifeTick = life;
	lifeCount = life;
	colour = colo;
}

Particle::~Particle()
{
}

// brigns particle back to life and sets spawn
void Particle::reviveTick()
{
	position = spawn;
	lifeTick = lifeCount;
}

// updates spawn
void Particle::setSpawn(glm::vec3 pos)
{
	spawn = pos;
}

// set position for particle
void Particle::setPosition(glm::vec3 pos)
{
	position = pos;
}

// adds velocity to position
void Particle::updatePosition(glm::vec3 vel)
{
	position += vel;
}

// life goes down on update
void Particle::update()
{
	lifeTick--;
}

// return position
glm::vec3 Particle::getPosition()
{
	return position;
}

// return velocity
glm::vec3 Particle::getVelocity()
{
	return velocity;
}

// return colour
glm::vec3 Particle::getColour()
{
	return colour;
}

// return lifeticks
int Particle::getLifeTicks()
{
	return lifeTick;
}