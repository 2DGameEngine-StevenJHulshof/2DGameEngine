#include "TransformComponent.h"
#include "app_config.h"
#include "UserLog.h"

TransformComponent::TransformComponent(Vector2D position) :
    Component(),
    position(position) {
}

TransformComponent::~TransformComponent() = default;

void TransformComponent::Update() {
    if(position.y < 0.0f) position.y = WINDOW_SCREEN_HEIGHT;
    if(position.y > WINDOW_SCREEN_HEIGHT) position.y = 0.0f;
    if(position.x < 0.0f) position.x = WINDOW_SCREEN_WIDTH;
    if(position.x > WINDOW_SCREEN_WIDTH) position.x = 0.0f;
}