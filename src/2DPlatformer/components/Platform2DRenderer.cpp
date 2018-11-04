#include "Platform2DRenderer.h"
#include "Platform2DTransform.h"
#include "ComponentManager.h"
#include "UserLog.h"

Platform2DRenderer::Platform2DRenderer(Texture_t textureID) :
    Base::Renderer(textureID) {

}

Platform2DRenderer::~Platform2DRenderer() = default;

void Platform2DRenderer::Config() {

    transform = component_manager->AddDependency<Platform2DTransform>(parent);

    Base::Renderer::Config();
}