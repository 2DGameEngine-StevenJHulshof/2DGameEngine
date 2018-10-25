#pragma once

#include "Component.h"
#include "Vector2D.h"

class TransformComponent : public Component {

private:



public:
    Vector2D position;
    Vector2D dimension;
    Vector2D scale;

    explicit TransformComponent(Vector2D position, Vector2D scale = Vector2D(1.0f, 1.0f));
    ~TransformComponent();

    void Update() override;
};