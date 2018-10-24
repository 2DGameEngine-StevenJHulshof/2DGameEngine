#include "UserLog.h"
#include "TextureManager.h"

TextureManager *TextureManager::_instance = nullptr;

TextureManager::TextureManager() = default; /*{
//    LOG_ALLOC(this, __PRETTY_FUNCTION__);
}*/

TextureManager::~TextureManager() {
//    LOG_DEALLOC(this, __PRETTY_FUNCTION__);
    Clean();
}

void TextureManager::Config(SDL_Renderer *renderer) {

    LoadPath();

    for(std::uint16_t ID = 0; ID < static_cast<std::uint16_t>(TEXTURE_TOTAL); ID++) {
        _textures.push_back(new Texture(static_cast<Texture_t>(ID), renderer));
    }
}

void TextureManager::Clean() {

    for(auto texture : _textures) {
        delete texture;
    }
}

void TextureManager::LoadPath() {

    _texturePath.emplace_back("../res/textures/default.png");
    _texturePath.emplace_back("../res/textures/default2.png");
}

Texture *TextureManager::GetTexture(Texture_t textureID) {
    return _textures.at(textureID);
}


std::string TextureManager::GetTexturePath(Texture_t textureID) {
    return _texturePath.at(textureID);
}