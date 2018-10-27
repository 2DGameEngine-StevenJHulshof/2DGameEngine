#include "ComponentManager.h"

ComponentManager *ComponentManager::_instance = nullptr;

ComponentManager::ComponentManager() = default;

ComponentManager::~ComponentManager() {
    Clean();
}

void ComponentManager::Clean() {
    _components.clear();
}