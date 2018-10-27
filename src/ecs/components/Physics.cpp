#include "Physics.h"

Physics::Physics(Vector2D velocity, Vector2D acceleration, Vector2D force, float mass) :
    Component(),
    velocity(velocity),
    acceleration(acceleration),
    force(force),
    impulse(Vector2D()),
    mass(mass) {

}

Physics::~Physics() = default;

void Physics::Update() {

}