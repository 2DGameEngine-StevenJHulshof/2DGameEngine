#pragma once

#include "font_types.h"
#include "SDL.h"
#include "SDL_FontCache.h"
#include <string>
#include <climits>
#include <limits>

class Font {

private:
    FC_Font *_font;
    SDL_Renderer *_renderer;

public:
    Font(Font_t fontID, SDL_Renderer *renderer, std::uint32_t size, std::uint8_t r = 0xFF, std::uint8_t g = 0xFF,
            std::uint8_t b = 0xFF, std::uint8_t a = 0xFF);
    ~Font();

    void Render(float x, float y, std::string prefix);
    void Render(float x, float y, std::string prefix, int value, std::string postfix = "");
    void Render(float x, float y, std::string prefix, float value, std::string postfix = "");
};