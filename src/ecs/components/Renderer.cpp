#include "Renderer.h"
#include "ComponentManager.h"
#include "TextureManager.h"
#include "UserLog.h"

Renderer::Renderer(Texture_t textureID) :
    Component(),
    visible(true),
    textureID(textureID) {

}

Renderer::~Renderer() = default;

void Renderer::Config() {

    if(GetParent()->GetComponent<Transform>() == nullptr) {
        LOG_INVALID("Invalid reference to Transform from Renderer -> Creating default Transform");
        transform = component_manager->New<Transform>(GetParent());
        GetParent()->Config();
    } else {
        transform = GetParent()->GetComponent<Transform>();
    }

    transform->dimension.x = texture_manager->GetTexture(textureID)->w;
    transform->dimension.y = texture_manager->GetTexture(textureID)->h;
}

void Renderer::Render() {

    if(visible) {
        texture_manager->GetTexture(textureID)->Render(
                GetParent()->GetComponent<Transform>()->position.x,
                GetParent()->GetComponent<Transform>()->position.y);
    }
}