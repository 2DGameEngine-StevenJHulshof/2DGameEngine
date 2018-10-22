#pragma once

#include <cstdint>
#include "SDL.h"

class Game {

private:

    bool _isRunning;
    SDL_Window *_window;
    SDL_Renderer *_renderer;

public:

    bool IsRunning();

    Game(const char *title, std::uint32_t windowPosX, std::uint32_t windowPosY, std::uint16_t windowWidth,
            std::uint16_t windowHeight, bool fullScreen);

    ~Game();

    bool Config(const char *title, std::uint32_t windowPosX, std::uint32_t windowPosY, std::uint16_t windowWidth,
                std::uint16_t windowHeight, bool fullScreen);

    void HandleEvents();
    void Update();
    void Render();
    void Clean();
};