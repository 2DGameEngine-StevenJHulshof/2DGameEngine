#include "Platform2DCollider.h"
#include "Platform2DTransform.h"
#include "ComponentManager.h"

Platform2DCollider::Platform2DCollider(std::string tag) :
    Base::Collider(tag) {

}

Platform2DCollider::~Platform2DCollider() = default;

void Platform2DCollider::Config() {

    transform = component_manager->AddDependency<Platform2DTransform>(parent);

    Base::Collider::Config();
}