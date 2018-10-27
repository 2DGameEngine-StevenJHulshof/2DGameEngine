#pragma once

#include "Component.h"
#include <memory>
#include <map>

class ComponentManager {

private:
    ComponentManager();
    static ComponentManager *_instance;
    std::map<std::uint32_t, Component*> _components;

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

        T *component = nullptr;

        if (entity->GetComponent<T>() == nullptr) {
            component = new T;
            _components[component->ID] = component;
            entity->AddComponent(component);
        } else {
            LOG_WARNING("Entity already contains component of this type");
        }

        return component;
    }

    template <class T>
    T *AddDependency(Entity *entity) {

        T *component = nullptr;

        if (entity->GetComponent<T>() == nullptr) {
            LOG_WARNING("Invalid reference to component -> Creating default");
            component = New<T>(entity);
            entity->Config();
        } else {
            component = entity->GetComponent<T>();
        }

        return component;
    }
};

#define component_manager ComponentManager::Instance()