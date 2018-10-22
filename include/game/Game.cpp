#include "Game.h"
#include "UserLog.h"
#include "Texture.h"
#include "TextureManager.h"
#include "InputManager.h"

bool Game::IsRunning() {

    return _isRunning;
}

Game::Game(const char *title, std::uint32_t windowPosX, std::uint32_t windowPosY, std::uint16_t windowWidth,
           std::uint16_t windowHeight, bool fullScreen) :
    _isRunning(true),
    _window(nullptr),
    _renderer(nullptr) {

//    LOG_ALLOC(this, __PRETTY_FUNCTION__);

    if(!Config(title, windowPosX, windowPosY, windowWidth, windowHeight, fullScreen)) {
        _isRunning = false;
    }
}

Game::~Game() {

//    LOG_DEALLOC(this, __PRETTY_FUNCTION__);
    Clean();
}

bool Game::Config(const char *title, std::uint32_t windowPosX, std::uint32_t windowPosY, std::uint16_t windowWidth,
                  std::uint16_t windowHeight, bool fullScreen) {

    LOG_INFO("Starting game application");

    std::uint32_t flags = 0;
    if(fullScreen) flags |= SDL_WINDOW_FULLSCREEN;

    LOG_INFO("Initializing SDL");
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        LOG_CRITICAL("SDL Init failed: %s", SDL_GetError());
        return false;
    }

    LOG_INFO("Creating SDL window");
    _window = SDL_CreateWindow(title, windowPosX, windowPosY, windowWidth, windowHeight, flags);
    if(_window == nullptr) {
        LOG_CRITICAL("SDL Window could not be created: %s", SDL_GetError());
        return false;
    }

    LOG_INFO("Creating SDL renderer");
    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
    if(_renderer == nullptr) {
        LOG_CRITICAL("SDL Renderer could not be created: %s", SDL_GetError());
        return false;
    }

    LOG_INFO("Configuring texture manager and loading textures");
    texture_manager_config(_renderer);

    return true;
}

void Game::HandleEvents() {

    SDL_Event event;
    while (SDL_PollEvent(&event)) {

        switch (event.type) {
            case SDL_QUIT:
                _isRunning = false;
                break;
            default:
                break;
        }
    }
    input_manager_reset_input;
    input_manager_poll_key_input;
}

/** - TODO: remove */
int x = 0;
int y = 0;

void Game::Update() {
    /** - TODO: remove */
    if(input_manager->GetKeyRight()) x++;
    if(input_manager->GetKeyLeft()) x--;
    if(input_manager->GetKeyUp()) y--;
    if(input_manager->GetKeyDown()) y++;
}

void Game::Render() {

    SDL_RenderClear(_renderer);
    /* - Begin of user rendering. */
    /** - TODO: remove */
    texture_manager_get(TEXTURE_DEFAULT)->Render(x, y);
    /* - End of user rendering. */
    SDL_RenderPresent(_renderer);
}

void Game::Clean() {

    LOG_INFO("Closing game application and destroying all resources");
    delete texture_manager;
    delete input_manager;

    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    SDL_Quit();
}



