#include "Window.h"

Window::Window() : update_threshold(1.0f / target_FPS)
{
	//Initialise GLFW
	//-----------------------------
	if (!glfwInit())
	{
		Debug::Log("Failed to initialize GLFW\n");
	}
	//-----------------------------

	//SetUp OpenGL
	//-----------------------------
	glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //We don't want the old OpenGL 
																   //-----------------------------

																   //Create a windowed mode window and its OpenGL context
																   //-----------------------------
	
	if (!(window = glfwCreateWindow(Render::WIDTH, Render::HEIGHT, "PixelsDefence", NULL, NULL)))
	{
		glfwTerminate();
		Debug::Log("Failed to initialize GLFW\n");
	}
	//-----------------------------

	//Initialise GLFW
	//-----------------------------
	//Make the window's context current
	glfwMakeContextCurrent(window);
	glewExperimental = true;
	if (glewInit() != GLEW_OK) {

		Debug::Log("Failed to initialize GLFW\n");

	}
	//-----------------------------

	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	//-----------------------------
	render = new Render();

	Loop();
}

//Window Loop
void Window::Loop() {

	double a_time = omp_get_wtime();
	double b_time = 0.0;

	// Check if the ESC key was pressed or the window was closed
	while(
		glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		glfwWindowShouldClose(window) == 0) {

			b_time = omp_get_wtime();
			if (delta_time = b_time - a_time > update_threshold) {

				a_time = omp_get_wtime();	
				Update();
		}
	} 

	// Close OpenGL window and terminate GLFW
	glfwTerminate();
}

void Window::Update() {

	//Input
	glfwPollEvents();

	//Update
	game.Update();

	//Draw
	render->Draw();
	glfwSwapBuffers(window);
}
