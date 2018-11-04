#include "Physics.h"

namespace Base {

    Physics::Physics(Vector2D velocity, Vector2D acceleration, Vector2D force, float mass) :
            Component(),
            velocity(velocity),
            acceleration(acceleration),
            force(force),
            impulse(Vector2D()),
            mass(mass),
            normal(Vector2D()) {

    }

    Physics::~Physics() = default;

    void Physics::Update() {

    }
}