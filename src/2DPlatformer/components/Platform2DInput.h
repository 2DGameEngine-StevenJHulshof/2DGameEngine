#pragma once

#include "Input.h"
#include "Platform2DPhysics.h"

class Platform2DInput : public Base::Input {

private:

public:
    Base::Physics *physics;

    Platform2DInput();
    ~Platform2DInput();

    void Config() override;
    void Update() override;
};