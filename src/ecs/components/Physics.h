#pragma once

#include "Component.h"
#include "Vector2D.h"

class Physics : public Component {

public:

    const float METERS_TO_PIXEL = 320.0f;
    const float GRAVITATIONAL_CONSTANT = 9.81f;

    Vector2D velocity;
    Vector2D acceleration;
    Vector2D force;
    Vector2D impulse;
    Vector2D normal;
    float mass;

    Physics(Vector2D velocity = Vector2D(), Vector2D acceleration = Vector2D(), Vector2D force = Vector2D(),
            float mass = 1.0f);
    ~Physics();

    void Update() override;
};