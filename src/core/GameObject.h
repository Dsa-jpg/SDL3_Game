//
// Created by Filip on 29.07.2025.
//

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#pragma once
#include <vector>

#include "Common.h"
#include "Transform.h"
#include "SDL3/SDL.h"


class GameObject {
public:
    Transform transform{};
    SDL_Texture *texture = nullptr;
    ShapeType shape = ShapeType::UNKNOWN;

    GameObject(float x, float y, float w, float h);

    virtual void update(float deltaTime, const std::vector<GameObject *> &staticObjects) = 0;

    virtual void render(SDL_Renderer *renderer) = 0;

    virtual ~GameObject() = default;
};


#endif //GAMEOBJECT_H
