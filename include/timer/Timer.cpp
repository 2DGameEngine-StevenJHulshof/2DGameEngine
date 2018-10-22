#include "Timer.h"
#include "SDL.h"
#include "UserLog.h"

Timer::Timer() :
    _started(false),
    _startTicks() {

}

Timer::~Timer() = default;

void Timer::Start() {

    _started = true;

    if(!_started) {
        _startTicks = Clock_t::now();
    }
}

void Timer::Reset() {

    _startTicks = Clock_t::now();
}

std::uint32_t Timer::Read_us() {

    std::uint32_t time = 0;

    if(_started) {
        time = static_cast<uint32_t>(
                std::chrono::duration_cast<std::chrono::microseconds>(Clock_t::now() - _startTicks).count());
       // LOG_INFO("%u", time);
    }

    return time;
}