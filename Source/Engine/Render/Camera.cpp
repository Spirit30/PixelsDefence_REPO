#include "Camera.h"

//-----------------------------
//-----------------------------
//-----------------------------

int Camera::WIDTH = 640;
int Camera::HEIGHT = 480;
Camera * Camera::instance;

//-----------------------------
//-----------------------------
//-----------------------------

Camera::Camera() : last_position( -1.0f, -1.0f, -1.0f) {

	instance = this;

	// Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
	projection_m = perspective(radians(45.0f), (float)WIDTH / (float)HEIGHT, 0.1f, 100.0f);
}

void Camera::Update() {

	//Debug::Log("Camera Updated: Position - " + to_string(transform->position.x()));

	// Camera matrix
	view_m = lookAt(
		vec3(transform->position.To_vec3()), // Camera is at (x,y,z), in World Space
		vec3(0, 0, 0), // and looks at the origin
		vec3(0, 1, 0)  // Head is up (set to 0,-1,0 to look upside-down)
	);

	// Our ModelViewProjection : multiplication of our 3 matrices
	mvp = projection_m * view_m;// *Model; // Remember, matrix multiplication is the other way around
}


//Camera::~Camera()
//{
//}
