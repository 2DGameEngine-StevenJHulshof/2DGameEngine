#pragma once

#include "Texture.h"
#include <vector>
#include <memory>

class TextureManager {

private:

    static TextureManager *_instance;

    std::vector<std::shared_ptr<Texture>> _textures;
    std::vector<std::string> _texturePath;

    TextureManager();
    void Clean();
    void LoadPath();

public:

    void Config(SDL_Renderer *renderer);
    std::shared_ptr<Texture> GetTexture(Texture_t textureID);
    std::string GetTexturePath(Texture_t textureID);

    static TextureManager *Instance() {
        if (!_instance)
            _instance = new TextureManager;
        return _instance;
    }

    ~TextureManager();
};

#define texture_manager TextureManager::Instance()