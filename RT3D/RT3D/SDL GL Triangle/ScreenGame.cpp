#include "ScreenGame.h"

rt3d::lightStruct light0 = {
	{0.3f, 0.3f, 0.3f, 1.0f}, // ambient
	{1.0f, 1.0f, 1.0f, 1.0f}, // diffuse
	{1.0f, 1.0f, 1.0f, 1.0f}, // specular
	{-10.0f, 10.0f, 10.0f, 1.0f}  // position
};

glm::vec4 lightPos(-10.0f, 10.0f, 10.0f, 1.0f); //light position

rt3d::materialStruct material0 = {
	{0.2f, 0.4f, 0.2f, 1.0f}, // ambient
	{0.5f, 1.0f, 0.5f, 1.0f}, // diffuse
	{0.0f, 0.1f, 0.0f, 1.0f}, // specular
	2.0f  // shininess
};

rt3d::materialStruct material1 = {
		{0.4f, 0.4f, 1.0f, 1.0f}, // ambient
		{0.8f, 0.8f, 1.0f, 1.0f}, // diffuse
		{0.8f, 0.8f, 0.8f, 1.0f}, // specular
		1.0f  // shininess
};

ScreenGame::ScreenGame(void)
{
	// Load shader programs
	shaderProgram = rt3d::initShaders("phong-tex.vert","phong-tex.frag");
	skyBoxShader = rt3d::initShaders("textured.vert", "textured.frag");

	rt3d::setLight(shaderProgram, light0);
	rt3d::setMaterial(shaderProgram, material0);

	// Next few lines creates and initialises all visible objects, the camera and array of collidables
	goblin = new Character("Resources/hobgoblin.bmp", "Resources/hobgoblin.md2", -7.0f, 0.5f, -0.10f, 0.025f, 0.025f, 0.025f, shaderProgram);
	yoshi = new Character("Resources/yoshi.bmp", "Resources/yoshi.md2", 25.0f, 0.5f, -0.5f, 0.025f, 0.025f, 0.025f, shaderProgram);

	skyBox = new SkyBox();
	skyBox->init(skyBoxShader);
	
	ground = new Environment("ground", "Resources/ground.bmp", "Resources/cube.obj", -10.0f, -0.1f, -10.0f, 30.0f, 0.1f, 7.0f, 0.0f, shaderProgram);
	ground2 = new Environment("ground", "Resources/ground.bmp", "Resources/cube.obj", -10.0f, -0.1f, 7.0f, 20.0f, 0.1f, 20.0f, 0.0f, shaderProgram);
	ground3 = new Environment("ground", "Resources/ground.bmp", "Resources/cube.obj", 20.0f, -0.1f, -10.0f, 10.0f, 0.1f, 40.0f, 0.0f, shaderProgram);

	building1 = new Environment("building", "Resources/building1.bmp", "Resources/cube.obj", -10.0f, -15.0f, -10.0f, 10.0f, 10.0f, 10.0f, 90.0f, shaderProgram);
	building2 = new Environment("building", "Resources/building2.bmp", "Resources/cube.obj", 2.0f, -15.0f, -18.0f, 10.0f, 10.0f, 18.0f, 90.0f, shaderProgram);
	building3 = new Environment("building", "Resources/building3.bmp", "Resources/cube.obj", 0.0f, 20.0f, -8.0f, 10.0f, 12.0f, 10.0f, 90.0f, shaderProgram);
	building4 = new Environment("building", "Resources/building4.bmp", "Resources/cube.obj", -10.0f, 20.0f, -7.0f, 10.0f, 10.0f, 10.0f, 90.0f, shaderProgram);
	building5 = new Environment("building", "Resources/building5.bmp", "Resources/cube.obj", 23.0f, 7.0f, -10.0f, 10.0f, 20.0f, 10.0f, 90.0f, shaderProgram);
	building6 = new Environment("building", "Resources/building6.bmp", "Resources/cube.obj", 20.0f, 20.0f, -8.0f, 15.0f, 20.0f, 8.0f, 90.0f, shaderProgram);
	building7 = new Environment("building", "Resources/building7.bmp", "Resources/cube.obj", 10.0f, 20.0f, -10.0f, 10.0f, 10.0f, 5.0f, 90.0f, shaderProgram);
	building7two = new Environment("building", "Resources/building7.bmp", "Resources/cube.obj", -20.0f, -8.0f, -7.0f, 10.0f, 4.0f, 10.0f, 180.0f, shaderProgram);
	building7three = new Environment("building", "Resources/building7.bmp", "Resources/cube.obj", -20.0f, -13.0f, -9.0f, 10.0f, 10.0f, 10.0f, 90.0f, shaderProgram);
	building8 = new Environment("building", "Resources/building8.bmp", "Resources/cube.obj", -20.0f, 7.0f, -9.0f, 10.0f, 18.0f, 10.0f, 90.0f, shaderProgram);

	exitCover = new Environment("building", "Resources/black.bmp", "Resources/cube.obj", 10.0f, 25.0f, -9.0f, 10.0f, 10.0f, 10.0f, 90.0f, shaderProgram);
	exitCover2 = new Environment("building", "Resources/black.bmp", "Resources/cube.obj", -20.0f, -3.0f, -9.0f, 1.0f, 10.0f, 10.0f, 90.0f, shaderProgram);

	road1 = new Environment("road", "Resources/road.bmp", "Resources/cube.obj", -20.0f, -0.2f, -3.0f, 30.0f, 0.1f, 10.0f, 0.0f, shaderProgram);
	road2 = new Environment("road", "Resources/road2.bmp", "Resources/cube.obj", 10.0f, -0.2f, 7.0f, 10.0f, 0.1f, 20.0f, 0.0f, shaderProgram);
	roadConnector = new Environment("road", "Resources/roadconnector.bmp", "Resources/cube.obj", 10.0f, -0.2f, -3.0f, 10.0f, 0.1f, 10.0f, 0.0f, shaderProgram);

	fence1 = new Environment("building", "Resources/fence.bmp", "Resources/cube.obj", 0.0f, -10.0f, -2.0f, 2.0f, 1.0f, 3.0f, 90.0f, shaderProgram);
	fence2 = new Environment("building", "Resources/wall.bmp", "Resources/cube.obj", 10.0f, -10.0f, -2.0f, 20.0f, 1.0f, 3.0f, 90.0f, shaderProgram);
	fence3 = new Environment("building", "Resources/wall.bmp", "Resources/cube.obj", 30.0f, -10.0f, -2.0f, 1.0f, 20.0f, 3.0f, 90.0f, shaderProgram);
	
	
	camera = new Camera();
	camera->setFocus(goblin); // Focus camera to first goblin
	currentChar = goblin; // Set current character to first goblin (control this goblin)
	
	// Set up array of collidable environment objects 
	collidableEnvironment[0] = building1;
	collidableEnvironment[1] = building2;
	collidableEnvironment[2] = building3;
	collidableEnvironment[3] = building4;
	collidableEnvironment[4] = building5;
	collidableEnvironment[5] = building6;
	collidableEnvironment[6] = building7three;
	collidableEnvironment[7] = building8;
	collidableEnvironment[8] = exitCover;
	collidableEnvironment[9] = exitCover2;
	collidableEnvironment[10] = fence1;
	collidableEnvironment[11] = fence2;
	collidableEnvironment[12] = fence3;

}


