#pragma once
#include "texture_types.h"

class Player {

private:
    Texture_t _textureID;
    float _x;
    float _y;
    float _velocity;

    void Input();

public:
    Player(Texture_t textureID, float x, float y, float velocity);
    ~Player();

    void Update();
    void Render();
};
