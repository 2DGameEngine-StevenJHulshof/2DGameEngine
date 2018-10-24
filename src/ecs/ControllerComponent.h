#pragma once

#include "Component.h"

class ControllerComponent : public Component {

private:

public:

    ControllerComponent();
    ~ControllerComponent();

    void Update() override;
};