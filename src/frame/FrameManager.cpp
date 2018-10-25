#include "FrameManager.h"
#include "UserLog.h"
#include <math.h>

FrameManager *FrameManager::_instance = nullptr;

FrameManager::FrameManager() :
    _stepTimer(nullptr),
    _cappedFrameTimeStep(0.0f),
    _deltaTime(0.0f) {

//    LOG_ALLOC(this, __PRETTY_FUNCTION__);
    _stepTimer = new Timer;
};

FrameManager::~FrameManager() {

//    LOG_DEALLOC(this, __PRETTY_FUNCTION__);
    delete _stepTimer;
}

bool FrameManager::Config(float refreshRateCap) {

    if(refreshRateCap == 0.0f) {
        LOG_CRITICAL("Refresh rate cap must be higher than 0");
        return false;
    }

    _cappedFrameTimeStep = 1.0f / refreshRateCap;

    return true;
}

void FrameManager::Start() {
    _stepTimer->Start();
}

void FrameManager::Reset() {
    _stepTimer->Reset();
}

void FrameManager::SynchronizeFrameTime() {

    while(_stepTimer->Read_ms() < static_cast<std::uint32_t>(_cappedFrameTimeStep * 1000.0f));
        _deltaTime = static_cast<float>(_stepTimer->Read_ms()) / 1000.0f;
}