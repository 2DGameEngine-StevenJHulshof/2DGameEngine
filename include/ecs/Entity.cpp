#include "Entity.h"
#include "Component.h"

Entity::Entity() :
    _components(0) {

}

Entity::~Entity() = default;

void Entity::AddComponent(Component *component) {

    _components.push_back(component);
    component->SetParent(this);
}

void Entity::Update() {
    for(auto &component : _components) {
        component->Update();
    }
}

void Entity::Render() {
    for(auto &component : _components) {
        component->Render();
    }
}