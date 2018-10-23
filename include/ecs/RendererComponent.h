#pragma once

#include "Component.h"
#include "texture_types.h"

class RendererComponent : public Component {

private:
    Texture_t _textureID;

public:

    explicit RendererComponent(Texture_t textureID);
    ~RendererComponent();

    void Render() override;
};