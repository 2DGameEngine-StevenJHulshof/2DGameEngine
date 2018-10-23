#include "ControllerComponent.h"
#include "InputManager.h"
#include "FrameManager.h"
#include "TransformComponent.h"
#include "PhysicsComponent.h"

ControllerComponent::ControllerComponent() :
    Component() {

}

ControllerComponent::~ControllerComponent() = default;

void ControllerComponent::Update() {

    if(input_manager->GetKeyD()) {
        GetParent()->GetComponent<TransformComponent>()->SetXPos(
                GetParent()->GetComponent<TransformComponent>()->GetXPos() +
                GetParent()->GetComponent<PhysicsComponent>()->GetVelocity() * frame_manager->GetDeltaTime());
    }
    if(input_manager->GetKeyA()) {
        GetParent()->GetComponent<TransformComponent>()->SetXPos(
                GetParent()->GetComponent<TransformComponent>()->GetXPos() -
                GetParent()->GetComponent<PhysicsComponent>()->GetVelocity() * frame_manager->GetDeltaTime());
    }
    if(input_manager->GetKeyW()) {
        GetParent()->GetComponent<TransformComponent>()->SetYPos(
                GetParent()->GetComponent<TransformComponent>()->GetYPos() -
                GetParent()->GetComponent<PhysicsComponent>()->GetVelocity() * frame_manager->GetDeltaTime());
    }
    if(input_manager->GetKeyS()) {
        GetParent()->GetComponent<TransformComponent>()->SetYPos(
                GetParent()->GetComponent<TransformComponent>()->GetYPos() +
                GetParent()->GetComponent<PhysicsComponent>()->GetVelocity() * frame_manager->GetDeltaTime());
    }
}