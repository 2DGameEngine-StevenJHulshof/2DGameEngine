#include "Platform2DInput.h"
#include "Platform2DPhysics.h"
#include "ComponentManager.h"
#include "InputManager.h"
#include "UserLog.h"

Platform2DInput::Platform2DInput() :
    Input(),
    physics(nullptr) {

}

Platform2DInput::~Platform2DInput() = default;

void Platform2DInput::Config() {

    physics = component_manager->AddDependency<Platform2DPhysics>(parent);

    Input::Config();
}

void Platform2DInput::Update() {

    if (input_manager->GetKeyUp()) {
        physics->impulse.y = 20.0f;
    }
    if (input_manager->GetKeyRight()) {
        physics->impulse.x = 10.0f;
    }
    if (input_manager->GetKeyLeft()) {
        physics->impulse.x = -10.0f;
    }

    Input::Update();
}