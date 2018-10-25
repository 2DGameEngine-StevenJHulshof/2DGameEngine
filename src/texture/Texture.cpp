#include "UserLog.h"
#include "Texture.h"
#include "SDL.h"
#include "SDL_image.h"
#include "TextureManager.h"

Texture::Texture(Texture_t textureID, SDL_Renderer *renderer) :
        _texture(nullptr),
        _renderer(renderer),
        _isValid(false),
        w(0),
        h(0) {

    _texture = IMG_LoadTexture(_renderer, texture_manager->GetTexturePath(textureID).c_str());
    if(_texture == nullptr) {
        LOG_WARNING("Texture loading failed: %s", SDL_GetError());
    }

    int width = 0;
    int height = 0;
    if(SDL_QueryTexture(_texture, nullptr, nullptr, &width, &height) != 0) {
        LOG_WARNING("Texture query failed: %s", SDL_GetError());
    } else {
        w = static_cast<float>(width);
        h = static_cast<float>(height);
        _isValid = true;
    }
}

Texture::~Texture() {

    SDL_DestroyTexture(_texture);
}

void Texture::Render(float x, float y) {

    if(_isValid) {

        SDL_Rect textureRect;
        textureRect.h = static_cast<int>(h);
        textureRect.w = static_cast<int>(w);
        textureRect.x = static_cast<int>(x);
        textureRect.y = static_cast<int>(y);

        if (SDL_RenderCopy(_renderer, _texture, nullptr, &textureRect) != 0) {
            LOG_WARNING("Texture could not be rendered: %s", SDL_GetError());
            _isValid = false;
        }
    }
}