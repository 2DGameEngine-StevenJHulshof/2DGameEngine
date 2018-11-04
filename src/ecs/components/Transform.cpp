#include "Transform.h"
#include "UserLog.h"

namespace Base {

    Transform::Transform(Vector2D position, Vector2D scale) :
            Component(),
            position(position),
            dimension(Vector2D()),
            scale(scale) {

    }

    Transform::~Transform() = default;

    void Transform::Update() {

    }
}