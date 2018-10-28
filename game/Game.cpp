#include "Game.h"

Entity *player;
Entity *floor;

void CreateFloor(Vector2D pos) {
    /** - Create floor object. */
    floor = new_entity();
    add_component<Platform2DTransform>(floor, pos);
    add_component<Platform2DRenderer>(floor, TEXTURE_FLOOR);
    add_component<Collider>(floor, "floor");
    floor->Config();
}

namespace game {

    void LoadFiles() {

        add_texture_path("default.png");
        add_texture_path("floor.png");
    }

    void CreateObjects() {
        /** - Create player onbject. */
        player = new_entity();
        add_component<Platform2DTransform>(player);
        add_component<Platform2DRenderer>(player);
        add_component<Platform2DPhysics>(player, 10.0f);
        add_component<Platform2DInput>(player);
        add_component<Platform2DDynamicCollider>(player, "player");
        player->Config();

        for(int i = 0; i < 8; i++) {
            CreateFloor(Vector2D(static_cast<float>(i * 64), 500.0f));
        }
    }

    void Update() {

    }
}