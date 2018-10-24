#include "TransformComponent.h"

TransformComponent::TransformComponent(Vector2D position) :
    Component(),
    position(position) {
}

TransformComponent::~TransformComponent() = default;