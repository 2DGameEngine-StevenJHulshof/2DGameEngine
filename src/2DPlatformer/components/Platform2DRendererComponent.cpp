#include "Platform2DRendererComponent.h"
#include "Platform2DTransformComponent.h"
#include "ComponentManager.h"
#include "UserLog.h"

Platform2DRendererComponent::Platform2DRendererComponent(Texture_t textureID) :
    RendererComponent(textureID) {

}

Platform2DRendererComponent::~Platform2DRendererComponent() = default;

void Platform2DRendererComponent::Config() {

    if(GetParent()->GetComponent<TransformComponent>() == nullptr) {
        LOG_INVALID("Invalid reference to Transform from Renderer -> Creating default Transform");
        transform = component_manager->New<Platform2DTransformComponent>(GetParent());
        GetParent()->Config();
    } else {
        transform = GetParent()->GetComponent<TransformComponent>();
    }

    RendererComponent::Config();
}

void Platform2DRendererComponent::Update() {

}