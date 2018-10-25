#pragma once

#include <cstdint>
#include <chrono>

class Timer {
private:
    bool _started;
    bool _stopped;

    std::uint32_t _startTicks;
    std::uint32_t _stopTicks;

public:
    Timer();
    ~Timer();

    void Start();
    void Stop();
    void Reset();
    std::uint32_t Read_ms();
};