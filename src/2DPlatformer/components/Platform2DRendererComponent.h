#pragma once

#include "RendererComponent.h"

class Platform2DRendererComponent : public RendererComponent {
private:
public:
    explicit Platform2DRendererComponent(Texture_t textureID);
    ~Platform2DRendererComponent();

    void Update() override;

};