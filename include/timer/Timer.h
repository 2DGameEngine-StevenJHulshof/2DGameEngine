#pragma once

#include <cstdint>

class Timer {
private:
    bool _started;
    bool _paused;

    std::uint32_t _startTicks;
    std::uint32_t _pausedTicks;
public:
    Timer();
    ~Timer();

    void Start();
    void Stop();
    void Reset();
    std::uint32_t Read_ms();
};