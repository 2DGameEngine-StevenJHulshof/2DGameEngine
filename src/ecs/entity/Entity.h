#pragma once

#include <vector>
#include "app_config.h"

class Component;
class Entity {

private:
    static std::uint32_t _IDCounter;
    std::vector<Component*> _components;

public:
    std::uint32_t ID;

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