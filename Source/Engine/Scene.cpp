#include "Scene.h"

Scene::Scene(string _name) {

	name = _name;
}

void Scene::Update() {

	//Update Containers
	for_each(containers.begin(), containers.end(), [](Container & c) { c.Update(); });
}

void Scene::AddContainer(const Container * _container) {

	containers.push_back(*_container);
}

Scene::~Scene() {

	//Delete Containers
	for_each(containers.begin(), containers.end(), [](Container & c) { 
		
		Container * p = &c;
		delete p;
	});
}