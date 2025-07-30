//
// Created by Filip on 30.07.2025.
//

#include "PhysicsBody.h"

#include <iostream>

#include "Collision.h"

void PhysicsBody::update(GameObject* game_object, const float deltaTime, const GameObject* floor) {
    if (affectedByGravity) {
        ay = 10.0f;
        ax = 1.0f;
    }
    vx += ax * deltaTime;
    vy += ay * deltaTime;

    game_object->transform.x += vx * deltaTime;
    game_object->transform.y += vy * deltaTime;


    if (checkCollision(game_object->transform, floor->transform)) {

        game_object->transform.y = floor->transform.y - game_object->transform.h;
        vy *= -0.5f;

    }

}
