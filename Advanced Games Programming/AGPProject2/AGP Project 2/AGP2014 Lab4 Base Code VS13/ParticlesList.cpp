#include "ParticlesList.h"

//constructor stored as GLfloat
ParticlesList::ParticlesList(int number, glm::vec3 pos, float colour1, float colour2, float colour3)
{
	particleOn = false;
	std::srand(time(0));
	particleList = new Particle[number];
	numParticles = number;
	positions = new GLfloat[number*3];
	colours = new GLfloat[number*3];
	velocities = new GLfloat[number*3];
	
	//creating list of velocities positions and colours as GLfloats
	for(int i=0; i<numParticles; i++)
	{
		velocities[(i*3)] = ((std::rand() % 100 ) / 10000.0f);
		velocities[(i*3)+1] = ((std::rand() % 100 ) / 10000.0f);
		velocities[(i*3)+2] = 0.3;
		particleList[i] = Particle(pos, glm::vec3(velocities[(i * 3)], velocities[(i * 3) + 1], velocities[(i * 3) + 2]), ((std::rand() % 50) + 20), glm::vec3(colour1, colour2, colour3));
		positions[(i*3)] = pos.x;
		positions[(i*3)+1] = pos.y;
		positions[(i*3)+2] = pos.z;

		colours[(i*3)] = particleList[i].getColour().x;
		colours[(i*3)+1] = particleList[i].getColour().y;
		colours[(i*3)+2] = particleList[i].getColour().z;	
	}

	//creating vao and vbo
	glGenVertexArrays(1, vao);
	glGenBuffers(2, vbo);
	glBindVertexArray(vao[0]); // bind VAO 0 as current object
	// Position data in attribute index 0, 3 floats per vertex
	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]); // bind VBO for positions
	glBufferData(GL_ARRAY_BUFFER, numParticles * 3 * sizeof(GLfloat), positions, GL_DYNAMIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0); // Enable attribute index 0
	// Colours data in attribute 1, 3 floats per vertex
	glBindBuffer(GL_ARRAY_BUFFER, vbo[1]); // bind VBO for colours
	glBufferData(GL_ARRAY_BUFFER, numParticles * 3 * sizeof(GLfloat), colours, GL_STATIC_DRAW);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(1); // Enable attribute index 1
	glBindVertexArray(0);
}

ParticlesList::~ParticlesList()
{
	delete positions;
	delete colours;
	delete particleList;
}

void ParticlesList::update(glm::vec3 cubePos)
{
	checkParticleTimer();

	for(int i=0; i<numParticles; i++)
	{
		velocities[(i*3)] = ((std::rand() % 100 ) / 10000.0f);
		velocities[(i*3)+1] = ((std::rand() % 100 ) / 10000.0f);
		velocities[(i*3)+2] = 0.3;

	}

	for(int i=0; i<numParticles;i++)
	{
		// if has life left move outwards and update positions
		if(particleList[i].getLifeTicks() > 0)
		{
			float tempX = particleList[i].getPosition().x + particleList[i].getVelocity().x;
			float tempY = particleList[i].getPosition().y + particleList[i].getVelocity().y;
			float tempZ = particleList[i].getPosition().z + particleList[i].getVelocity().z;
			particleList[i].updatePosition(particleList[i].getVelocity());
			positions[(i*3)] = particleList[i].getPosition().x;
			positions[(i*3)+1] = particleList[i].getPosition().y;
			positions[(i*3)+2] = particleList[i].getPosition().z;
		}

		if(particleOn == true && particleList[i].getLifeTicks() <=0)
		{
			// if timer is on and particles has no life left then revive
			particleList[i].reviveTick();
		}
		
		// if particle timer is off and particle has no life left then return to particle prop
		if(particleOn == false && particleList[i].getLifeTicks() <=0)
		{
			particleList[i].setPosition(cubePos);
			positions[(i*3)] = cubePos.x;
			positions[(i*3)+1] = cubePos.y;
			positions[(i*3)+2] = cubePos.z;
		}
		// sets spawn
		particleList[i].setSpawn(cubePos);
		particleList[i].update();
	}	
}


// draw particles
void ParticlesList::draw()
{
	glBindVertexArray(vao[0]);
	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]); // bind VBO 0
	glBufferData(GL_ARRAY_BUFFER, numParticles * 3 *sizeof(GLfloat), positions, GL_DYNAMIC_DRAW);
	// Position data in attribute index 0, 3 floats per vertex
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0); // Enable attribute index 0
	// Now draw the particles... as easy as this!
	glDrawArrays(GL_POINTS, 0, numParticles );
	glBindVertexArray(0);
}

// starts timer
void ParticlesList::particleTimer(int mSeconds)
{
	particleOn = true;
	alarm = 0;
	alarm = (clock() + (mSeconds));	
}

// checks if time is up
void ParticlesList::checkParticleTimer()
{
	int temp = clock();

	if(temp >= alarm) particleOn = false;
}


// returns positions
glm::vec3 ParticlesList::getPositions(int id)
{
	return glm::vec3(positions[((id-1)*3)], positions[((id-1)*3)+1], positions[((id-1)*3)+2]);
}


bool ParticlesList::getParticleOn()
{
	return particleOn;
}