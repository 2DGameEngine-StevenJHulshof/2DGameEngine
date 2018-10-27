#pragma once

#include "Entity.h"
#include "UserLog.h"
#include <cstdint>

class Component {

private:
    static std::uint32_t _IDCounter;

public:
    Entity *parent;
    std::uint32_t ID;

    Component();
    ~Component();

    virtual void Config();
    virtual void Update();
    virtual void Render();
};

