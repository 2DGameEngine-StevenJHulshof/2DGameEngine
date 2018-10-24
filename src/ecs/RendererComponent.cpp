#include "RendererComponent.h"
#include "TransformComponent.h"
#include "TextureManager.h"

RendererComponent::RendererComponent(Texture_t textureID) :
    Component(),
    _textureID(textureID) {

}

RendererComponent::~RendererComponent() = default;

void RendererComponent::Render() {

    texture_manager->GetTexture(_textureID)->Render(
            GetParent()->GetComponent<TransformComponent>()->GetXPos(),
            GetParent()->GetComponent<TransformComponent>()->GetYPos());
}