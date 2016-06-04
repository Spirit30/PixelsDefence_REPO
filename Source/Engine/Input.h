#pragma once
#include <map>
//GLFW
#include <GLFW/glfw3.h>

#include "MathHelper.h"

#include "Vector.h"

class Input
{
private:
	//<Key Macros, isPressed>
	static map<int, bool> keys;
	static map<int, bool>::iterator keys_iterator;
	static double x;
	static double y;
	static int window_width;
	static int window_height;
	static Vector<double> screen_center_dv2;	//double vector 2
public:
	static void Init(GLFWwindow * window, const int & window_width, const int & window_height);
	static void Update(GLFWwindow * window);
	static bool Pressed(int key);
	static int X();
	static int Y();
};

