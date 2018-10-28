#include "Collider.h"
#include "ComponentManager.h"
#include "CollisionManager.h"
#include "Transform.h"

Collider::Collider(std::string tag) :
    Component(),
    collider(),
    tag(tag),
    transform(nullptr) {

    collision_manager->AddCollider(this);
}

Collider::~Collider() = default;

void Collider::Config() {

    transform = component_manager->AddDependency<Transform>(parent);
}

void Collider::Update() {

    collider.x = static_cast<int>(transform->position.x);
    collider.y = static_cast<int>(transform->position.y);
    collider.w = static_cast<int>(transform->dimension.x);
    collider.h = static_cast<int>(transform->dimension.y);
}