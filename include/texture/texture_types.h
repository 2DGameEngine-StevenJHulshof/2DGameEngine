#pragma once

#include <cstdint>
#include <string>

enum Texture_t : std::uint16_t {
    TEXTURE_DEFAULT,
    TEXTURE_DEFAULT2,
    TEXTURE_TOTAL
};

static const std::string gTexturePath[TEXTURE_TOTAL] = {
        "../res/textures/default.png",
        "../res/textures/default2.png"
};