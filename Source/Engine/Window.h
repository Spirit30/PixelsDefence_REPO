#pragma once
#include <omp.h>

#include "Render\Render.h"
#include "Input.h"
#include "Game.h"

class Window
{
private:
	GLFWwindow * window;
	const float target_FPS = 60;
	const float update_threshold;
	float delta_time;
public:
	Game game;
	Render * render;

	Window();
	void Loop();
	void Update();
	~Window();
};

