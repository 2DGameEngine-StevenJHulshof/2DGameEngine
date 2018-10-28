#include "Game.h"

namespace game {

    void LoadFiles() {

        add_texture_path("default.png");
        add_texture_path("floor.png");
    }

    void CreateObjects() {
        /** - Create player onbject. */
        Entity *player = new_entity();
        add_component<Platform2DTransform>(player);
        add_component<Platform2DRenderer>(player);
        add_component<Platform2DPhysics>(player);
        add_component<Platform2DInput>(player);
        player->Config();

        /** - Create floor object. */
        Entity *floor = new_entity();
        add_component<Platform2DTransform>(floor);
        add_component<Platform2DRenderer>(floor);
        floor->GetComponent<Platform2DTransform>()->position = Vector2D(0.0f, 300.0f);
        floor->GetComponent<Platform2DRenderer>()->textureID = TEXTURE_FLOOR;
    }

    void Update() {

    }
}