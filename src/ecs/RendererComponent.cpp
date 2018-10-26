#include "RendererComponent.h"
#include "ComponentManager.h"
#include "TextureManager.h"
#include "UserLog.h"

RendererComponent::RendererComponent(Texture_t textureID) :
    Component(),
    visible(true),
    textureID(textureID) {

}

RendererComponent::~RendererComponent() = default;

void RendererComponent::Config() {

    if(GetParent()->GetComponent<TransformComponent>() == nullptr) {
        LOG_INVALID("Invalid reference to Transform from Renderer -> Creating default Transform");
        transform = component_manager->New<TransformComponent>(GetParent());
        GetParent()->Config();
    } else {
        transform = GetParent()->GetComponent<TransformComponent>();
    }

    transform->dimension.x = texture_manager->GetTexture(textureID)->w;
    transform->dimension.y = texture_manager->GetTexture(textureID)->h;
}

void RendererComponent::Render() {

    if(visible) {
        texture_manager->GetTexture(textureID)->Render(
                GetParent()->GetComponent<TransformComponent>()->position.x,
                GetParent()->GetComponent<TransformComponent>()->position.y);
    }
}