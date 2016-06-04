#pragma once
#include "Debug.h"

template <typename T>
class Vector
{

public:
	const int size;
	Vector();
	Vector(T x, T y);			//Vector2
	Vector(T x, T y, T z);		//Vector3
	Vector(T x, T y, T z, T w);	//Vector4
	T & x();
	T & y();
	T & z();
	T & w();
	void x(T x);
	void y(T y);
	void z(T z);
	void w(T w);
	~Vector();
private:
	T * axes;
	Vector(int _size, T x, T y);
};

//Constructors
//-------------------

template <typename T>
Vector<T>::Vector(int _size, T x, T y) : size(_size) {

	axes = new T[size];
	axes[0] = x;
	axes[1] = y;
}

template <typename T>
Vector<T>::Vector() : Vector<T>(2, 0.0f, 0.0f) {}	//Vector2 by default

template <typename T>
Vector<T>::Vector(T x, T y) : Vector<T>::Vector(2, x, y) {}

template <typename T>
Vector<T>::Vector(T x, T y, T z) : Vector<T>::Vector(3, x, y) {

	axes[2] = z;
}

template <typename T>
Vector<T>::Vector(T x, T y, T z, T w) : Vector<T>::Vector(4, x, y) {

	axes[2] = z;
	axes[3] = w;
}

//Destructor
//-------------------

template <typename T>
Vector<T>::~Vector() {

	delete [] axes;
}

//Getters
//-------------------

//template <typename T>
//T Vector<T>::x() {
//
//	return axes[0];
//}
//
//template <typename T>
//T Vector<T>::y() {
//
//	return axes[1];
//}
//
//template <typename T>
//T Vector<T>::z() {
//
//	//if (size == 2) Debug::Log("Z-Axe requested from Vector2. Create Vector3 to use Z");
//	return axes[2];
//}
//
//template <typename T>
//T Vector<T>::w() {
//
//	//if (size == 3) Debug::Log("W-Axe requested from Vector3. Create Vector4 to use W");
//	return axes[3];
//}

//-------------------

template <typename T>
T & Vector<T>::x() {

	return axes[0];
}

template <typename T>
T & Vector<T>::y() {

	return axes[1];
}

template <typename T>
T & Vector<T>::z() {

	//if (size == 2) Debug::Log("Z-Axe requested from Vector2. Create Vector3 to use Z");
	return axes[2];
}

template <typename T>
T & Vector<T>::w() {

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

