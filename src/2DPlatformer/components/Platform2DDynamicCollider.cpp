#include "Platform2DDynamicCollider.h"
#include "Platform2DPhysics.h"
#include "ComponentManager.h"
#include "CollisionManager.h"

Platform2DDynamicCollider::Platform2DDynamicCollider(std::string tag) :
        Platform2DCollider(tag),
        _isColliding(false),
        physics(nullptr) {


}

Platform2DDynamicCollider::~Platform2DDynamicCollider() = default;

void Platform2DDynamicCollider::Config() {

    physics = component_manager->AddDependency<Platform2DPhysics>(parent);

    Platform2DCollider::Config();
}

void Platform2DDynamicCollider::Update() {

//    Collider *otherCollider = collision_manager->IsColliding(this);
//    if(otherCollider != nullptr) {
//       if(!_isColliding) {
//           physics->acceleration.y *= -1;
//           physics->velocity.y *= -1;
//           _isColliding = true;
//       }
//    } else {
//        _isColliding = false;
//    }

    Platform2DCollider::Update();
}