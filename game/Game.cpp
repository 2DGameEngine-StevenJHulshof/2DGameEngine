#include "Game.h"

Entity *player;

Entity *CreatePlayer(Vector2D position, Vector2D scale, Texture_t textureID) {
    Entity *entity = new_entity();
    add_component<Orthogonal2D::Transform>(entity, position, scale);
    add_component<Orthogonal2D::Renderer>(entity, textureID);
    add_component<Orthogonal2D::Physics>(entity);
    add_component<Orthogonal2D::InputPlayer>(entity);
    entity->Config();

    return entity;
}

Entity *CreateTileOverlayWater(Vector2D position, Vector2D scale, Texture_t textureID) {
    Entity *entity = new_entity();
    add_component<Orthogonal2D::Transform>(entity, position, scale);
    add_component<Orthogonal2D::Renderer>(entity, textureID);
    entity->Config();

    return entity;
}

Entity *CreateTileGrass(Vector2D position, Vector2D scale) {

    Entity *entity = new_entity();
    add_component<Orthogonal2D::Transform>(entity, position, scale);
    add_component<Orthogonal2D::Renderer>(entity, TEXTURE_TILE_GRASS_0);
    entity->Config();

    return entity;
}

namespace game {

    void LoadFiles() {
        add_texture_path("default.png");
        add_texture_path("tile-grass-0.png");
        add_texture_path("tile-overlay-water-0.png");
        add_texture_path("tile-overlay-water-17.png");
        add_texture_path("unit-default-0.png");
    }

    void CreateObjects() {

        for(std::size_t y = 0; y < 9; y++) {
           for(std::size_t x = 0; x < 16; x++) {

               CreateTileGrass(Vector2D(64.0f * x, 64.0f * y), Vector2D(4.0f, 4.0f));
           }
        }

        for(std::size_t y = 0; y < 9; y++) {
            CreateTileOverlayWater(Vector2D(64.0f * 10.0f, 64.0f * y), Vector2D(4.0f, 4.0f), TEXTURE_TILE_OVERLAY_WATER_17);
        }

        player = CreatePlayer(Vector2D(64.0f, 64.0f), Vector2D(4.0f, 4.0f), TEXTURE_UNIT_DEFAULT_0);
    }

    void Update() {

    }
}