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
    bool _keyW;
    bool _keyE;
    bool _keyR;
    bool _keyT;
    bool _keyY;
    bool _keyU;
    bool _keyI;
    bool _keyO;
    bool _keyP;
    bool _keyA;
    bool _keyS;
    bool _keyD;
    bool _keyF;
    bool _keyG;
    bool _keyH;
    bool _keyJ;
    bool _keyK;
    bool _keyL;
    bool _keyZ;
    bool _keyX;
    bool _keyC;
    bool _keyV;
    bool _keyB;
    bool _keyN;
    bool _keyM;

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
    bool GetKeyW() { return _keyW; };
    bool GetKeyE() { return _keyE; };
    bool GetKeyR() { return _keyR; };
    bool GetKeyT() { return _keyT; };
    bool GetKeyY() { return _keyY; };
    bool GetKeyU() { return _keyU; };
    bool GetKeyI() { return _keyI; };
    bool GetKeyO() { return _keyO; };
    bool GetKeyP() { return _keyP; };
    bool GetKeyA() { return _keyA; };
    bool GetKeyS() { return _keyS; };
    bool GetKeyD() { return _keyD; };
    bool GetKeyF() { return _keyF; };
    bool GetKeyG() { return _keyG; };
    bool GetKeyH() { return _keyH; };
    bool GetKeyJ() { return _keyJ; };
    bool GetKeyK() { return _keyK; };
    bool GetKeyL() { return _keyL; };
    bool GetKeyZ() { return _keyZ; };
    bool GetKeyX() { return _keyX; };
    bool GetKeyC() { return _keyC; };
    bool GetKeyV() { return _keyV; };
    bool GetKeyB() { return _keyB; };
    bool GetKeyN() { return _keyN; };
    bool GetKeyM() { return _keyM; };
};

#define input_manager InputManager::Instance()
