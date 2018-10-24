#include "PhysicsComponent.h"

PhysicsComponent::PhysicsComponent(Vector2D velocity, Vector2D acceleration, Vector2D force, float mass) :
    Component(),
    velocity(velocity),
    acceleration(acceleration),
    force(force),
    mass(mass) {

}

PhysicsComponent::~PhysicsComponent() = default;

void PhysicsComponent::Update() {

}