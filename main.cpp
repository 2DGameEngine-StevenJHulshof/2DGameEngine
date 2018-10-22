#include "app_config.h"
#include "Game.h"
#include "UserLog.h"

Game *game = nullptr;

int main(int argc, char* argv[])
{
    game = new Game("TestGame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_SCREEN_WIDTH,
            WINDOW_SCREEN_HEIGHT, false);

    LOG_INFO("Entering game loop");
    while(game->IsRunning()) {
        game->HandleEvents();
        game->Update();
        game->Render();
    }

    delete game;

    return 0;
}