#pragma once

#include "Orthogonal2DInput.h"
#include "Orthogonal2DPhysics.h"

namespace Orthogonal2D {

    class InputPlayer : public Orthogonal2D::Input {
    public:
        Physics *physics;

        explicit InputPlayer();

        ~InputPlayer();
        void Config() override;
        void Update() override;

    private:
    };
}