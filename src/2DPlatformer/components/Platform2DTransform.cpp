#include "Platform2DTransform.h"

Platform2DTransform::Platform2DTransform(Vector2D position) :
    Transform(position){

}

Platform2DTransform::~Platform2DTransform() = default;

void Platform2DTransform::Update() {

    if(position.y < 0.0f) position.y = WINDOW_SCREEN_HEIGHT;
    if(position.y > WINDOW_SCREEN_HEIGHT) position.y = 0.0f;
    if(position.x < 0.0f) position.x = WINDOW_SCREEN_WIDTH;
    if(position.x > WINDOW_SCREEN_WIDTH) position.x = 0.0f;

    Transform::Update();
}