#include "Game.h"
#include "UserLog.h"

bool Game::IsRunning() {

    return _isRunning;
}

Game::Game(const char *title, std::uint32_t windowPosX, std::uint32_t windowPosY, std::uint16_t windowWidth,
           std::uint16_t windowHeight, bool fullScreen) :
    _isRunning(true),
    _window(nullptr),
    _renderer(nullptr) {

    LOG_ALLOC(this, __PRETTY_FUNCTION__);

    if(!Config(title, windowPosX, windowPosY, windowWidth, windowHeight, fullScreen)) {
        _isRunning = false;
    }
}

Game::~Game() {

    LOG_DEALLOC(this, __PRETTY_FUNCTION__);
    Clean();
}

bool Game::Config(const char *title, std::uint32_t windowPosX, std::uint32_t windowPosY, std::uint16_t windowWidth,
                  std::uint16_t windowHeight, bool fullScreen) {

    LOG_INFO("Starting game application...");

    std::uint32_t flags = 0;
    if(fullScreen) flags |= SDL_WINDOW_FULLSCREEN;

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        LOG_CRITICAL("SDL Init failed: %s", SDL_GetError());
        return false;
    }

    _window = SDL_CreateWindow(title, windowPosX, windowPosY, windowWidth, windowHeight, flags);
    if(_window == nullptr) {
        LOG_CRITICAL("SDL Window could not be created: %s", SDL_GetError());
        return false;
    }

    _renderer = SDL_CreateRenderer(_window, -1, 0);
    if(_renderer == nullptr) {
        LOG_CRITICAL("SDL Renderer could not be created: %s", SDL_GetError());
        return false;
    }

    return true;
}

void Game::HandleEvents() {

    SDL_Event event;
    SDL_PollEvent(&event);

    switch(event.type) {
        case SDL_QUIT:
            _isRunning = false;
            break;
        default:
            break;
    }
}

void Game::Update() {

}

void Game::Render() {

    SDL_RenderClear(_renderer);
    /* - Begin of user rendering. */

    /* - End of user rendering. */
    SDL_RenderPresent(_renderer);
}

void Game::Clean() {

    LOG_INFO("Closing game application...");
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    SDL_Quit();
}



