#include "Game.h"

Game::Game() {

	//CONSTRUCT SCENE
	//-------------------
	scene = new Scene("GameScene");
	//TestObject
	//-------------------
	Container * temp_container = new Container("TestObject");
	temp_container->AddComponent<TestComponent>();
	scene->AddContainer(temp_container);
	//Camera
	//-------------------
	temp_container = new Container("Cam");
	cam = temp_container->AddComponent<Camera>();
	scene->AddContainer(temp_container);
	//-------------------

	dist = -5;
}

void Game::Update() {

	if (Input::Pressed(GLFW_KEY_D)) dist += 0.1f;
	else if (Input::Pressed(GLFW_KEY_A)) dist -= 0.1f;

	cam->transform->position = Vector<float>(dist, 3.0f, 3.0f);

	scene->Update();
}

//Game::~Game() {
//
//	//VisualStudi exception?
//	delete scene;
//}
