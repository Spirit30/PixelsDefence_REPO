#pragma once
#include "../Components/Component.h"

class Camera : public Component
{
	//Variables
	Vector<float> last_position;
	mat4 projection_m;
	mat4 view_m;
public:
	static Camera * instance;
	//Data
	static int WIDTH;
	static int HEIGHT;
	//Variables
	mat4 mvp;
	//Functions
	Camera();
	void Update() override;
	//~Camera();
};

