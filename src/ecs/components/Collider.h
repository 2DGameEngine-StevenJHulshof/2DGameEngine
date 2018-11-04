#pragma once

#include <string>
#include "SDL.h"
#include "Transform.h"
#include "Component.h"

namespace Base {

    class Collider : public Component {

    private:

    public:
        SDL_Rect collider;
        std::string tag;
        Transform *transform;

        explicit Collider(std::string tag);

        ~Collider();

        void Config();

        void Update();
    };
}