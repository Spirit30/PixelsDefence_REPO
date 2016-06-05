#pragma once
#include "Scene.h"
#include "Input.h"

//Components
#include "Render/Camera.h"
#include "../Game/TestComponent.h"

class Game
{
private:
	Scene * scene;

	//Test
	Camera * cam;
	float dist;
public:
	Game();
	void Update();
	//~Game();
};

