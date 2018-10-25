#include "Platform2DPhysicsComponent.h"
#include "TransformComponent.h"
#include "RendererComponent.h"
#include "TextureManager.h"
#include "UserLog.h"

Platform2DPhysicsComponent::Platform2DPhysicsComponent(float mass) :
    PhysicsComponent(Vector2D(), Vector2D(), Vector2D(), mass) {

}

Platform2DPhysicsComponent::~Platform2DPhysicsComponent() = default;

void Platform2DPhysicsComponent::Update() {

    float area = (texture_manager->GetTexture(GetParent()->GetComponent<RendererComponent>()->textureID)->h /
            METERS_TO_PIXEL) * (texture_manager->GetTexture(GetParent()->GetComponent<RendererComponent>()->
                    textureID)->h / METERS_TO_PIXEL);


    float forceGravitational = mass * GRAVITATIONAL_CONSTANT;
    float forceAirResistanceX = 0.5f * 985.0f * 0.47f * area * velocity.x;
    float forceAirResistanceY = 0.5f * 985.0f * 0.47f * area * velocity.y;


    force.x = impulse.x - forceAirResistanceX;
    force.y = -impulse.y + forceGravitational - forceAirResistanceY;

    acceleration.x = force.x / mass;
    acceleration.y = force.y / mass;

    velocity.x += acceleration.x * frame_manager->GetDeltaTime();
    velocity.y += acceleration.y * frame_manager->GetDeltaTime();

    GetParent()->GetComponent<TransformComponent>()->position.x += METERS_TO_PIXEL *
            (velocity.x * frame_manager->GetDeltaTime());

    GetParent()->GetComponent<TransformComponent>()->position.y += METERS_TO_PIXEL *
            (velocity.y * frame_manager->GetDeltaTime());

    impulse.x = 0;
    impulse.y = 0;
}