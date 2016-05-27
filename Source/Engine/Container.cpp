#include "Container.h"

Container::Container(string _name) {

	name = _name;
}

void Container::Update() {

	//Update Components
	for_each(components.begin(), components.end(), [](shared_ptr<Component> & c) { c->Update(); });
}

//Container::~Container() {
//
//	//Delete Components - Do not need because of shared_ptr<> !
//	for_each(components.begin(), components.end(), [](Component * p) {
//
//		//Component * p = &c;
//		delete p;
//	});
//}