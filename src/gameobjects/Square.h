//
// Created by Filip on 30.07.2025.
//

#ifndef CIRCLE_H
#define CIRCLE_H
#include "Floor.h"
#include "GameObject.h"
#include "PhysicsBody.h"


class Square : public GameObject{

    PhysicsBody body;
    Floor* floor = nullptr;

    public:
        Square(float x, float y, float w, float h,  Floor* floor);

        void update(float deltaTime) override;
        void render(SDL_Renderer* renderer) override;


};



#endif //CIRCLE_H
