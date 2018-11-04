#pragma once

#include "Transform.h"

namespace Orthogonal2D {

    class Transform : public Base::Transform {
    public:
        explicit Transform(Vector2D position = Vector2D(), Vector2D scale = Vector2D(1.0f, 1.0f));
        ~Transform();
    private:
    };
}