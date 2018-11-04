#pragma once

#include "Transform.h"

class Platform2DTransform : public Base::Transform {
private:

public:
    explicit Platform2DTransform(Vector2D position = Vector2D());
    ~Platform2DTransform();

    void Update() override;
};