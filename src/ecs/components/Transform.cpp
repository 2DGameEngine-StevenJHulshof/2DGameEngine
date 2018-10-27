#include "Transform.h"
#include "UserLog.h"

Transform::Transform(Vector2D position, Vector2D scale) :
    Component(),
    position(position * scale),
    dimension(Vector2D()),
    scale(scale) {

}

Transform::~Transform() = default;

void Transform::Update() {

}