#include "Platform2DPhysicsComponent.h"
#include "Platform2DRendererComponent.h"
#include "Platform2DTransformComponent.h"
#include "TransformComponent.h"
#include "RendererComponent.h"
#include "TextureManager.h"
#include "ComponentManager.h"
#include "UserLog.h"

Platform2DPhysicsComponent::Platform2DPhysicsComponent(float mass) :
    PhysicsComponent(Vector2D(), Vector2D(), Vector2D(), mass) {

}

Platform2DPhysicsComponent::~Platform2DPhysicsComponent() = default;

void Platform2DPhysicsComponent::Config() {

    if(GetParent()->GetComponent<TransformComponent>() == nullptr) {
        LOG_INVALID("Invalid reference to Platform2DTransform from Platform2DPhysics -> Creating default Platform2DTransform");
        transform = component_manager->New<Platform2DTransformComponent>(GetParent());
        GetParent()->Config();
    } else {
        transform = GetParent()->GetComponent<TransformComponent>();
    }

    if(GetParent()->GetComponent<RendererComponent>() == nullptr) {
        LOG_INVALID("Invalid reference to Platform2DRenderer from Platform2DPhysics -> Creating default Platform2DRenderer");
        renderer = component_manager->New<Platform2DRendererComponent>(GetParent());
        GetParent()->Config();
    } else {
        renderer = GetParent()->GetComponent<RendererComponent>();
    }
}

void Platform2DPhysicsComponent::Update() {

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
}