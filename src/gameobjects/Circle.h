//
// Created by Filip on 02.08.2025.
//

#ifndef CIRCLE_H
#define CIRCLE_H
#pragma once
#include "Floor.h"
#include "../core/GameObject.h"
#include "../core/PhysicsBody.h"


class Circle : public GameObject {
public:
    float radius;
    int numSegments;
    PhysicsBody body;
    Floor *floor = nullptr;

    Circle(float x, float y, float radius, int numSegments, Floor *floor);

    void update(float deltaTime) override;

    void render(SDL_Renderer *renderer) override;
};


#endif //CIRCLE_H
