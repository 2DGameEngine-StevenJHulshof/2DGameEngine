#pragma once

#include <string>
#include "SDL.h"
#include "Transform.h"
#include "Component.h"

class Collider : public Component {

private:

public:
    SDL_Rect collider;
    std::string tag;
    Transform *transform;

    Collider();
    ~Collider();
    void Config();
};