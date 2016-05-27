#pragma once
#include "Container.h"

class Scene
{
	string name;
	vector<Container> containers;
public:
	Scene(string _name);
	void Update();
	void AddContainer(const Container * _container);
	~Scene();
};

