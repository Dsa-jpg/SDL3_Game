//
// Created by Filip on 30.07.2025.
//

#ifndef COLISSION_H
#define COLISSION_H
#include "SDL3/SDL_rect.h"


bool checkSquareCollision(const SDL_FRect &a, const SDL_FRect &b);

bool checkCircleCollision(const SDL_FRect &a, const SDL_FRect &b);


#endif //COLISSION_H
