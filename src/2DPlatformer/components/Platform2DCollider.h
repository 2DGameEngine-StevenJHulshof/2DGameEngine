#pragma once

#include "Collider.h"

class Platform2DCollider : public Collider {
private:
public:
    explicit Platform2DCollider(std::string tag);
    ~Platform2DCollider();

    void Config() override;
};