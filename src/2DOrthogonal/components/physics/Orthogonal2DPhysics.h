#pragma once

#include "Physics.h"
#include "Orthogonal2DTransform.h"

namespace Orthogonal2D {

    class Physics : public Base::Physics {
    public:
        Base::Transform *transform;

        explicit Physics();
        ~Physics();
        void Config() override;
        void Update() override;
    private:
    };
}