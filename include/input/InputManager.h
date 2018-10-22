#pragma once
#include "SDL.h"

class InputManager {

private:
    static InputManager *_instance;
    InputManager();

    bool _keyUp;
    bool _keyDown;
    bool _keyLeft;
    bool _keyRight;
    bool _keyQ;

public:
    ~InputManager();

    static InputManager *Instance() {
        if(!_instance) {
            _instance = new InputManager;
        }
        return _instance;
    }

    void PollKeyboardInput();
    void ResetInput();

    bool GetKeyUp() { return _keyUp; };
    bool GetKeyDown() { return _keyDown; };
    bool GetKeyLeft() { return _keyLeft; };
    bool GetKeyRight() { return _keyRight; };
    bool GetKeyQ() { return _keyQ; };
};

#define input_manager InputManager::Instance()
#define input_manager_reset_input input_manager->ResetInput()
#define input_manager_poll_key_input input_manager->PollKeyboardInput()
