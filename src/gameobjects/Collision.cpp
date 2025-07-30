//
// Created by Filip on 30.07.2025.
//

#include "Collision.h"

bool checkCollision(const SDL_FRect& a,const  SDL_FRect& b) {
    return SDL_HasRectIntersectionFloat(&a,&b);
}
