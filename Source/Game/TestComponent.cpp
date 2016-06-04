#include "TestComponent.h"

TestComponent::TestComponent() {


}

void TestComponent::Update() {

	//
	Debug::Log("TestComponent Updated: X - " + to_string(Input::X()) + ", Y - " + to_string(Input::Y()) + "\n");
}

