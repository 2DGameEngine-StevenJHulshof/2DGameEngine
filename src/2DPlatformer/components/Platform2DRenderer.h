#pragma once

#include "Renderer.h"

class Platform2DRenderer : public Renderer {
private:
public:
    explicit Platform2DRenderer(Texture_t textureID = TEXTURE_DEFAULT);
    ~Platform2DRenderer();

    void Config() override;
};