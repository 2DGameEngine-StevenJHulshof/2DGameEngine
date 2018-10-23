#include "TransformComponent.h"

TransformComponent::TransformComponent(float xPos, float yPos) :
    Component(),
    _xPos(xPos),
    _yPos(yPos) {

}

TransformComponent::~TransformComponent() = default;