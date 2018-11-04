#pragma once

#include "Physics.h"
#include "Platform2DCollider.h"

class Platform2DDynamicCollider : public Platform2DCollider {
private:
    bool _isColliding;
public:
    Base::Physics *physics;

    explicit Platform2DDynamicCollider(std::string tag);
    ~Platform2DDynamicCollider();

    void Config() override;
    void Update() override;
};