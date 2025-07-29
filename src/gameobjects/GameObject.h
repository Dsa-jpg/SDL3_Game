//
// Created by Filip on 29.07.2025.
//

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#pragma once
#include "SDL3/SDL.h"


class GameObject {

    public:
        SDL_FRect transform{};
        SDL_Texture* texture = nullptr;

        GameObject(int x, int y, int w, int h);

        virtual void update(float deltaTime) = 0;
        virtual void render(SDL_Renderer* renderer) = 0;

        virtual ~GameObject();

};



#endif //GAMEOBJECT_H
