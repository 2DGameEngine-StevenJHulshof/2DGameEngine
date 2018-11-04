#include "Renderer.h"
#include "ComponentManager.h"
#include "TextureManager.h"
#include "UserLog.h"

namespace Base {

    Renderer::Renderer(Texture_t textureID) :
            Component(),
            visible(true),
            textureID(textureID),
            transform(nullptr) {

    }

    Renderer::~Renderer() = default;

    void Renderer::Config() {

        transform = component_manager->AddDependency<Transform>(parent);


    }

    void Renderer::Update() {
        transform->dimension.x = texture_manager->GetTexture(textureID)->w * transform->scale.x;
        transform->dimension.y = texture_manager->GetTexture(textureID)->h * transform->scale.y;
    }

    void Renderer::Render() {

        if (visible) {
            texture_manager->GetTexture(textureID)->Render(transform->position, transform->dimension);
        }
    }
}