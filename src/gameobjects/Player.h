//
// Created by Filip on 29.07.2025.
//

#ifndef PLAYER_H
#define PLAYER_H

#pragma once
#include "GameObject.h"

class Player : public GameObject {
public:

    Player(int x, int y, int w, int h);
    void update(float deltaTime) override;
    void render(SDL_Renderer* renderer) override;

};



#endif //PLAYER_H
