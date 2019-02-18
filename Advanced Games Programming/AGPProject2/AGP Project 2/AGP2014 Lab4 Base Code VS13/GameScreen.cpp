#include "GameScreen.h"
#include "Particle.h"
#include "Load.h"	


GameScreen::GameScreen()
{
}

GameScreen::~GameScreen()
{
}

void GameScreen::init() 
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);	
	std::srand(time(0));
	renderer.init();
	renderer.setParticleCubePosition(glm::vec3(-3.25f,12.0f,-5.0f));

	// light object constructors
	//Light(Ambient,Diffuse,Specular,Position,ConeDirection,ConeFallOff,Attenuation,Active,Type)
	lightList[0] = Light(glm::vec4(0.5f, 0.5f, 0.5f, 1.0f), glm::vec4(0.5f, 0.0f, 0.0f, 1.0f), glm::vec4(5.3f, 5.9f, 5.2f, 1.0f), glm::vec4(0.0f, 0.0f, 0.0f, 1.0f), glm::vec3(0.01, -0.15, 0.009), 1.39, glm::vec3(1.0f, 0.01f, 0.001f), 1, 0);

	lightList[1] = Light(glm::vec4(0.0f, 0.0f, 0.0f, 1.0f), glm::vec4(0.0f, 0.0f, 0.5f, 1.0f), glm::vec4(1.3f, 1.9f, 1.2f, 1.0f), glm::vec4(0.0f, 0.0f, 0.0f, 1.0f), glm::vec3(0.01, -0.15, 0.009), 1.39, glm::vec3(1.0f, 0.01f, 0.001f), 1, 0);
	lightList[2] = Light(glm::vec4(0.0f, 0.0f, 0.0f, 1.0f), glm::vec4(0.0f, 0.0f, 0.5f, 1.0f), glm::vec4(1.3f, 1.9f, 1.2f, 1.0f), glm::vec4(0.0f, 0.0f, 0.0f, 1.0f), glm::vec3(0.01, -0.15, 0.009), 1.39, glm::vec3(1.0f, 0.01f, 0.001f), 1, 0);
	lightList[3] = Light(glm::vec4(0.0f, 0.0f, 0.0f, 1.0f), glm::vec4(0.5f, 0.1f, 0.0f, 1.0f), glm::vec4(1.3f, 1.9f, 1.2f, 1.0f), glm::vec4(0.0f, 0.0f, 0.0f, 1.0f), glm::vec3(0.01, -0.15, 0.009), 1.39, glm::vec3(1.0f, 0.01f, 0.001f), 1, 0);
	lightList[4] = Light(glm::vec4(0.0f, 0.0f, 0.0f, 1.0f), glm::vec4(0.5f, 0.0f, 0.0f, 1.0f), glm::vec4(1.3f, 1.9f, 1.2f, 1.0f), glm::vec4(0.0f, 0.0f, 0.0f, 1.0f), glm::vec3(0.01, -0.15, 0.009), 1.39, glm::vec3(1.0f, 0.01f, 0.001f), 1, 0);
	lightList[5] = Light(glm::vec4(0.0f, 0.0f, 0.0f, 1.0f), glm::vec4(0.3f, 0.0f, 0.3f, 1.0f), glm::vec4(1.3f, 1.9f, 1.2f, 1.0f), glm::vec4(0.0f, 0.0f, 0.0f, 1.0f), glm::vec3(0.01, -0.15, 0.009), 1.39, glm::vec3(1.0f, 0.01f, 0.001f), 1, 0);
	lightList[6] = Light(glm::vec4(0.0f, 0.0f, 0.0f, 1.0f), glm::vec4(0.0f, 0.5f, 0.0f, 1.0f), glm::vec4(1.3f, 1.9f, 1.2f, 1.0f), glm::vec4(0.0f, 0.0f, 0.0f, 1.0f), glm::vec3(0.01, -0.15, 0.009), 1.39, glm::vec3(1.0f, 0.01f, 0.001f), 1, 0);

	lightList[7] = Light(glm::vec4(0.5f, 0.5f, 0.5f, 1.0f), glm::vec4(0.2f, 1.0f, 0.2f, 1.0f), glm::vec4(20.3f, 20.9f, 20.2f, 1.0f), glm::vec4(renderer.getParticleCubePosition().x, renderer.getParticleCubePosition().y, renderer.getParticleCubePosition().z, 1.0f), glm::vec3(30.01, -0.15, 0.009), 1.39, glm::vec3(1.0f, 0.01f, 0.001f), 0, 0);

	lightList[8] = Light(glm::vec4(0.0f, 0.0f, 0.0f, 1.0f), glm::vec4(0.5f, 0.1f, 0.0f, 1.0f), glm::vec4(1.3f, 1.9f, 1.2f, 1.0f), glm::vec4(0.0f, 0.0f, 0.0f, 1.0f), glm::vec3(0.01, -0.15, 0.009), 1.39, glm::vec3(1.0f, 0.01f, 0.001f), 1, 0);
	lightList[9] = Light(glm::vec4(0.0f, 0.0f, 0.0f, 1.0f), glm::vec4(0.3f, 0.0f, 0.3f, 1.0f), glm::vec4(1.3f, 1.9f, 1.2f, 1.0f), glm::vec4(0.0f, 0.0f, 0.0f, 1.0f), glm::vec3(0.01, -0.15, 0.009), 1.39, glm::vec3(1.0f, 0.01f, 0.001f), 1, 0);

	// light position in world space:
	
	lightPosList[0] = glm::vec4(-8.0f, 3.0f, 42.0f, 1.0f);
	lightPosList[1] = glm::vec4(-20.0f, 6.0f, -20.0f, 1.0f);
	lightPosList[2] = glm::vec4(-20.0f, 6.0f, 10.0f, 1.0f);
	lightPosList[3] = glm::vec4(-5.0f, 6.0f, -20.0f, 1.0f);
	lightPosList[4] = glm::vec4( 10.0f, 6.0f, 10.0f, 1.0f);
	lightPosList[5] = glm::vec4( 10.0f, 6.0f, -20.0f, 1.0f);
	lightPosList[6] = glm::vec4(-20.0f, 6.0f, -5.0f, 1.0f);
	lightPosList[7] = glm::vec4(renderer.getParticleCubePosition().x,renderer.getParticleCubePosition().y,renderer.getParticleCubePosition().z, 1.0f);
	lightPosList[8] = glm::vec4( -5.0f,  6.0f,  10.0f, 1.0f);
	lightPosList[9] = glm::vec4( 10.0f, 6.0f,  -5.0f,  1.0f);

	// light cone for spotlights
	for (int i = 0; i < NUMLIGHTS; i++) { lightConeDirection[i] = glm::vec3(0.01, -1.41, -1.00); }

	selectLight = 0;
}

