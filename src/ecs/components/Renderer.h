#pragma once

#include "Component.h"
#include "Transform.h"
#include "texture_types.h"

namespace Base {

    class Renderer : public Component {

    public:

        bool visible;
        Texture_t textureID;
        Transform *transform;

        explicit Renderer(Texture_t textureID = TEXTURE_DEFAULT);

        ~Renderer();

        void Config() override;
        void Update() override;
        void Render() override;
    };
}