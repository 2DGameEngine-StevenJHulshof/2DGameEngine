#pragma once

#include "SDL.h"
#include "Collider.h"

class CollisionManager {
private:
    CollisionManager();
    static CollisionManager *_instance;

    std::vector<Base::Collider*> _colliders;

public:
    ~CollisionManager();
    static CollisionManager *Instance() {
        if(!_instance) {
            _instance = new CollisionManager;
        }
        return _instance;
    }

    void AddCollider(Base::Collider *collider);
    Base::Collider *IsColliding(Base::Collider *collider);

    bool AABB(const SDL_Rect& rectA, const SDL_Rect& rectB);
    bool AABB(Base::Collider *colliderA, Base::Collider *colliderB);
};

#define collision_manager CollisionManager::Instance()