ScreenGame::~ScreenGame(void)
{
	// Destruct all of ScreenGame's objects
	goblin->~Character(); 
	yoshi->~Character(); 

	currentChar->~Character(); 

	camera->~Camera();

	skyBox->~SkyBox();

	ground->~Environment();
	ground2->~Environment();
	ground3->~Environment();

	building1->~Environment();
	building2->~Environment();
	building3->~Environment();
	building4->~Environment();
	building5->~Environment();
	building6->~Environment();
	building7->~Environment();
	building7two->~Environment();
	building7three->~Environment();
	building8->~Environment();
	exitCover->~Environment();
	exitCover2->~Environment();

	road1->~Environment();
	road2->~Environment();
	roadConnector->~Environment();

	fence1->~Environment();
	fence2->~Environment();
	fence3->~Environment();
}

void ScreenGame::draw(SDL_Window * window) 
{
	glEnable(GL_CULL_FACE);
	glClearColor(0.5f,0.5f,0.5f,1.0f);
	glClear(GL_COLOR_BUFFER_BIT  | GL_DEPTH_BUFFER_BIT);

	// Set up projection matrix
	glm::mat4 projection(1.0);
	projection = glm::perspective(60.0f,800.0f/600.0f,1.0f,150.0f);
	rt3d::setUniformMatrix4fv(shaderProgram, "projection", glm::value_ptr(projection));
	
	GLfloat scale(1.0f); // just to allow easy scaling of complete scene
	
	glm::mat4 modelview(1.0); // set base position for scene
	mvStack.push(modelview);

	mvStack.top() = glm::lookAt(camera->getEye(),camera->getAt(),camera->getUp());

	glm::vec4 tmp = mvStack.top()*lightPos;
	light0.position[0] = tmp.x;
	light0.position[1] = tmp.y;
	light0.position[2] = tmp.z;

	rt3d::setLightPos(shaderProgram, glm::value_ptr(tmp));
	
	glUseProgram(skyBoxShader); // Switch shaders, reset uniforms for skybox
	rt3d::setUniformMatrix4fv(skyBoxShader, "projection", glm::value_ptr(projection));
	glDepthMask(GL_FALSE); // make sure depth test is off
	glm::mat3 mvRotOnlyMat3 = glm::mat3(mvStack.top());
	mvStack.push( glm::mat4(mvRotOnlyMat3) );

	skyBox->draw(mvStack); // drawing skybox
	
	mvStack.pop();

	glDepthMask(GL_TRUE); // make sure depth test is on

	mvStack.top() = glm::lookAt(camera->getEye(),camera->getAt(),camera->getUp());

	glUseProgram(shaderProgram); // Switch back to normal shader program
	rt3d::setUniformMatrix4fv(shaderProgram, "projection", glm::value_ptr(projection));
	rt3d::setLightPos(shaderProgram, glm::value_ptr(tmp));
	rt3d::setLight(shaderProgram, light0);

	// Draw all visible objects...
	goblin->draw(mvStack);
	yoshi->draw(mvStack);
	
	ground->draw(mvStack);
	ground2->draw(mvStack);
	ground3->draw(mvStack);
	
	building1->draw(mvStack);
	building2->draw(mvStack);
	building3->draw(mvStack);
	building4->draw(mvStack);
	building5->draw(mvStack);
	building6->draw(mvStack);
	building7->draw(mvStack);
	building7two->draw(mvStack);
	building7three->draw(mvStack);
	building8->draw(mvStack);
	exitCover->draw(mvStack);
	exitCover2->draw(mvStack);
	
	road1->draw(mvStack);
	road2->draw(mvStack);
	roadConnector->draw(mvStack);
	
	fence1->draw(mvStack);
	fence2->draw(mvStack);
	fence3->draw(mvStack);
	
	mvStack.pop(); // initial matrix
	glDepthMask(GL_TRUE);

	SDL_GL_SwapWindow(window); // swap buffers
}

void ScreenGame::update() 
{
	camera->update(); // Update camera
	currentChar->update(); // Updated selected character only

	for ( int i = 0; i < 13; i++ ) // Check collisions between selected character and collidables
		detectCollisions(currentChar, collidableEnvironment[i]);
	}


void ScreenGame::checkEvents() 
{
	Uint8 *keys = SDL_GetKeyboardState(NULL);

	if ( keys[SDL_SCANCODE_3] ) { // Switching between characters
		currentChar = yoshi;
		camera->setFocus(currentChar);
	}

	if ( keys[SDL_SCANCODE_4] ) { // Switching between characters
		currentChar = goblin;
		camera->setFocus(currentChar);
	}

	if ( keys[SDL_SCANCODE_1] ) { // Wireframe
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glDisable(GL_CULL_FACE);
	}

	if ( keys[SDL_SCANCODE_2] ) { // Non-wireframe
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glEnable(GL_CULL_FACE);

	}
}

void ScreenGame::detectCollisions(Character * character, Environment * environment)
{
	if(character->getRect().intersects(environment->getRect())) {
		std::cout << "Collision Detected" << std::endl;
		currentChar->setMoveValue(-currentChar->getMoveValue()); // Negate value to handle collisions
	}
}