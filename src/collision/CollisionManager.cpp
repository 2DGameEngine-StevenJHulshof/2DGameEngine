#include "CollisionManager.h"

CollisionManager *CollisionManager::_instance = nullptr;

CollisionManager::CollisionManager() = default;

CollisionManager::~CollisionManager() = default;

bool CollisionManager::AABB(const SDL_Rect& rectA, const SDL_Rect& rectB) {

    if (rectA.x + rectA.w >= rectB.x && rectB.x + rectB.w >= rectA.x && rectA.y + rectA.h >= rectB.y &&
        rectB.y + rectB.h >= rectA.y) {
        return true;
    } else {
        return false;
    }
}