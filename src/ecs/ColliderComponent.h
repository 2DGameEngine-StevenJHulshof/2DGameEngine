#pragma once

#include <string>
#include "SDL.h"
#include "TransformComponent.h"
#include "Component.h"

class ColliderComponent : public Component {

private:

public:
    SDL_Rect collider;
    std::string tag;
    TransformComponent *transform;

    ColliderComponent();
    ~ColliderComponent();
    void Config();
};