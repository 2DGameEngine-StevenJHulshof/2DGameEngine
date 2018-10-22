#pragma once
#include "SDL.h"
#include "texture_types.h"

class Texture {
public:
    Texture(Texture_t textureID, SDL_Renderer *renderer);
    ~Texture();

    void Render(float x, float y);
private:
    SDL_Texture *_texture;
    SDL_Renderer *_renderer;
    bool _isValid;
    int _width;
    int _height;
};