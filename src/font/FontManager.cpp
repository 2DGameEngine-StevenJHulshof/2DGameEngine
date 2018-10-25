#include "FontManager.h"

FontManager *FontManager::_instance = nullptr;

FontManager::FontManager() :
    _renderer(nullptr) {

}

FontManager::~FontManager() = default;

void FontManager::Config(SDL_Renderer *renderer, std::uint32_t size, std::uint8_t r, std::uint8_t g, std::uint8_t b,
        std::uint8_t a) {

    _renderer = renderer;

    LoadPath();

    for(std::uint16_t ID = 0; ID < static_cast<std::uint16_t>(FONT_TOTAL); ID++) {

        _fonts.push_back(std::make_shared<Font>(static_cast<Font_t>(ID), _renderer, size, r, g, b, a));
    }
}

std::shared_ptr<Font> FontManager::GetFont(Font_t fontID) {
    return _fonts.at(fontID);
}

std::string FontManager::GetFontPath(Font_t fontID) {
    return _fontPath.at(fontID);
}

void FontManager::LoadPath() {

    _fontPath.emplace_back("../fonts/FreeSans.ttf");
}