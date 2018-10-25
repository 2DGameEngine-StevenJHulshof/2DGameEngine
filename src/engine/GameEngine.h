#pragma once

#include <cstdint>
#include "SDL.h"
#include "SDL_FontCache.h"

class GameEngine {

private:

    bool _isRunning;
    SDL_Window *_window;
    SDL_Renderer *_renderer;
    FC_Font *_font;

    void CheckSDLVersions();

public:

    bool IsRunning();

    GameEngine(const char *title, std::uint32_t windowPosX, std::uint32_t windowPosY, std::uint16_t windowWidth,
            std::uint16_t windowHeight, bool fullScreen);

    ~GameEngine();

    bool Config(const char *title, std::uint32_t windowPosX, std::uint32_t windowPosY, std::uint16_t windowWidth,
                std::uint16_t windowHeight, bool fullScreen);

    void HandleEvents();
    void Update();
    void Render();
    void Clean();

    SDL_Renderer *GetRenderer() { return _renderer; }
};