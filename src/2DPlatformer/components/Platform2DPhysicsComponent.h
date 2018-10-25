#pragma once

#include "PhysicsComponent.h"
#include "FrameManager.h"

class Platform2DPhysicsComponent : public PhysicsComponent {
private:
    const float GRAVITATIONAL_CONSTANT = 0.000981f;
    const float AIR_RESISTANCE_CONSTANT = 100.0f;

    const float MAX_VELOCITY = 0.5f;

    Vector2D _forceInitiated;

    float GetForceAirResistance(float density, float resistanceCoefficient, float area, float velocityAxis);
    float GetForceGravity(float mass, float gravitationalConstant);

public:

    explicit Platform2DPhysicsComponent(float mass);
    ~Platform2DPhysicsComponent();

    void Update() override;
    virtual void InitiateForce(const Vector2D& force);
};