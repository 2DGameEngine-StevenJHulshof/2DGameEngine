#include <math.h>

#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"

#include "GameEngine.h"
#include "UserLog.h"
#include "Texture.h"
#include "TextureManager.h"
#include "FontManager.h"
#include "InputManager.h"
#include "FrameManager.h"
#include "CollisionManager.h"
#include "ComponentManager.h"
#include "EntityManager.h"
#include "Entity.h"
#include "Platform2DTransform.h"
#include "Platform2DRenderer.h"
#include "Platform2DInput.h"
#include "Platform2DPhysics.h"

bool GameEngine::IsRunning() {

    return _isRunning;
}

GameEngine::GameEngine(const char *title, std::uint32_t windowPosX, std::uint32_t windowPosY, std::uint16_t windowWidth,
           std::uint16_t windowHeight, bool fullScreen) :
    _isRunning(true),
    _window(nullptr),
    _renderer(nullptr) {

    if(!Config(title, windowPosX, windowPosY, windowWidth, windowHeight, fullScreen)) {
        _isRunning = false;
    }
}

GameEngine::~GameEngine() {

    Clean();
}

bool GameEngine::Config(const char *title, std::uint32_t windowPosX, std::uint32_t windowPosY, std::uint16_t windowWidth,
                  std::uint16_t windowHeight, bool fullScreen) {

    LOG_INFO("Starting game engine");

    std::uint32_t flags = 0;
    if(fullScreen) flags |= SDL_WINDOW_FULLSCREEN;

    CheckSDLVersions();

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
    LOG_INFO("Configuring font manager and loading fonts");
    font_manager->Config(_renderer, 16, 255, 255, 255, 255);

    Entity *player = entity_manager->New();
    component_manager->New<Platform2DTransform>(player);
    component_manager->New<Platform2DRenderer>(player);
    component_manager->New<Platform2DPhysics>(player);
    component_manager->New<Platform2DInput>(player);
    player->Config();

    Entity *player2 = entity_manager->New();
    component_manager->New<Platform2DTransform>(player2);
    component_manager->New<Platform2DRenderer>(player2);
    component_manager->New<Platform2DPhysics>(player2);
    player2->GetComponent<Platform2DTransform>()->position = Vector2D(100.0f, 0.0f);
    player2->Config();

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
    entity_manager->Update();
}

void GameEngine::Render() {

    SDL_RenderClear(_renderer);
    /* - Begin of user rendering. */
    entity_manager->Render();

    font_manager->GetFont(FONT_FREE_SANS)->Render(0.0f, 0.0f, "FPS: ",
            static_cast<int>(1.0f / frame_manager->GetDeltaTime()));
    /* - End of user rendering. */
    SDL_RenderPresent(_renderer);
}

void GameEngine::Clean() {

    LOG_INFO("Closing game engine and destroying all resources");

    delete component_manager;
    delete entity_manager;
    delete collision_manager;
    delete font_manager;
    delete texture_manager;
    delete input_manager;

    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

void GameEngine::CheckSDLVersions() {

    SDL_version compiled;
    SDL_version linked;

    SDL_VERSION(&compiled);
    SDL_GetVersion(&linked);

    LOG_INFO("Checking SDL version: Compiled v%d.%d.%d - Linked v%d.%d.%d", compiled.major, compiled.minor, compiled.patch,
             linked.major, linked.minor, linked.patch);

    if(compiled.major != linked.major ||
       compiled.minor != linked.minor ||
       compiled.patch != linked.patch) {
        LOG_WARNING("SDL compiled version is not the same as linked version");
    }

    LOG_INFO("Using SDL Image v%d.%d.%d", SDL_IMAGE_MAJOR_VERSION, SDL_IMAGE_MINOR_VERSION, SDL_IMAGE_PATCHLEVEL);
    LOG_INFO("Using SDL TTF v%d.%d.%d", SDL_TTF_MAJOR_VERSION, SDL_TTF_MINOR_VERSION, SDL_TTF_PATCHLEVEL);
    LOG_INFO("Using SDL Mixer v%d.%d.%d", SDL_MIXER_MAJOR_VERSION, SDL_MIXER_MINOR_VERSION, SDL_MIXER_PATCHLEVEL);
}



