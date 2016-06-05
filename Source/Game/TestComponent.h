#pragma once
#include "../Engine/Components/Component.h"
//-------------------------
#include "../Engine/Input.h"

class TestComponent : public Component
{
public:
	TestComponent();
	void Update() override;
};

