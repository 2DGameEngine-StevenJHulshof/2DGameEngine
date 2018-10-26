#pragma once

#include "SDL.h"

class CollisionManager {
private:
    CollisionManager();
    static CollisionManager *_instance;

public:
    ~CollisionManager();
    static CollisionManager *Instance() {
        if(!_instance) {
            _instance = new CollisionManager;
        }
        return _instance;
    }

    bool AABB(const SDL_Rect& rectA, const SDL_Rect& rectB);
};

#define collision_manager CollisionManager::Instance()