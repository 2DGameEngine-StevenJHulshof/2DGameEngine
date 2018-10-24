#include "Platform2DPhysicsComponent.h"
#include "TransformComponent.h"
#include "FrameManager.h"
#include "UserLog.h"

Platform2DPhysicsComponent::Platform2DPhysicsComponent(float mass) :
    PhysicsComponent(Vector2D(0.0f, 0.0f), Vector2D(0.0f, 0.0f), Vector2D(0.0f, 0.0f), mass) {

}

Platform2DPhysicsComponent::~Platform2DPhysicsComponent() = default;

void Platform2DPhysicsComponent::Update() {

    acceleration.x = force.x / mass;
    acceleration.y = force.y / mass;

    velocity.x += acceleration.x * frame_manager->GetDeltaTime();
    velocity.y += acceleration.y * frame_manager->GetDeltaTime();

    GetParent()->GetComponent<TransformComponent>()->position.x += velocity.x * frame_manager->GetDeltaTime();
    GetParent()->GetComponent<TransformComponent>()->position.y += velocity.y * frame_manager->GetDeltaTime();

    if(velocity.x >= MAX_VELOCITY) velocity.x = MAX_VELOCITY;
    if(velocity.x <= -MAX_VELOCITY) velocity.x = -MAX_VELOCITY;
    if(velocity.y >= MAX_VELOCITY) velocity.y = MAX_VELOCITY;
    if(velocity.y <= -MAX_VELOCITY) velocity.y = -MAX_VELOCITY;
}