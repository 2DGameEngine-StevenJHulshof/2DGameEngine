#include "Entity.h"
#include "Component.h"

Entity::Entity() :
    _components(0) {

}

Entity::~Entity() {
    Clean();
}

void Entity::Config() {
    for(auto &component : _components) {
        component->Config();
    }
}

void Entity::AddComponent(Component *component) {

    _components.push_back(component);
    component->parent = this;
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

void Entity::Clean() {
//    for(auto &component : _components) {
//        delete component;
//    }
}