#pragma once

#include "ControllerComponent.h"
#include "Platform2DPhysicsComponent.h"

class Platform2DControllerComponent : public ControllerComponent {

private:

public:
    PhysicsComponent *physics;

    Platform2DControllerComponent();
    ~Platform2DControllerComponent();

    void Config() override;
    void Update() override;
};