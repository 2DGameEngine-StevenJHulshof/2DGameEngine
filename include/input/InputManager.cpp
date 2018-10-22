#include "InputManager.h"
#include "UserLog.h"

InputManager *InputManager::_instance = nullptr;

InputManager::InputManager() :
    _keyUp(false),
    _keyDown(false),
    _keyLeft(false),
    _keyRight(false),
    _keyQ(false) {

//    LOG_ALLOC(this, __PRETTY_FUNCTION__);
}

InputManager::~InputManager() = default;/*{

//    LOG_DEALLOC(this, __PRETTY_FUNCTION__);
}*/

void InputManager::PollKeyboardInput() {

    const std::uint8_t *state = SDL_GetKeyboardState(nullptr);
    if (state[SDL_SCANCODE_UP]) _keyUp = true;
    if (state[SDL_SCANCODE_DOWN]) _keyDown = true;
    if (state[SDL_SCANCODE_LEFT]) _keyLeft = true;
    if (state[SDL_SCANCODE_RIGHT]) _keyRight = true;
    if (state[SDL_SCANCODE_Q]) _keyQ = true;
}

void InputManager::ResetInput() {

    if(_keyUp) _keyUp = false;
    if(_keyDown) _keyDown = false;
    if(_keyLeft) _keyLeft = false;
    if(_keyRight) _keyRight = false;
    if(_keyQ) _keyQ = false;
}