#include "Input.h"

map<int, bool> Input::keys;
map<int, bool>::iterator Input::keys_iterator;
double Input::x;
double Input::y;
int Input::window_width;
int Input::window_height;
Vector<double> Input::screen_center_dv2;

void Input::Init(GLFWwindow * window, const int & _window_width, const int & _window_height) {

	// Ensure we can capture the Keys pressed below
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
	//Save Screen size
	window_width = _window_width;
	window_height = _window_height;
	screen_center_dv2.x(double(window_width) / 2.0);
	screen_center_dv2.y(double(window_height) / 2.0);
	//All used Keys:
	keys[GLFW_KEY_A] =
		keys[GLFW_KEY_D] =
		keys[GLFW_KEY_W] =
		keys[GLFW_KEY_S] =
		keys[GLFW_KEY_ESCAPE] = false;
}

void Input::Update(GLFWwindow * window) {

	glfwPollEvents();
	//KEYS
	//--------------------
	for (keys_iterator = keys.begin(); keys_iterator != keys.end(); keys_iterator++) {
		// iterator->first = key
		// iterator->second = value
		keys[keys_iterator->first] = glfwGetKey(window, keys_iterator->first);
	}
	//MOUSE
	//--------------------
	glfwGetCursorPos(window, &x, &y);
	//Reset mouse position for next frame
	glfwSetCursorPos(window, screen_center_dv2.x(), screen_center_dv2.y());
}

bool Input::Pressed(int key) {

	return keys[key] == GLFW_PRESS;
}

int Input::X() { 
	
	return MathHelper::Clip(x, 0, window_width);
}

int Input::Y() { 

	return MathHelper::Clip(y, 0, window_height); 
}

