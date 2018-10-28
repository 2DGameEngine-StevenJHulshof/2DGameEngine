#include "CollisionManager.h"

CollisionManager *CollisionManager::_instance = nullptr;

CollisionManager::CollisionManager() = default;

CollisionManager::~CollisionManager() = default;

void CollisionManager::AddCollider(Collider *collider) {

    _colliders.push_back(collider);
}


Collider *CollisionManager::IsColliding(Collider *collider) {

    for(auto &c : _colliders) {

        if(collider->tag != c->tag) {
            if (AABB(collider, c)) {
                return c;
            }
        }
    }

    return nullptr;
}

bool CollisionManager::AABB(const SDL_Rect& rectA, const SDL_Rect& rectB) {

    if(rectA.x + rectA.w < rectB.x && rectB.x + rectB.w < rectA.x) LOG_INFO("REKT X");
    if(rectA.y + rectA.h < rectB.y && rectB.y + rectB.h < rectA.y) LOG_INFO("REKT Y");

    if (rectA.x + rectA.w >= rectB.x && rectB.x + rectB.w >= rectA.x && rectA.y + rectA.h >= rectB.y &&
        rectB.y + rectB.h >= rectA.y) {
        return true;
    } else {
        return false;
    }
}


bool CollisionManager::AABB(Collider *colliderA, Collider *colliderB) {

    return AABB(colliderA->collider, colliderB->collider);
}