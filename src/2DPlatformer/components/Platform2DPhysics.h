#pragma once

#include "Physics.h"
#include "Transform.h"
#include "Renderer.h"
#include "FrameManager.h"

class Platform2DPhysics : public Physics {
private:
    const float METERS_TO_PIXEL = 320.0f;
    const float GRAVITATIONAL_CONSTANT = 9.81f;

public:

    Transform *transform;
    Renderer *renderer;

    explicit Platform2DPhysics(float mass = 1.0f);
    ~Platform2DPhysics();

    void Config() override;
    void Update() override;
};