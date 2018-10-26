#include "Platform2DControllerComponent.h"
#include "Platform2DPhysicsComponent.h"
#include "ComponentManager.h"
#include "InputManager.h"
#include "UserLog.h"

Platform2DControllerComponent::Platform2DControllerComponent() :
    ControllerComponent() {



}

Platform2DControllerComponent::~Platform2DControllerComponent() = default;

void Platform2DControllerComponent::Config() {

    if(GetParent()->GetComponent<PhysicsComponent>() == nullptr) {
        LOG_INVALID("Invalid reference to Platform2DPhysics from Platform2DController -> Creating default Platform2DPhysics");
        physics = component_manager->New<Platform2DPhysicsComponent>(GetParent());
        GetParent()->Config();
    } else {
        physics = GetParent()->GetComponent<PhysicsComponent>();
    }
}

void Platform2DControllerComponent::Update() {

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