bool GameScreen::update()
{
	bool running = true;

	renderer.update();

	const Uint8 *keys = SDL_GetKeyboardState(NULL);
	// moving camera 
	if (keys[SDL_SCANCODE_W]) renderer.setEye(Load::moveForward(renderer.getEye(), renderer.getRotate(), 1.0f));
	if (keys[SDL_SCANCODE_S]) renderer.setEye(Load::moveForward(renderer.getEye(), renderer.getRotate(), -1.0f));
	if (keys[SDL_SCANCODE_A]) renderer.setEye(Load::moveRight(renderer.getEye(), renderer.getRotate(), -1.0f));
	if (keys[SDL_SCANCODE_D]) renderer.setEye(Load::moveRight(renderer.getEye(), renderer.getRotate(), 1.0f));
	if (keys[SDL_SCANCODE_E]) renderer.setEye(glm::vec3(renderer.getEye().x, renderer.getEye().y + 1.0, renderer.getEye().z));
	if (keys[SDL_SCANCODE_Q]) renderer.setEye(glm::vec3(renderer.getEye().x, renderer.getEye().y - 1.0, renderer.getEye().z));

	// rotate camera
	if (keys[SDL_SCANCODE_COMMA])renderer.setRotate(renderer.getRotate() - 2.0f);
	if (keys[SDL_SCANCODE_PERIOD]) renderer.setRotate(renderer.getRotate() + 2.0f);

	// select light
	if (keys[SDL_SCANCODE_1]) selectLight = 0;
	if (keys[SDL_SCANCODE_2]) selectLight = 1;
	if (keys[SDL_SCANCODE_3]) selectLight = 2;
	if (keys[SDL_SCANCODE_4]) selectLight = 3;
	if (keys[SDL_SCANCODE_5]) selectLight = 4;
	if (keys[SDL_SCANCODE_6]) selectLight = 5;
	if (keys[SDL_SCANCODE_7]) selectLight = 6;
	if (keys[SDL_SCANCODE_8]) selectLight = 7;

	// set attenuation for chosen light
	if (keys[SDL_SCANCODE_C]) lightList[selectLight].setAttenuationLinear(lightList[selectLight].getAttenuationLinear() + 0.01f);
	if (keys[SDL_SCANCODE_V]) lightList[selectLight].setAttenuationLinear(lightList[selectLight].getAttenuationLinear() - 0.01f);
	if (keys[SDL_SCANCODE_LEFTBRACKET]) lightList[selectLight].setAttenuationQuadratic(lightList[selectLight].getAttenuationQuadratic() + 0.001f);
	if (keys[SDL_SCANCODE_RIGHTBRACKET]) lightList[selectLight].setAttenuationQuadratic(lightList[selectLight].getAttenuationQuadratic() - 0.001f);


	// move particle cube
	if (keys[SDL_SCANCODE_KP_6]) renderer.setParticleCubePosition(glm::vec3(renderer.getParticleCubePosition().x + 0.2, renderer.getParticleCubePosition().y, renderer.getParticleCubePosition().z));
	if (keys[SDL_SCANCODE_KP_8]) renderer.setParticleCubePosition(glm::vec3(renderer.getParticleCubePosition().x, renderer.getParticleCubePosition().y, renderer.getParticleCubePosition().z - 0.2));
	if (keys[SDL_SCANCODE_KP_4]) renderer.setParticleCubePosition(glm::vec3(renderer.getParticleCubePosition().x - 0.2, renderer.getParticleCubePosition().y, renderer.getParticleCubePosition().z));
	if (keys[SDL_SCANCODE_KP_5]) renderer.setParticleCubePosition(glm::vec3(renderer.getParticleCubePosition().x, renderer.getParticleCubePosition().y, renderer.getParticleCubePosition().z + 0.2));
	if (keys[SDL_SCANCODE_KP_9]) renderer.setParticleCubePosition(glm::vec3(renderer.getParticleCubePosition().x, renderer.getParticleCubePosition().y + 0.2, renderer.getParticleCubePosition().z));
	if (keys[SDL_SCANCODE_KP_7]) renderer.setParticleCubePosition(glm::vec3(renderer.getParticleCubePosition().x, renderer.getParticleCubePosition().y - 0.2, renderer.getParticleCubePosition().z));

	// move selected light
	if (keys[SDL_SCANCODE_I]) lightPosList[selectLight].z += -1.0f;
	if (keys[SDL_SCANCODE_K]) lightPosList[selectLight].z += 1.0f;
	if (keys[SDL_SCANCODE_J]) lightPosList[selectLight].x += -1.0f;
	if (keys[SDL_SCANCODE_L]) lightPosList[selectLight].x += 1.0f;
	if (keys[SDL_SCANCODE_O]) lightPosList[selectLight].y += 1.0f;
	if (keys[SDL_SCANCODE_U]) lightPosList[selectLight].y -= 1.0f;

	//// increase and decrease cone fall of for chosen light(spotlights only)
	if (keys[SDL_SCANCODE_N]){ lightList[selectLight].setConeFallOff(lightList[selectLight].getConeFallOff() - 0.01); }
	if (keys[SDL_SCANCODE_M]){ lightList[selectLight].setConeFallOff(lightList[selectLight].getConeFallOff() + 0.01); }

	if (keys[SDL_SCANCODE_9]){
		if (lightList[selectLight].getStatus() == 1) {
			lightList[selectLight].turnOff();
			cout << "Current light (Number " << selectLight << ") is now turned off" << endl;
		}
	}

	if (keys[SDL_SCANCODE_0]){
		if (lightList[selectLight].getStatus() == 0) {
			lightList[selectLight].turnOn();
			cout << "Current light (Number " << selectLight << ") is now turned on" << endl;
		}
	}

	if (keys[SDL_SCANCODE_Z]){ 
		if (lightList[selectLight].getType() == 1) {
			lightList[selectLight].setType(0);
			cout << "Current light (Number " << selectLight << ") Changed to pointlight" << endl;
		}
	}
	if (keys[SDL_SCANCODE_X]){ 
		if (lightList[selectLight].getType() == 0) {
			lightList[selectLight].setType(1);
			cout << "Current light (Number " << selectLight << ") Changed to spotlight" << endl;
		}
	}



	//fire particles
	if ( keys[SDL_SCANCODE_EQUALS])
	{
		tempParticlePosition = std::rand() % 151;
		lightList[7].turnOn();
	}

	// increase particle size
	if (keys[SDL_SCANCODE_RIGHT]) { 
		if (particleSize < 100){
			particleSize += 1.0f;
		}
	}
	// decrease particle size
	if (keys[SDL_SCANCODE_LEFT]){
		if (particleSize > 0){
			particleSize -= 1.0f;
		}
	}
	
	// update light with random particle
	lightPosList[7] = glm::vec4(renderer.getParticleLight()->getPositions(50).x,renderer.getParticleLight()->getPositions(50).y,renderer.getParticleLight()->getPositions(50).z,1.0);

	if(renderer.getParticleLight()->getParticleOn()==false) lightList[7].turnOff();

	return running;
}

