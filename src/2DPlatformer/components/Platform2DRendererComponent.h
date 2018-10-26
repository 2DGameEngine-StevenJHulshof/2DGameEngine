#pragma once

#include "RendererComponent.h"

class Platform2DRendererComponent : public RendererComponent {
private:
public:
    explicit Platform2DRendererComponent(Texture_t textureID = TEXTURE_DEFAULT);
    ~Platform2DRendererComponent();

    void Config() override;
    void Update() override;

};