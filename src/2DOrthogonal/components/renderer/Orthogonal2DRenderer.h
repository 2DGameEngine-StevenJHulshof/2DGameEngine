#pragma once

#include "Renderer.h"

namespace Orthogonal2D {

    class Renderer : public Base::Renderer {
    public:
        explicit Renderer(Texture_t textureID);
        ~Renderer();
    private:
    };
}