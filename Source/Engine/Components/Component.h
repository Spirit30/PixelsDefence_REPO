#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
using namespace std;

#include "../Debug.h"

class Component
{
public:
	Component();
	virtual void Update();
	//~Component();
};

