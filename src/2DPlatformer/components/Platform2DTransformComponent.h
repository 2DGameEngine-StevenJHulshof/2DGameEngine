#pragma once

#include "TransformComponent.h"

class Platform2DTransformComponent : public TransformComponent {
private:

public:
    Platform2DTransformComponent(Vector2D position);
    ~Platform2DTransformComponent();

    void Update() override;
};