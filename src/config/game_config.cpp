#include "game_config.h"
#include "TextureManager.h"

void add_path(std::vector<std::string>& vector, std::string path) {
    vector.emplace_back("res/" + path);
}

void add_texture_path(std::string path) {
    texture_manager->AddTexturePath("res/textures/" + path);
}