#include "Component.h"

std::uint32_t Component::_IDCounter = 0;

Component::Component() :
    parent(nullptr),
    ID(0) {

    ID = _IDCounter;
    _IDCounter++;
}

Component::~Component() = default;

void Component::Config() {

}

void Component::Update() {

}

void Component::Render() {

}