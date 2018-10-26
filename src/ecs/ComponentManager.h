#pragma once

#include "Component.h"
#include <memory>

class ComponentManager {

private:
    ComponentManager();
    static ComponentManager *_instance;
    std::vector<Component*> _components;

    void Clean();

public:
    ~ComponentManager();
    static ComponentManager *Instance() {
        if(!_instance) {
            _instance = new ComponentManager;
        }
        return _instance;
    }

    template <class T>
    T *New(Entity *entity) {
        T *component = new T;
        _components.push_back(component);
        entity->AddComponent(component);
        return component;
    }
};

#define component_manager ComponentManager::Instance()