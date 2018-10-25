#pragma once

#include "Component.h"
#include "texture_types.h"

class RendererComponent : public Component {

public:
    bool visible;
    Texture_t textureID;

    explicit RendererComponent(Texture_t textureID);
    ~RendererComponent();

    void Render() override;
};