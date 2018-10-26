#pragma once

#include <vector>
#include "app_config.h"

class Component;
class Entity {

private:

    std::vector<Component*> _components;

public:

    Entity();
    ~Entity();

    void AddComponent(Component *component);
    void Config();
    void Update();
    void Render();
    void Clean();

    template <class T>
    T* GetComponent() const;
};

template <class T>
T* Entity::GetComponent() const {

    for(auto &component : _components) {

        T* comp = dynamic_cast<T*>(component);

        if(comp != nullptr) {
            return comp;
        }
    }

    return nullptr;
}