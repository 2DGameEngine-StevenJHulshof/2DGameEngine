#pragma once

#include "PhysicsComponent.h"
#include "FrameManager.h"

class Platform2DPhysicsComponent : public PhysicsComponent {
private:
    const float MAX_VELOCITY = 0.5f;
    const float MAX_ACCELERATION = MAX_VELOCITY * frame_manager->GetDeltaTime();

public:

    explicit Platform2DPhysicsComponent(float mass);
    ~Platform2DPhysicsComponent();

    void Update() override;
};