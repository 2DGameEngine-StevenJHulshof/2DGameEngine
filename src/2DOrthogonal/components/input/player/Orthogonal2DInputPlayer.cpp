#include "Orthogonal2DInputPlayer.h"
#include "InputManager.h"
#include "ComponentManager.h"

namespace Orthogonal2D {

    InputPlayer::InputPlayer() :
            Orthogonal2D::Input() {

    }

    InputPlayer::~InputPlayer() = default;

    void InputPlayer::Config() {

        physics = component_manager->AddDependency<Orthogonal2D::Physics>(parent);

        Base::Input::Config();
    }

    void InputPlayer::Update() {

        if(input_manager->GetKeyW()) {
            physics->velocity.y = -100.0f;
        }
        if(input_manager->GetKeyA()) {
            physics->velocity.x = -100.0f;
        }
        if(input_manager->GetKeyS()) {
            physics->velocity.y = 100.0f;
        }
        if(input_manager->GetKeyD()) {
            physics->velocity.x = 100.0f;
        }

        Orthogonal2D::Input::Update();
    }
}