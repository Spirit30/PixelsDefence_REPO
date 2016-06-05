#pragma once
//#include <string>
#include <vector>
#include <algorithm>
#include <memory>
using namespace std;

#include "../Debug.h"
#include "../Render/Transform.h"

class Component
{
public:
	const Transform * transform;
	Component();
	virtual void Update();
	//~Component();
};

