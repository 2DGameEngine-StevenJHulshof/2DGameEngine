#include "EntityManager.h"

EntityManager *EntityManager::_instance = nullptr;

EntityManager::EntityManager() = default;

EntityManager::~EntityManager() {
    Clean();
}

Entity *EntityManager::New() {

    Entity *entity = new Entity;
    _entities[entity->ID] = entity;
    return entity;
}

void EntityManager::Update() {
    for (auto const& entity : _entities)
    {
        entity.second->Update();
    }
}

void EntityManager::Render() {
    for (auto const& entity : _entities)
    {
        entity.second->Render();
    }
}

void EntityManager::Clean() {

    _entities.clear();
}