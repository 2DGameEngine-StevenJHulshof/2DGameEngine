#include "UserLog.h"
#include "Texture.h"
#include "SDL.h"
#include "SDL_image.h"

Texture::Texture(Texture_t textureID, SDL_Renderer *renderer) :
        _texture(nullptr),
        _renderer(renderer),
        _isValid(false),
        _width(0),
        _height(0) {

//    LOG_ALLOC(this, __PRETTY_FUNCTION__);

    if(textureID >= TEXTURE_TOTAL) {
        LOG_CRITICAL("Texture ID is out of bounds!");
    } else {
        _texture = IMG_LoadTexture(_renderer, "../res/textures/default.png");
        if(_texture == nullptr) {
            LOG_WARNING("Texture loading failed: %s", SDL_GetError());
        }
        if(SDL_QueryTexture(_texture, nullptr, nullptr, &_width, &_height) != 0) {
            LOG_WARNING("Texture query failed: %s", SDL_GetError());
        } else {
            _isValid = true;
        }
    }
}

Texture::~Texture() {
//    LOG_DEALLOC(this, __PRETTY_FUNCTION__);
    SDL_DestroyTexture(_texture);
}

void Texture::render(int x, int y) {

    if(_isValid) {

        SDL_Rect textureRect;
        textureRect.h = _height;
        textureRect.w = _width;
        textureRect.x = x;
        textureRect.y = y;

        if (SDL_RenderCopy(_renderer, _texture, nullptr, &textureRect) != 0) {
            LOG_WARNING("Texture could not be rendered: %s", SDL_GetError());
            _isValid = false;
        }
    }
}