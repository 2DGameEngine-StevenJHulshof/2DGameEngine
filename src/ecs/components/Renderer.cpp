#include "Renderer.h"
#include "ComponentManager.h"
#include "TextureManager.h"
#include "UserLog.h"

Renderer::Renderer(Texture_t textureID) :
    Component(),
    visible(true),
    textureID(textureID),
    transform(nullptr) {

}

Renderer::~Renderer() = default;

void Renderer::Config() {

    transform = component_manager->AddDependency<Transform>(parent);

    transform->dimension.x = texture_manager->GetTexture(textureID)->w;
    transform->dimension.y = texture_manager->GetTexture(textureID)->h;
}

void Renderer::Render() {

    if(visible) {
        texture_manager->GetTexture(textureID)->Render(parent->GetComponent<Transform>()->position);
    }
}