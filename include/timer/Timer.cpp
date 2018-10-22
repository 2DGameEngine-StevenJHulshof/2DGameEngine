#include "Timer.h"
#include "SDL.h"

Timer::Timer() :
    _started(false),
    _paused(false),
    _startTicks(0),
    _pausedTicks(0) {

}

Timer::~Timer() = default;

void Timer::Start() {

    if(_started && _paused ) {
        _paused = false;
        _startTicks = SDL_GetTicks() - _pausedTicks;
        _pausedTicks = 0;
    } else {
        _started = true;
        _paused = false;

        if(!_started) {
            _startTicks = SDL_GetTicks();
        }
    }
}

void Timer::Stop() {

    if(_started && !_paused ) {
        _paused = true;
        _pausedTicks = SDL_GetTicks() - _startTicks;
        _startTicks = 0;
    }
}

void Timer::Reset() {

    _startTicks = SDL_GetTicks();
    _pausedTicks = 0;
}

std::uint32_t Timer::Read_ms() {

    std::uint32_t time = 0;

    if(_started) {
        if(_paused) {
            time = _pausedTicks;
        } else {
            time = SDL_GetTicks() - _startTicks;
        }
    }

    return time;
}