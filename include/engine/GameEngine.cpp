#include <climits>

#include "GameEngine.h"
#include "UserLog.h"
#include "Texture.h"
#include "TextureManager.h"
#include "InputManager.h"
#include "FrameManager.h"
#include "Entity.h"
#include "TransformComponent.h"
#include "RendererComponent.h"
#include "ControllerComponent.h"
#include "PhysicsComponent.h"

Entity player;
TransformComponent transformComponent(200.0f, 200.0f);
RendererComponent rendererComponent(TEXTURE_DEFAULT);
PhysicsComponent physicsComponent(0.1f, 60.0f);
ControllerComponent controllerComponent;

bool GameEngine::IsRunning() {

    return _isRunning;
}

GameEngine::GameEngine(const char *title, std::uint32_t windowPosX, std::uint32_t windowPosY, std::uint16_t windowWidth,
           std::uint16_t windowHeight, bool fullScreen) :
    _isRunning(true),
    _window(nullptr),
    _renderer(nullptr) {

//    LOG_ALLOC(this, __PRETTY_FUNCTION__);

    if(!Config(title, windowPosX, windowPosY, windowWidth, windowHeight, fullScreen)) {
        _isRunning = false;
    }
}

GameEngine::~GameEngine() {

//    LOG_DEALLOC(this, __PRETTY_FUNCTION__);
    Clean();
}

bool GameEngine::Config(const char *title, std::uint32_t windowPosX, std::uint32_t windowPosY, std::uint16_t windowWidth,
                  std::uint16_t windowHeight, bool fullScreen) {

    LOG_INFO("Starting game engine");

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
    texture_manager->Config(_renderer);

    player.AddComponent(&transformComponent);
    player.AddComponent(&rendererComponent);
    player.AddComponent(&physicsComponent);
    player.AddComponent(&controllerComponent);

    return true;
}

void GameEngine::HandleEvents() {

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
    input_manager->ResetInput();
    input_manager->PollKeyboardInput();
}

void GameEngine::Update() {
    /** - Update assets here. */
    player.Update();
}

void GameEngine::Render() {

    SDL_RenderClear(_renderer);
    /* - Begin of user rendering. */
    player.Render();
    /* - End of user rendering. */
    SDL_RenderPresent(_renderer);
}

void GameEngine::Clean() {

    LOG_INFO("Closing game engine and destroying all resources");
    delete texture_manager;
    delete input_manager;

    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    SDL_Quit();
}


