//
// Created by Filip on 30.07.2025.
//

#include "PhysicsBody.h"

#include <iostream>

#include "Collision.h"

void PhysicsBody::update(GameObject *obj, const float deltaTime, const GameObject *floor) {
    if (obj->shape == ShapeType::RECTANGLE) {
        accelerate(obj, deltaTime);
        if (checkSquareCollision(getBoundingBox(obj), getBoundingBox(floor))) {
            obj->transform.position.y = floor->transform.position.y - obj->transform.scale.y;
            velocity.y *= -0.5f;
        }
    } else if (obj->shape == ShapeType::CIRCLE) {
        accelerate(obj, deltaTime);
        if (checkCircleCollision(getBoundingBox(obj), getBoundingBox(floor))) {
            obj->transform.position.y = floor->transform.position.y - obj->transform.scale.y;
            velocity.y *= -0.5f;
        }
    }
}

SDL_FRect PhysicsBody::getBoundingBox(const GameObject *obj) {
    return SDL_FRect{
        obj->transform.position.x,
        obj->transform.position.y,
        obj->transform.scale.x,
        obj->transform.scale.y
    };
}


void PhysicsBody::accelerate(GameObject *obj, float deltaTime) {
    if (affectedByGravity) {
        acceleration.y = 980.0f;
    }

    velocity.x += acceleration.x * deltaTime;
    velocity.y += acceleration.y * deltaTime;

    obj->transform.position.x += velocity.x * deltaTime;
    obj->transform.position.y += velocity.y * deltaTime;
}



