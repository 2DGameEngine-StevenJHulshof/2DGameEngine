#include "Timer.h"
#include "SDL.h"
#include "UserLog.h"
#include <math.h>

Timer::Timer() :
    _started(false),
    _stopped(false),
    _startTicks(0),
    _stopTicks(0) {

}

Timer::~Timer() = default;

void Timer::Start() {

    _started = true;

    if(_stopped) {
        _stopped = false;
    } else {
        Reset();
    }
}

void Timer::Stop() {

    _stopped = true;
    _stopTicks = SDL_GetTicks();
}

void Timer::Reset() {

    _startTicks = SDL_GetTicks();
    _stopped = false;
}

std::uint32_t Timer::Read_ms() {

    if (_stopped) {
        return _stopTicks - _startTicks;
    } else if(_started) {
        return SDL_GetTicks() - _startTicks;
    }

    return 0;
}