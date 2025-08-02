//
// Created by Filip on 02.08.2025.
//

#ifndef CIRCLE_H
#define CIRCLE_H
#pragma once
#include "../core/GameObject.h"
#include "../core/PhysicsBody.h"


class Circle : public GameObject {
public:
    float radius;
    int numSegments;
    PhysicsBody body;


    Circle(float x, float y, float radius, int numSegments);

    void update(float deltaTime, const std::vector<GameObject *> &staticObjects) override;

    void render(SDL_Renderer *renderer) override;
};


#endif //CIRCLE_H
