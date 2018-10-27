#pragma once

#include "Component.h"
#include "Vector2D.h"

class Physics : public Component {

public:

    Vector2D velocity;
    Vector2D acceleration;
    Vector2D force;
    Vector2D impulse;
    float mass;

    Physics(Vector2D velocity = Vector2D(), Vector2D acceleration = Vector2D(), Vector2D force = Vector2D(),
            float mass = 1.0f);
    ~Physics();

    void Update() override;
};