//
// Created by Filip on 30.07.2025.
//

#ifndef FLOOR_H
#define FLOOR_H
#include "GameObject.h"


class Floor: public GameObject {

    public:
    Floor(float x, float y, float w, float h);
    void render(SDL_Renderer *renderer) override;
    void update(float deltaTime) override{}

};



#endif //FLOOR_H
