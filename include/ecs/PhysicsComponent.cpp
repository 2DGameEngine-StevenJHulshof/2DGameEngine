#include "PhysicsComponent.h"

PhysicsComponent::PhysicsComponent(float velocity, float mass) :
    Component(),
    _velocity(velocity),
    _mass(mass) {

}

PhysicsComponent::~PhysicsComponent() = default;

void PhysicsComponent::Update() {

}