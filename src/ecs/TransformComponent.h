#pragma once

#include "Component.h"
#include "Vector2D.h"

class TransformComponent : public Component {

private:



public:
    Vector2D position;

    explicit TransformComponent(Vector2D position);
    ~TransformComponent();
};