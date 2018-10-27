#pragma once

#include "Component.h"
#include "Transform.h"
#include "texture_types.h"

class Renderer : public Component {

public:
    bool visible;
    Texture_t textureID;
    Transform *transform;

    explicit Renderer(Texture_t textureID = TEXTURE_DEFAULT);
    ~Renderer();

    void Config();
    void Render() override;
};