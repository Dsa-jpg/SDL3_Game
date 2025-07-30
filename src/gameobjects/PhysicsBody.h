//
// Created by Filip on 30.07.2025.
//

#ifndef PHYSICSBODY_H
#define PHYSICSBODY_H
#include "GameObject.h"
#include "SDL3/SDL.h"


class PhysicsBody {

    public:

        // velocity
        float vx = 0.0f;
        float vy = 0.0f;
        // acceleration
        float ax = 0.0f;
        float ay = 0.0f;

        float mass = 1.0f;

        bool affectedByGravity = true;

        void update(GameObject *game_object, float deltaTime, const GameObject* floor);

};



#endif //PHYSICSBODY_H
