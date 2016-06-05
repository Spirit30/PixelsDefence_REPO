#pragma once
//Include GLM
#include <GLM/glm.hpp>
#include <glm/gtx/transform.hpp> // after <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
using namespace glm;
#include "Debug.h"

template <typename T>
class Vector
{
public:
	const int size;
	//Constructors
	Vector();					//Vector2
	Vector(T x, T y);			//Vector2
	Vector(T x, T y, T z);		//Vector3
	Vector(T x, T y, T z, T w);	//Vector4
	Vector<T>(int _size, T a);	//Identity
	//Destructor
	~Vector();
	//Getters
	T & x() const;
	T & y() const;
	T & z() const;
	T & w() const;
	//Setters
	void x(T x);
	void y(T y);
	void z(T z);
	void w(T w);
	//GLM
	vec3 To_vec3() const;
	//Operators
	void operator=(Vector<T> & v) const;
private:
	T * axes;
	/*Vector(const Vector & v);
	Vector(int _size, T * _axes);*/
	Vector(int _size, T x, T y);
};

//Constructors
//-------------------

template <typename T>
Vector<T>::Vector(int _size, T a) : size(_size) {

	axes = new T[size];
	for (int i = 0; i < size; i++) axes[i] = a;
}

template <typename T>
Vector<T>::Vector() : Vector<T>(2, 0.0f) {}	//Vector2 by default

template <typename T>
Vector<T>::Vector(int _size, T x, T y) : size(_size) {

	axes = new T[size];
	axes[0] = x;
	axes[1] = y;
}

template <typename T>
Vector<T>::Vector(T x, T y) : Vector<T>::Vector(2, x, y) {}

template <typename T>
Vector<T>::Vector(T x, T y, T z) : Vector<T>::Vector(3, x, y) {

	axes[2] = z;
}

template <typename T>
Vector<T>::Vector(T x, T y, T z, T w) : Vector<T>::Vector(4, x, y, z) {

	axes[3] = w;
}

//template <typename T>
//Vector<T>::Vector(int _size, T * _axes) : size(_size) {
//
//	axes = new T[size];
//	for (int i = 0; i < size; i++) axes[i] = _axes[i];
//}
//
//template <typename T>
//Vector<T>::Vector(const Vector<T> & v) : Vector<T>(v.size, v.axes) {}

//Destructor
//-------------------

template <typename T>
Vector<T>::~Vector() {

	delete [] axes;
}

//Getters
//-------------------

template <typename T>
T & Vector<T>::x() const {

	return axes[0];
}

template <typename T>
T & Vector<T>::y() const {

	return axes[1];
}

template <typename T>
T & Vector<T>::z() const {

	//if (size == 2) Debug::Log("Z-Axe requested from Vector2. Create Vector3 to use Z");
	return axes[2];
}

template <typename T>
T & Vector<T>::w() const {

	//if (size == 3) Debug::Log("W-Axe requested from Vector3. Create Vector4 to use W");
	return axes[3];
}

//Setters
//-------------------

template <typename T>
void Vector<T>::x(T x) {

	axes[0] = x;
}

template <typename T>
void Vector<T>::y(T y) {

	axes[1] = y;
}

template <typename T>
void Vector<T>::z(T z) {

	//if (size == 2) Debug::Log("Z-Axe requested from Vector2. Create Vector3 to use Z");
	axes[2] = z;
}

template <typename T>
void Vector<T>::w(T wz) {

	//if (size == 3) Debug::Log("W-Axe requested from Vector3. Create Vector4 to use W");
	axes[3] = w;
}

//Convert 
//-------------------

template <typename T>
vec3 Vector<T>::To_vec3() const {

	return vec3(axes[0], axes[1], axes[2]);
}

//Operators
//-------------------

template <typename T>
void Vector<T>::operator=(Vector<T> & v) const {

	for (int i = 0; i < size; i++) axes[i] = v.axes[i];
	//return * this;
}