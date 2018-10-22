#pragma once

#include <cstdint>
#include <string>

enum Texture_t : std::uint8_t {
    TEXTURE_DEFAULT,
    TEXTURE_TOTAL
};

static const std::string gTexturePath[TEXTURE_TOTAL] = {
        "../res/textures/default.png"
};