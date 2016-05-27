#include "Game.h"

Game::Game() {

	//CONSTRUCT SCENE
	//-------------------
	scene = new Scene("GameScene");
	Container * container = new Container("TestObject");
	container->AddComponent<TestComponent>();
	scene->AddContainer(container);
	//-------------------
}

void Game::Update() {

	scene->Update();
}
