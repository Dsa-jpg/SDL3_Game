//
// Created by Filip on 29.07.2025.
//

#include "Player.h"
#include <SDL3/SDL.h>

Player::Player(int x, int y, int w, int h) : GameObject(x, y, w, h) {}

void Player::update(float deltaTime) {

}

void Player::render(SDL_Renderer* renderer) {
    if (texture) {
        SDL_RenderTexture(renderer,texture,nullptr,&transform);
    }
}