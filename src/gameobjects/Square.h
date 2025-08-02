//
// Created by Filip on 30.07.2025.
//

#ifndef SQUARE_H
#define SQUARE_H
#pragma once
#include "../core/GameObject.h"
#include "../core/PhysicsBody.h"


class Square : public GameObject {
public:
    PhysicsBody body;
    SquareType type = SquareType::UNKNOWN;

    Square(float x, float y, float w, float h);

    void update(float deltaTime, const std::vector<GameObject *> &staticObjects) override;

    void render(SDL_Renderer *renderer) override;
};


#endif //SQUARE_H
