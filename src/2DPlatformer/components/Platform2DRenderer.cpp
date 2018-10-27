#include "Platform2DRenderer.h"
#include "Platform2DTransform.h"
#include "ComponentManager.h"
#include "UserLog.h"

Platform2DRenderer::Platform2DRenderer(Texture_t textureID) :
    Renderer(textureID) {

}

Platform2DRenderer::~Platform2DRenderer() = default;

void Platform2DRenderer::Config() {

    if(GetParent()->GetComponent<Transform>() == nullptr) {
        LOG_INVALID("Invalid reference to Transform from Renderer -> Creating default Transform");
        transform = component_manager->New<Platform2DTransform>(GetParent());
        GetParent()->Config();
    } else {
        transform = GetParent()->GetComponent<Transform>();
    }

    Renderer::Config();
}

void Platform2DRenderer::Update() {

}