#include "SDL.h"
#include "UserLog.h"

int main(int argc, char* argv[])
{
    LOG_INFO("Starting game application...");

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        LOG_CRITICAL("SDL Init failed: %s", SDL_GetError());
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_SCREEN_WIDTH,
            WINDOW_SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if(window == nullptr) {
        LOG_CRITICAL("SDL Window could not be created: %s", SDL_GetError());
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

    SDL_RenderClear(renderer);

    SDL_RenderPresent(renderer);

    SDL_Delay(3000);

    SDL_Quit();

    return 0;
}