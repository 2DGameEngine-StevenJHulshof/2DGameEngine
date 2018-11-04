#pragma once

#include "Component.h"

namespace Base {

    class Input : public Component {

    private:

    public:

        Input();

        ~Input();

        void Update() override;
    };
}