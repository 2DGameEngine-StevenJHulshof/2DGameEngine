#include "Platform2DControllerComponent.h"
#include "PhysicsComponent.h"
#include "InputManager.h"
#include "UserLog.h"

Platform2DControllerComponent::Platform2DControllerComponent() :
    ControllerComponent() {



}

Platform2DControllerComponent::~Platform2DControllerComponent() = default;

void Platform2DControllerComponent::Update() {

    if (!input_manager->GetKeyLeft() && !input_manager->GetKeyRight()) {
        GetParent()->GetComponent<PhysicsComponent>()->force = Vector2D(0.0f, 0.0f);
        GetParent()->GetComponent<PhysicsComponent>()->velocity = Vector2D(0.0f, 0.0f);
    } else if (input_manager->GetKeyRight()) {
        GetParent()->GetComponent<PhysicsComponent>()->force = Vector2D(0.05f, 0.0f);
    } else if (input_manager->GetKeyLeft()) {
        GetParent()->GetComponent<PhysicsComponent>()->force = Vector2D(-0.05f, 0.0f);
    }
}