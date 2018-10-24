#pragma once

#include "ControllerComponent.h"

class Platform2DControllerComponent : public ControllerComponent {

private:

public:

    Platform2DControllerComponent();
    ~Platform2DControllerComponent();

    void Update() override;
};