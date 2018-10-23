#pragma once

#include "Component.h"

class TransformComponent : public Component {

private:
    float _xPos;
    float _yPos;

public:
    TransformComponent(float xPos, float yPos);
    ~TransformComponent();

    float GetXPos() { return _xPos; }
    float GetYPos() { return _yPos; }
    void SetXPos(float xPos) { _xPos = xPos; }
    void SetYPos(float yPos) { _yPos = yPos; }
};