#include <memory>

#include "app_config.h"
#include "GameEngine.h"
#include "UserLog.h"
#include "FrameManager.h"

int main(int argc, char* argv[])
{
    std::shared_ptr<GameEngine> gameEngine = std::make_shared<GameEngine>("TestGame", SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED, WINDOW_SCREEN_WIDTH, WINDOW_SCREEN_HEIGHT, false);

    if(!frame_manager->Config(static_cast<float>(WINDOW_REFRESH_RATE_CAP))) {
        return 0;
    }

    LOG_INFO("Entering game loop");
    frame_manager->Start();
    while(gameEngine->IsRunning()) {
        frame_manager->Reset();
        gameEngine->HandleEvents();
        gameEngine->Update();
        gameEngine->Render();
        frame_manager->SynchronizeFrameTime();
    }

    delete frame_manager;

    return 0;
}