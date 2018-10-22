#pragma once

#include "Texture.h"
#include <vector>

class TextureManager {

private:

    static TextureManager *_instance;
    std::vector<Texture*> _textures;

    TextureManager();
    void Clean();

public:

    void Config(SDL_Renderer *renderer);
    Texture *GetTexture(Texture_t textureID);

    static TextureManager *Instance() {
        if (!_instance)
            _instance = new TextureManager;
        return _instance;
    }

    ~TextureManager();
};

#define texture_manager TextureManager::Instance()
#define texture_manager_config(renderer) TextureManager::Instance()->Config(renderer)
#define texture_manager_get(ID) TextureManager::Instance()->GetTexture(ID)