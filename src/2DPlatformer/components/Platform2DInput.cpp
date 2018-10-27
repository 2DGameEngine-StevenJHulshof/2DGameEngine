#include "Platform2DInput.h"
#include "Platform2DPhysics.h"
#include "ComponentManager.h"
#include "InputManager.h"
#include "UserLog.h"

Platform2DInput::Platform2DInput() :
    Input() {



}

Platform2DInput::~Platform2DInput() = default;

void Platform2DInput::Config() {

    if(GetParent()->GetComponent<Physics>() == nullptr) {
        LOG_INVALID("Invalid reference to Platform2DPhysics from Platform2DInput -> Creating default Platform2DPhysics");
        physics = component_manager->New<Platform2DPhysics>(GetParent());
        GetParent()->Config();
    } else {
        physics = GetParent()->GetComponent<Physics>();
    }
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
}