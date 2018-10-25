#include "Platform2DPhysicsComponent.h"
#include "TransformComponent.h"
#include "RendererComponent.h"
#include "TextureManager.h"
#include "UserLog.h"

Platform2DPhysicsComponent::Platform2DPhysicsComponent(float mass) :
    PhysicsComponent(Vector2D(0.0f, 0.0f), Vector2D(0.0f, 0.0f), Vector2D(0.0f, 0.0f), mass),
    _forceInitiated(Vector2D(0.0f, 0.0f)){

}

Platform2DPhysicsComponent::~Platform2DPhysicsComponent() = default;

void Platform2DPhysicsComponent::Update() {

//    float area = texture_manager->GetTexture(GetParent()->GetComponent<RendererComponent>()->textureID)->h *
//                 texture_manager->GetTexture(GetParent()->GetComponent<RendererComponent>()->textureID)->w;
//
//
//    force.x = _forceInitiated.x - GetForceAirResistance(1, AIR_RESISTANCE_CONSTANT, area, velocity.x);
//    force.y = _forceInitiated.y + GetForceGravity(mass, GRAVITATIONAL_CONSTANT) -
//            GetForceAirResistance(1, AIR_RESISTANCE_CONSTANT, area, velocity.y);
//
//    acceleration.x = force.x / mass;
//    acceleration.y = force.y / mass;
//
//    velocity.x += acceleration.x;
//    velocity.y += acceleration.y;
//
//    LOG_INFO("v: %f, %f; a: %f, %f; f: %f, %f; a: %f", velocity.x, velocity.y, acceleration.x, acceleration.y, force.x, force.y, area);
//
//    GetParent()->GetComponent<TransformComponent>()->position.x += velocity.x;
//    GetParent()->GetComponent<TransformComponent>()->position.y += velocity.y;
//
//    _forceInitiated.x = 0;
//    _forceInitiated.y = 0;
}

float Platform2DPhysicsComponent::GetForceAirResistance(float density, float resistanceCoefficient, float area, float velocityAxis) {
//    if(velocityAxis < 0.1f || velocityAxis > -0.1f) return 0;
    return (0.5f * (density * resistanceCoefficient * area) * (velocityAxis * velocityAxis));
}

float Platform2DPhysicsComponent::GetForceGravity(float mass, float gravitationalConstant) {
    return (mass * gravitationalConstant);
}

void Platform2DPhysicsComponent::InitiateForce(const Vector2D& force) {
    _forceInitiated = force;
}