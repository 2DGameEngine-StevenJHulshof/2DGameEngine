#include "FrameManager.h"
#include "UserLog.h"
#include <math.h>

FrameManager *FrameManager::_instance = nullptr;

FrameManager::FrameManager() :
    _stepTimer(nullptr),
    _frameTimeStep(0.0f) {

//    LOG_ALLOC(this, __PRETTY_FUNCTION__);
    _stepTimer = new Timer;
};

FrameManager::~FrameManager() {

//    LOG_DEALLOC(this, __PRETTY_FUNCTION__);
    delete _stepTimer;
}

bool FrameManager::Config(float refreshRate) {
    _frameTimeStep = 1.0f / refreshRate;
}

void FrameManager::Start() {
    _stepTimer->Start();
}

void FrameManager::Reset() {
    _stepTimer->Reset();
}

void FrameManager::SynchronizeFrameTime() {

    while(_stepTimer->Read_ms() < static_cast<std::uint32_t>(std::round(_frameTimeStep * 1000.0f)));
}