#pragma once
#include "SDL.h"
#include "Vector2D.h"
#include "texture_types.h"

class Texture {
public:
    Texture(Texture_t textureID, SDL_Renderer *renderer);
    ~Texture();

    void Render(Vector2D position, Vector2D dimension, double angle = 0.0, Vector2D *center = nullptr,
            SDL_RendererFlip flip = SDL_FLIP_NONE);

    float w;
    float h;
private:
    SDL_Texture *_texture;
    SDL_Renderer *_renderer;
    bool _isValid;
};