#include "Player.h"
#include "InputManager.h"
#include "FrameManager.h"
#include "TextureManager.h"

Player::Player(Texture_t textureID, float x, float y, float velocity) :
    _textureID(textureID),
    _x(x),
    _y(y),
    _velocity(velocity){

}

Player::~Player() = default;

void Player::Input() {

    if(input_manager->GetKeyD()) _x += _velocity * frame_manager->GetDeltaTime();
    if(input_manager->GetKeyA()) _x -= _velocity * frame_manager->GetDeltaTime();
    if(input_manager->GetKeyW()) _y -= _velocity * frame_manager->GetDeltaTime();
    if(input_manager->GetKeyS()) _y += _velocity * frame_manager->GetDeltaTime();
}

void Player::Update() {
    Input();
}

void Player::Render() {
    texture_manager->GetTexture(_textureID)->Render(_x, _y);
}