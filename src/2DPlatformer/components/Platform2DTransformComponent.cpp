#include "Platform2DTransformComponent.h"

Platform2DTransformComponent::Platform2DTransformComponent(Vector2D position) :
    TransformComponent(position){

}

Platform2DTransformComponent::~Platform2DTransformComponent() = default;

void Platform2DTransformComponent::Update() {
    if(position.y < 0.0f) position.y = WINDOW_SCREEN_HEIGHT;
    if(position.y > WINDOW_SCREEN_HEIGHT) position.y = 0.0f;
    if(position.x < 0.0f) position.x = WINDOW_SCREEN_WIDTH;
    if(position.x > WINDOW_SCREEN_WIDTH) position.x = 0.0f;
}