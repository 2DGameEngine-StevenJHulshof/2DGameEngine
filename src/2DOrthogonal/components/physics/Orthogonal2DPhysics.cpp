#include "Orthogonal2DPhysics.h"
#include "ComponentManager.h"
#include "Orthogonal2DTransform.h"
#include "FrameManager.h"

namespace Orthogonal2D {

    Physics::Physics() :
            Base::Physics() {

    }

    Physics::~Physics() = default;

    void Physics::Config() {

        transform = component_manager->AddDependency<Orthogonal2D::Transform>(parent);

        Base::Physics::Config();
    }

    void Physics::Update() {

        float dt = frame_manager->GetDeltaTime();
        transform->position += velocity * Vector2D(dt, dt);

        Base::Physics::Update();
    }
}