#pragma once

#include "TransformComponent.h"

class Platform2DTransformComponent : public TransformComponent {
private:

public:
    explicit Platform2DTransformComponent(Vector2D position = Vector2D());
    ~Platform2DTransformComponent();

    void Update() override;
};