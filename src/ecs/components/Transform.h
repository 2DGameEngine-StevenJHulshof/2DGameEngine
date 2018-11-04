#pragma once

#include "Component.h"
#include "Vector2D.h"

namespace Base {

    class Transform : public Component {

    private:


    public:
        Vector2D position;
        Vector2D dimension;
        Vector2D scale;

        explicit Transform(Vector2D position = Vector2D(), Vector2D scale = Vector2D(1.0f, 1.0f));

        ~Transform();

        void Update() override;
    };
}