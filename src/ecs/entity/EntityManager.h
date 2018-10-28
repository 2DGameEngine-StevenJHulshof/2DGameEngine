#pragma once

#include "Entity.h"
#include <map>

class EntityManager {

private:
    EntityManager();
    static EntityManager *_instance;
    std::map<std::uint32_t, Entity*> _entities;

    void Clean();

public:
    ~EntityManager();
    static EntityManager *Instance() {
        if(!_instance) {
            _instance = new EntityManager;
        }
        return _instance;
    }

    Entity *New();
    void Update();
    void Render();
};

#define entity_manager EntityManager::Instance()

extern Entity *new_entity();