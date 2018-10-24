#pragma once

#include "Timer.h"

class FrameManager {

private:

    FrameManager();
    static FrameManager *_instance;

    Timer *_stepTimer;

public:
    ~FrameManager();
    static FrameManager *Instance() {
        if(!_instance) {
            _instance = new FrameManager;
        }
        return _instance;
    }

    void Start();
    void Reset();
    float GetDeltaTime();
};

#define frame_manager FrameManager::Instance()