#pragma once

#include "Entity.h"
#include "UserLog.h"

class Component {

private:

public:
    Entity *parent;

    Component();
    ~Component();

    virtual void Config();
    virtual void Update();
    virtual void Render();
};

