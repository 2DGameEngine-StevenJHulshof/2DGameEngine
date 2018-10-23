#pragma once

#include "Component.h"

class PhysicsComponent : public Component {

private:
    float _velocity;
    float _mass;

public:
    PhysicsComponent(float velocity, float mass);
    ~PhysicsComponent();

    void Update() override;

    void SetVelocity(float velocity) { _velocity = velocity; }
    void SetMass(float mass) { _mass = mass; }

    float GetVelocity() { return _velocity; }
    float GetMass() { return _mass; }
};