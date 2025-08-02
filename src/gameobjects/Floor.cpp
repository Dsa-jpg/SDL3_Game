//
// Created by Filip on 30.07.2025.
//

#include "Floor.h"

Floor::Floor(float x, float y, float w, float h) : GameObject(x, y, w, h) {
    shape = ShapeType::POLYGON;
}

void Floor::render(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 5, 10, 120, 255);
    const SDL_FRect rect{
        transform.position.x,
        transform.position.y,
        transform.scale.x,
        transform.scale.y
    };
    SDL_RenderFillRect(renderer, &rect);
}


