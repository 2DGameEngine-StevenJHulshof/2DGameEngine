#include "InputManager.h"
#include "UserLog.h"

InputManager *InputManager::_instance = nullptr;

InputManager::InputManager() :
    _keyUp(false),
    _keyDown(false),
    _keyLeft(false),
    _keyRight(false),
    _keyQ(false),
    _keyW(false),
    _keyE(false),
    _keyR(false),
    _keyT(false),
    _keyY(false),
    _keyU(false),
    _keyI(false),
    _keyO(false),
    _keyP(false),
    _keyA(false),
    _keyS(false),
    _keyD(false),
    _keyF(false),
    _keyG(false),
    _keyH(false),
    _keyJ(false),
    _keyK(false),
    _keyL(false),
    _keyZ(false),
    _keyX(false),
    _keyC(false),
    _keyV(false),
    _keyB(false),
    _keyN(false),
    _keyM(false) {

}

InputManager::~InputManager() = default;

void InputManager::PollKeyboardInput() {

    const std::uint8_t *state = SDL_GetKeyboardState(nullptr);
    if (state[SDL_SCANCODE_UP]) _keyUp = true;
    if (state[SDL_SCANCODE_DOWN]) _keyDown = true;
    if (state[SDL_SCANCODE_LEFT]) _keyLeft = true;
    if (state[SDL_SCANCODE_RIGHT]) _keyRight = true;
    if (state[SDL_SCANCODE_Q]) _keyQ = true;
    if (state[SDL_SCANCODE_W]) _keyW = true;
    if (state[SDL_SCANCODE_E]) _keyE = true;
    if (state[SDL_SCANCODE_R]) _keyR= true;
    if (state[SDL_SCANCODE_T]) _keyT = true;
    if (state[SDL_SCANCODE_Y]) _keyY = true;
    if (state[SDL_SCANCODE_U]) _keyU = true;
    if (state[SDL_SCANCODE_I]) _keyI = true;
    if (state[SDL_SCANCODE_O]) _keyO = true;
    if (state[SDL_SCANCODE_P]) _keyP = true;
    if (state[SDL_SCANCODE_A]) _keyA = true;
    if (state[SDL_SCANCODE_S]) _keyS = true;
    if (state[SDL_SCANCODE_D]) _keyD = true;
    if (state[SDL_SCANCODE_F]) _keyF = true;
    if (state[SDL_SCANCODE_G]) _keyG = true;
    if (state[SDL_SCANCODE_H]) _keyH = true;
    if (state[SDL_SCANCODE_J]) _keyJ = true;
    if (state[SDL_SCANCODE_K]) _keyK = true;
    if (state[SDL_SCANCODE_L]) _keyL = true;
    if (state[SDL_SCANCODE_Z]) _keyZ = true;
    if (state[SDL_SCANCODE_X]) _keyX = true;
    if (state[SDL_SCANCODE_C]) _keyC = true;
    if (state[SDL_SCANCODE_V]) _keyV = true;
    if (state[SDL_SCANCODE_B]) _keyB = true;
    if (state[SDL_SCANCODE_N]) _keyN = true;
    if (state[SDL_SCANCODE_M]) _keyM = true;
}

void InputManager::ResetInput() {

    if(_keyUp) _keyUp = false;
    if(_keyDown) _keyDown = false;
    if(_keyLeft) _keyLeft = false;
    if(_keyRight) _keyRight = false;
    if(_keyQ) _keyQ = false;
    if(_keyW) _keyW = false;
    if(_keyE) _keyE = false;
    if(_keyR) _keyR = false;
    if(_keyT) _keyT = false;
    if(_keyY) _keyY = false;
    if(_keyU) _keyU = false;
    if(_keyI) _keyI = false;
    if(_keyO) _keyO = false;
    if(_keyP) _keyP = false;
    if(_keyA) _keyA = false;
    if(_keyS) _keyS = false;
    if(_keyD) _keyD = false;
    if(_keyF) _keyF = false;
    if(_keyG) _keyG = false;
    if(_keyH) _keyH = false;
    if(_keyJ) _keyJ = false;
    if(_keyK) _keyK = false;
    if(_keyL) _keyL = false;
    if(_keyZ) _keyZ = false;
    if(_keyX) _keyX = false;
    if(_keyC) _keyC = false;
    if(_keyV) _keyV = false;
    if(_keyB) _keyB = false;
    if(_keyN) _keyN = false;
    if(_keyM) _keyM = false;
}