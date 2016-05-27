#pragma once
#include "Components/Component.h"
#include "../Game/TestComponent.h"

class Container
{
	string name;
	vector<shared_ptr<Component>> components;
public:
	Container(string _name);
	void Update();
	template <typename T> 
	void AddComponent();
	//~Container();
};

//---------------------

template <typename T>
void Container::AddComponent() {

	components.push_back(make_shared<T>());
}

