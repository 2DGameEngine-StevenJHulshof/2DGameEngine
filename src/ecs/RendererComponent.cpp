#include "RendererComponent.h"
#include "TransformComponent.h"
#include "TextureManager.h"

RendererComponent::RendererComponent(Texture_t textureID) :
    Component(),
    visible(true),
    textureID(textureID) {

}

RendererComponent::~RendererComponent() = default;

void RendererComponent::Render() {

    if(GetParent()->GetComponent<TransformComponent>() != nullptr) {
        GetParent()->GetComponent<TransformComponent>()->dimension.x =
                texture_manager->GetTexture(textureID)->w;
        GetParent()->GetComponent<TransformComponent>()->dimension.y =
                texture_manager->GetTexture(textureID)->h;
    }

    if(visible) {
        texture_manager->GetTexture(textureID)->Render(
                GetParent()->GetComponent<TransformComponent>()->position.x,
                GetParent()->GetComponent<TransformComponent>()->position.y);
    }
}