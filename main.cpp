#include "app_config.h"
#include "GameEngine.h"
#include "UserLog.h"
#include "FrameManager.h"

GameEngine *gameEngine = nullptr;

int main(int argc, char* argv[])
{
    gameEngine = new GameEngine("TestGame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_SCREEN_WIDTH,
            WINDOW_SCREEN_HEIGHT, false);

    LOG_INFO("Entering game loop");
    Timer frameCapTimer;
    frame_manager->Start();
    frameCapTimer.Start();
    while(gameEngine->IsRunning()) {
        frame_manager->Reset();
        frameCapTimer.Reset();
        gameEngine->HandleEvents();
        gameEngine->Update();
        gameEngine->Render();
        while(frameCapTimer.Read_us() < (1 / FRAME_RATE_CAP));
    }

    delete frame_manager;
    delete gameEngine;

    return 0;
}