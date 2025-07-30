//
// Created by Filip on 30.07.2025.
//

#include "Square.h"

#include "Floor.h"

Square::Square(const float x, const float y, const float w, const float h, Floor* floor): GameObject(x, y, w, h), floor(floor) {
}

void Square::render(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &transform);
}

void Square::update(const float deltaTime) {
    body.update(this,deltaTime,floor);
}

