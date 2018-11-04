#pragma once

#include "Component.h"
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

    template <class T, class... TArgs>
    T *New(Entity *entity, TArgs&&... args) {

        T *component = nullptr;

        if (entity->GetComponent<T>() == nullptr) {
            component = new T(std::forward<TArgs>(args)...);
            _components[component->ID] = component;
            entity->AddComponent(component);
        } else {
            LOG_WARNING("Entity already contains component of this type");
        }

        return component;
    }

    template <class T, class... TArgs>
    T *AddDependency(Entity *entity, TArgs&&... args) {

        T *component = nullptr;

        if (entity->GetComponent<T>() == nullptr) {
            LOG_WARNING("Invalid reference to component -> Creating default");
            component = New<T>(entity, std::forward<TArgs>(args)...);
            entity->Config();
        } else {
            component = entity->GetComponent<T>();
        }

        return component;
    }
};

#define component_manager ComponentManager::Instance()

template <class T, class... TArgs>
extern T *add_component(Entity *parent, TArgs&&... args) {
    component_manager->New<T>(parent, std::forward<TArgs>(args)...);
}