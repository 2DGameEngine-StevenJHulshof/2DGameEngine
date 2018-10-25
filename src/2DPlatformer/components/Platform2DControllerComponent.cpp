#include "Platform2DControllerComponent.h"
#include "PhysicsComponent.h"
#include "InputManager.h"
#include "UserLog.h"

Platform2DControllerComponent::Platform2DControllerComponent() :
    ControllerComponent() {



}

Platform2DControllerComponent::~Platform2DControllerComponent() = default;

void Platform2DControllerComponent::Update() {

    if (input_manager->GetKeyQ()) {
        GetParent()->GetComponent<PhysicsComponent>()->impulse.y = 20.0f;
    }
    if (input_manager->GetKeyRight()) {
        GetParent()->GetComponent<PhysicsComponent>()->impulse.x = 10.0f;
    }
    if (input_manager->GetKeyLeft()) {
        GetParent()->GetComponent<PhysicsComponent>()->impulse.x = -10.0f;
    }
}