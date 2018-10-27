#pragma once

#include "Entity.h"
#include "UserLog.h"

class Component {

private:

    Entity *_parent;

public:

    Component();
    ~Component();

    Entity *GetParent() { return _parent; };
    void SetParent(Entity *entity) { _parent = entity; };

    virtual void Config();
    virtual void Update();
    virtual void Render();
};

