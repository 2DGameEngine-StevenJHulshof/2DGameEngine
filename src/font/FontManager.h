#pragma once

#include "SDL.h"
#include "Font.h"
#include <vector>
#include <memory>

class FontManager {

private:

    static FontManager *_instance;
    std::vector<std::shared_ptr<Font>> _fonts;
    std::vector<std::string> _fontPath;
    SDL_Renderer *_renderer;

    FontManager();
    void LoadPath();

public:

    ~FontManager();

    void Config(SDL_Renderer *renderer, std::uint32_t size, std::uint8_t r, std::uint8_t g, std::uint8_t b,
            std::uint8_t a);

    static FontManager *Instance() {
        if(!_instance) {
            _instance = new FontManager;
        }
        return _instance;
    }

    std::shared_ptr<Font> GetFont(Font_t fontID);
    std::string GetFontPath(Font_t fontID);

};

#define font_manager FontManager::Instance()