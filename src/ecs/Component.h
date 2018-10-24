#pragma once

#include "Entity.h"

class Component {

private:

    Entity *_parent;

public:

    Component();
    ~Component();

    Entity *GetParent() { return _parent; };
    void SetParent(Entity *entity) { _parent = entity; };

    virtual void Update();
    virtual void Render();
};