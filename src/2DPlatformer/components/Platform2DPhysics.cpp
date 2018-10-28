#include "Platform2DPhysics.h"
#include "Platform2DRenderer.h"
#include "Platform2DTransform.h"
#include "Transform.h"
#include "Renderer.h"
#include "TextureManager.h"
#include "ComponentManager.h"
#include "UserLog.h"

Platform2DPhysics::Platform2DPhysics(float mass) :
    Physics(Vector2D(), Vector2D(), Vector2D(), mass),
    transform(nullptr),
    renderer(nullptr) {

}

Platform2DPhysics::~Platform2DPhysics() = default;

void Platform2DPhysics::Config() {

    transform = component_manager->AddDependency<Platform2DTransform>(parent);
    renderer = component_manager->AddDependency<Platform2DRenderer>(parent);

    Physics::Config();
}

void Platform2DPhysics::Update() {

    float area = (texture_manager->GetTexture(renderer->textureID)->h / METERS_TO_PIXEL) *
            (texture_manager->GetTexture(renderer->textureID)->h / METERS_TO_PIXEL);


    float forceGravitational = mass * GRAVITATIONAL_CONSTANT;
    float forceAirResistanceX = 0.5f * 985.0f * 0.47f * area * velocity.x;
    float forceAirResistanceY = 0.5f * 985.0f * 0.47f * area * velocity.y;


    force.x = impulse.x - forceAirResistanceX;
    force.y = -impulse.y + forceGravitational - forceAirResistanceY;

    acceleration.x = force.x / mass;
    acceleration.y = force.y / mass;

    velocity.x += acceleration.x * frame_manager->GetDeltaTime();
    velocity.y += acceleration.y * frame_manager->GetDeltaTime();

    transform->position.x += METERS_TO_PIXEL * (velocity.x * frame_manager->GetDeltaTime());
    transform->position.y += METERS_TO_PIXEL * (velocity.y * frame_manager->GetDeltaTime());

    impulse.x = 0;
    impulse.y = 0;

    Physics::Update();
}