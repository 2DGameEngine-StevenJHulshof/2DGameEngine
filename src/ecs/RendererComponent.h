#pragma once

#include "Component.h"
#include "TransformComponent.h"
#include "texture_types.h"

class RendererComponent : public Component {

public:
    bool visible;
    Texture_t textureID;
    TransformComponent *transform;

    explicit RendererComponent(Texture_t textureID = TEXTURE_DEFAULT);
    ~RendererComponent();

    void Config();
    void Render() override;
};