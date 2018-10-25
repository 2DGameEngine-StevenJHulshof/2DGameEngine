#pragma once

#include "Timer.h"

class FrameManager {

private:

    FrameManager();
    static FrameManager *_instance;

    Timer *_stepTimer;
    float _frameTimeStep;

public:
    ~FrameManager();
    static FrameManager *Instance() {
        if(!_instance) {
            _instance = new FrameManager;
        }
        return _instance;
    }

    bool Config(float refreshRate);
    void Start();
    void Reset();
    void SynchronizeFrameTime();

    float GetFrameTimeStep() { return _frameTimeStep; }
};

#define frame_manager FrameManager::Instance()