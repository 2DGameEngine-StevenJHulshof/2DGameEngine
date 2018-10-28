#pragma once

#include "SDL.h"
#include "Collider.h"

class CollisionManager {
private:
    CollisionManager();
    static CollisionManager *_instance;

    std::vector<Collider*> _colliders;

public:
    ~CollisionManager();
    static CollisionManager *Instance() {
        if(!_instance) {
            _instance = new CollisionManager;
        }
        return _instance;
    }

    void AddCollider(Collider *collider);
    Collider *IsColliding(Collider *collider);

    bool AABB(const SDL_Rect& rectA, const SDL_Rect& rectB);
    bool AABB(Collider *colliderA, Collider *colliderB);
};

#define collision_manager CollisionManager::Instance()