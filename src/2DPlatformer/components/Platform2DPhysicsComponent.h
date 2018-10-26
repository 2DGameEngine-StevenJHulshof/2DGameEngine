#pragma once

#include "PhysicsComponent.h"
#include "TransformComponent.h"
#include "RendererComponent.h"
#include "FrameManager.h"

class Platform2DPhysicsComponent : public PhysicsComponent {
private:
    const float METERS_TO_PIXEL = 320.0f;
    const float GRAVITATIONAL_CONSTANT = 9.81f;

public:

    TransformComponent *transform;
    RendererComponent *renderer;

    explicit Platform2DPhysicsComponent(float mass = 1.0f);
    ~Platform2DPhysicsComponent();

    void Config() override;
    void Update() override;
};