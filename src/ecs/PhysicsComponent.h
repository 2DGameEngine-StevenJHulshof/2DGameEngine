#pragma once

#include "Component.h"
#include "Vector2D.h"

class PhysicsComponent : public Component {

public:

    Vector2D velocity;
    Vector2D acceleration;
    Vector2D force;
    Vector2D impulse;
    float mass;

    PhysicsComponent(Vector2D velocity, Vector2D acceleration, Vector2D force, float mass);
    ~PhysicsComponent();

    void Update() override;
};