#pragma once
#include "Components/Component.h"

class Container
{
	string name;
	vector<shared_ptr<Component>> components;
public:
	Transform transform;

	Container(string _name);
	void Update();
	template <typename T> 
	T * AddComponent();
	//~Container();
};

//---------------------

template <typename T>
T * Container::AddComponent() {

	shared_ptr<T> component = make_shared<T>();
	component->transform = & this->transform;
	components.push_back(component);
	return component.get();
}

