#pragma once

#include <cstdint>
#include <chrono>

typedef std::chrono::high_resolution_clock Clock_t;
typedef Clock_t::time_point TimePoint_t;

class Timer {
private:
    bool _started;

    TimePoint_t _startTicks;
public:
    Timer();
    ~Timer();

    void Start();
    void Reset();
    std::uint32_t Read_us();
    std::uint32_t Read_ms();
};