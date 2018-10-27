#include "UserLog.h"
#include "TextureManager.h"

TextureManager *TextureManager::_instance = nullptr;

TextureManager::TextureManager() = default;

TextureManager::~TextureManager() = default;

void TextureManager::Config(SDL_Renderer *renderer) {

    LoadPath();

    for(std::uint16_t ID = 0; ID < static_cast<std::uint16_t>(TEXTURE_TOTAL); ID++) {
        _textures.push_back(std::make_shared<Texture>(static_cast<Texture_t>(ID), renderer));
    }
}

void TextureManager::LoadPath() {

    _texturePath.emplace_back("/textures/default.png");
    _texturePath.emplace_back("/textures/default2.png");
}

std::shared_ptr<Texture> TextureManager::GetTexture(Texture_t textureID) {
    return _textures.at(textureID);
}


std::string TextureManager::GetTexturePath(Texture_t textureID) {
    return _texturePath.at(textureID);
}