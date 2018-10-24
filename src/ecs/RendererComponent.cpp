#include "RendererComponent.h"
#include "TransformComponent.h"
#include "TextureManager.h"

RendererComponent::RendererComponent(Texture_t textureID) :
    Component(),
    textureID(textureID) {

}

RendererComponent::~RendererComponent() = default;

void RendererComponent::Render() {

    texture_manager->GetTexture(textureID)->Render(GetParent()->GetComponent<TransformComponent>()->position.x,
            GetParent()->GetComponent<TransformComponent>()->position.y);
}