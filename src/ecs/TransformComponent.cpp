#include "TransformComponent.h"
#include "UserLog.h"

TransformComponent::TransformComponent(Vector2D position, Vector2D scale) :
    Component(),
    position(position * scale),
    dimension(Vector2D()),
    scale(scale) {

}

TransformComponent::~TransformComponent() = default;

void TransformComponent::Update() {

}