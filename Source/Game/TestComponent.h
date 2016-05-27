#pragma once
#include "../Engine/Components/Component.h"

class TestComponent : public Component
{
	int update_index = 0;
public:
	TestComponent();
	void Update() override;
};