void GameScreen::draw(SDL_Window * window)
{
	const Uint8 *keys = SDL_GetKeyboardState(NULL);
	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glBindFramebuffer(GL_FRAMEBUFFER, renderer.getFBO());
	glClear(GL_DEPTH_BUFFER_BIT);

	///// Render depths for cubes, for shadows

	//// back section
	// Render box 1, tall right
	renderer.renderDepth(glm::vec3(1.0f, 5.0f, -9.0f), glm::vec3(1.2f, 5.0f, 1.2f), lightPosList[0], lightConeDirection[0]);
	// Render box 2, sideways bottom
	renderer.renderDepth(glm::vec3(-3.25f, 1.25f, -9.0f), glm::vec3(3.0f, 1.2f, 1.2f), lightPosList[0], lightConeDirection[0]);
	// Render box 3, tall left
	renderer.renderDepth(glm::vec3(-7.50f, 5.0f, -9.0f), glm::vec3(1.2f, 5.0f, 1.2f), lightPosList[0], lightConeDirection[0]);
	// Render box 4, sideways top
	renderer.renderDepth(glm::vec3(-3.25f, 8.75f, -9.0f), glm::vec3(3.0f, 1.2f, 1.2f), lightPosList[0], lightConeDirection[0]);

	////side paritions
	// Render box 5, bottom left
	renderer.renderDepth(glm::vec3(-7.50f, 1.25f, -4.75f), glm::vec3(1.2f, 1.2f, 3.0f), lightPosList[0], lightConeDirection[0]);
	// Render box 6, bottom right
	renderer.renderDepth(glm::vec3(1.0f, 1.25f, -4.75f), glm::vec3(1.2f, 1.2f, 3.0f), lightPosList[0], lightConeDirection[0]);
	// Render box 7, top left
	renderer.renderDepth(glm::vec3(-7.50f, 8.75f, -4.75f), glm::vec3(1.2f, 1.2f, 3.0f), lightPosList[0], lightConeDirection[0]);
	// Render box 8, top right
	renderer.renderDepth(glm::vec3(1.0f, 8.75f, -4.75f), glm::vec3(1.2f, 1.2f, 3.0f), lightPosList[0], lightConeDirection[0]);

	//// front section
	// Render box 9, tall right
	renderer.renderDepth(glm::vec3(1.0f, 5.0f, -0.5f), glm::vec3(1.2f, 5.0f, 1.2f), lightPosList[0], lightConeDirection[0]);
	// Render box 10, sideways bottom
	renderer.renderDepth(glm::vec3(-3.25f, 1.25f, -0.5f), glm::vec3(3.0f, 1.2f, 1.2f), lightPosList[0], lightConeDirection[0]);
	// Render box 11, tall left
	renderer.renderDepth(glm::vec3(-7.50f, 5.0f, -0.5f), glm::vec3(1.2f, 5.0f, 1.2f), lightPosList[0], lightConeDirection[0]);
	// Render box 12, sideways top
	renderer.renderDepth(glm::vec3(-3.25f, 8.75f, -0.5f), glm::vec3(3.0f, 1.2f, 1.2f), lightPosList[0], lightConeDirection[0]);

	//// outside cubes
	renderer.renderDepth(glm::vec3(-3.25f, 3.25f, -39.0f), glm::vec3(3.0f, 3.0f, 3.0f), lightPosList[0], lightConeDirection[0]);
	renderer.renderDepth(glm::vec3(31.0f, 3.25f, -4.75f), glm::vec3(3.0f, 3.0f, 3.0f), lightPosList[0], lightConeDirection[0]);
	renderer.renderDepth(glm::vec3(-37.50f, 3.25f, -4.75f), glm::vec3(3.0f, 3.0f, 3.0f), lightPosList[0], lightConeDirection[0]);

	renderer.renderDepth(glm::vec3(-10.0f, -0.1f, -10.0f), glm::vec3(60.0f, 0.1f, 60.f), lightPosList[0], lightConeDirection[0]);

	//particle cube
	renderer.renderDepth(glm::vec3(renderer.getParticleCubePosition()), glm::vec3(1.0f, 1.0f, 1.0f), lightPosList[0], lightConeDirection[0]);

	glBindFramebuffer(GL_FRAMEBUFFER, 0);

	//// Render the cubes, to draw

	//// back section
	// Render box 1, tall right
	renderer.renderProp("prop", glm::vec3(1.0f, 5.0f, -9.0f), glm::vec3(1.2f, 5.0f, 1.2f), lightConeDirection, lightList, lightPosList);
	// Render box 2, sideways bottom
	renderer.renderProp("prop", glm::vec3(-3.25f, 1.25f, -9.0f), glm::vec3(3.0f, 1.2f, 1.2f), lightConeDirection, lightList, lightPosList);
	// Render box 3, tall left
	renderer.renderProp("prop", glm::vec3(-7.50f, 5.0f, -9.0f), glm::vec3(1.2f, 5.0f, 1.2f), lightConeDirection, lightList, lightPosList);
	// Render box 4, sideways top
	renderer.renderProp("prop", glm::vec3(-3.25f, 8.75f, -9.0f), glm::vec3(3.0f, 1.2f, 1.2f), lightConeDirection, lightList, lightPosList);

	//// side partitions
	// Render box 5, bottom left
	renderer.renderProp("prop", glm::vec3(-7.50f, 1.25f, -4.75f), glm::vec3(1.2f, 1.2f, 3.0f), lightConeDirection, lightList, lightPosList);
	// Render box 6, bottom right
	renderer.renderProp("prop", glm::vec3(1.0f, 1.25f, -4.75f), glm::vec3(1.2f, 1.2f, 3.0f), lightConeDirection, lightList, lightPosList);
	// Render box 7, top left
	renderer.renderProp("prop", glm::vec3(-7.50f, 8.75f, -4.75f), glm::vec3(1.2f, 1.2f, 3.0f), lightConeDirection, lightList, lightPosList);
	// Render box 8, top right
	renderer.renderProp("prop", glm::vec3(1.0f, 8.75f, -4.75f), glm::vec3(1.2f, 1.2f, 3.0f), lightConeDirection, lightList, lightPosList);

	//// front section
	// Render box 9, tall right
	renderer.renderProp("prop", glm::vec3(1.0f, 5.0f, -0.5f), glm::vec3(1.2f, 5.0f, 1.2f), lightConeDirection, lightList, lightPosList);
	// Render box 10, sideways bottom
	renderer.renderProp("prop", glm::vec3(-3.25f, 1.25f, -0.5f), glm::vec3(3.0f, 1.2f, 1.2f), lightConeDirection, lightList, lightPosList);
	// Render box 11, tall left
	renderer.renderProp("prop", glm::vec3(-7.50f, 5.0f, -0.5f), glm::vec3(1.2f, 5.0f, 1.2f), lightConeDirection, lightList, lightPosList);
	// Render box 12, sideways top
	renderer.renderProp("prop", glm::vec3(-3.25f, 8.75f, -0.5f), glm::vec3(3.0f, 1.2f, 1.2f), lightConeDirection, lightList, lightPosList);

	//// outside cubes
	renderer.renderProp("prop", glm::vec3(-3.25f, 3.25f, -39.0f), glm::vec3(3.0f, 3.0f, 3.0f), lightConeDirection, lightList, lightPosList);
	renderer.renderProp("prop", glm::vec3(31.0f, 3.25f, -4.75f), glm::vec3(3.0f, 3.0f, 3.0f), lightConeDirection, lightList, lightPosList);
	renderer.renderProp("prop", glm::vec3(-37.50f, 3.25f, -4.75f), glm::vec3(3.0f, 3.0f, 3.0f), lightConeDirection, lightList, lightPosList);

	// Render particleCube
	renderer.renderProp("box", glm::vec3(renderer.getParticleCubePosition()), glm::vec3(1.0f, 1.0f, 1.0f), lightConeDirection, lightList, lightPosList);

	// Render scene
	//floor
	renderer.renderProp("metal", glm::vec3(-10.0f, -0.1f, -10.0f), glm::vec3(60.0f, 0.1f, 60.0f), lightConeDirection, lightList, lightPosList);
	//top
	renderer.renderProp("metal", glm::vec3(-10.0f, 40.0f, -10.0f), glm::vec3(60.0f, 0.1f, 60.0f), lightConeDirection, lightList, lightPosList);
	//right
	renderer.renderProp("metal", glm::vec3(50.0f, 20.0f, -10.0f), glm::vec3(0.1f, 20.0f, 60.0f), lightConeDirection, lightList, lightPosList);
	//left
	renderer.renderProp("metal", glm::vec3(-70.0f, 20.0f, -10.0f), glm::vec3(0.1f, 20.0f, 60.0f), lightConeDirection, lightList, lightPosList);
	//front
	renderer.renderProp("metal", glm::vec3(-10.0f, 20.0f, 50.0f), glm::vec3(60.0f, 20.0f, 0.1f), lightConeDirection, lightList, lightPosList);
	//back
	renderer.renderProp("metal", glm::vec3(-10.0f, 20.0f, -70.0f), glm::vec3(60.0f, 20.0f, 0.1f), lightConeDirection, lightList, lightPosList);

	// Render list of lights
	renderer.renderLight(lightList, lightPosList);

	// Render a prop for each light
	for (int i = 0; i < NUMLIGHTS - 1; i++)
	{
		// dont render cube around particle light
		if (i != 7) {
			renderer.renderLightProps(lightPosList[i]);
		}
	}

	//// change particle textures
	// set as smoke
	if (keys[SDL_SCANCODE_F1]){ choiceMade = true; choice = 1; }
	// set as scene
	if (keys[SDL_SCANCODE_F2]){ choiceMade = true; choice = 2; }
	// set as prop
	if (keys[SDL_SCANCODE_F3]){ choiceMade = true; choice = 3; }
	// set as box
	if (keys[SDL_SCANCODE_F4]){ choiceMade = true; choice = 4; }
	// set as leaf
	if (keys[SDL_SCANCODE_F5]){ choiceMade = true; choice = 5; }
	// set as colourbox
	if (keys[SDL_SCANCODE_F6]){ choiceMade = true; choice = 6; }
	// set as fabric
	if (keys[SDL_SCANCODE_F7]){ choiceMade = true; choice = 7; }
	// set as goblin
	if (keys[SDL_SCANCODE_F8]){ choiceMade = true; choice = 8; }
	// set as metal
	if (keys[SDL_SCANCODE_F9]){ choiceMade = true; choice = 9; }

	if (choiceMade = true)
	{
		if (choice == 1) { renderer.renderParticles("smoke", particleSize, lightPosList[0]); }
		if (choice == 2) { renderer.renderParticles("smokecloud", particleSize, lightPosList[0]); }
		if (choice == 3) { renderer.renderParticles("prop", particleSize, lightPosList[0]); }
		if (choice == 4) { renderer.renderParticles("box", particleSize, lightPosList[0]); }
		if (choice == 5) { renderer.renderParticles("leaf", particleSize, lightPosList[0]); }
		if (choice == 6) { renderer.renderParticles("colour", particleSize, lightPosList[0]); }
		if (choice == 7) { renderer.renderParticles("fabric", particleSize, lightPosList[0]); }
		if (choice == 8) { renderer.renderParticles("goblin", particleSize, lightPosList[0]); }
		if (choice == 9) { renderer.renderParticles("metal", particleSize, lightPosList[0]); }
	}
	
	glDepthMask(GL_TRUE);

	SDL_GL_SwapWindow(window); // swap buffers
}