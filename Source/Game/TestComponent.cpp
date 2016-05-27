#include "TestComponent.h"

TestComponent::TestComponent() {


}

void TestComponent::Update() {

	Debug::Log(("TestComponent Updated: " + to_string(++update_index) + "\n").c_str());
}

