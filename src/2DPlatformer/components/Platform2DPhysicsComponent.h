#pragma once

#include "PhysicsComponent.h"
#include "FrameManager.h"

class Platform2DPhysicsComponent : public PhysicsComponent {
private:
    const float METERS_TO_PIXEL = 320.0f;
    const float GRAVITATIONAL_CONSTANT = 9.81f;

public:

    explicit Platform2DPhysicsComponent(float mass);
    ~Platform2DPhysicsComponent();

    void Update() override;
};