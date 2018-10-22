#include "FrameManager.h"
#include "UserLog.h"

FrameManager *FrameManager::_instance = nullptr;

FrameManager::FrameManager() :
    _stepTimer(nullptr) {

//    LOG_ALLOC(this, __PRETTY_FUNCTION__);
    _stepTimer = new Timer;
};

FrameManager::~FrameManager() {

//    LOG_DEALLOC(this, __PRETTY_FUNCTION__);
    delete _stepTimer;
}

void FrameManager::Start() {
    _stepTimer->Start();
}

void FrameManager::Reset() {
    _stepTimer->Reset();
}

float FrameManager::GetDeltaTime() {

    float deltaTime = _stepTimer->Read_us() / 1000.0f;

    if(deltaTime == 0.0f) {
        deltaTime = 1.0f;
    }
    return deltaTime;
}