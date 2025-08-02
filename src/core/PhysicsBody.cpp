//
// Created by Filip on 30.07.2025.
//

#include "PhysicsBody.h"
#include "Collision.h"
#include "../gameobjects/Square.h"


void PhysicsBody::update(GameObject *obj, const float deltaTime, const std::vector<GameObject *> &staticObjects) {
    for (const auto *other: staticObjects) {
        if (obj == other) continue;

        const auto *squareOther = dynamic_cast<const Square *>(other);

        if (obj->shape == ShapeType::RECTANGLE) {
            accelerate(obj, deltaTime);
            if (checkSquareCollision(getBoundingBox(obj), getBoundingBox(other))) {
                if (squareOther) {
                    if (squareOther->type == SquareType::PLATFORM) {
                        obj->transform.position.y = other->transform.position.y - obj->transform.scale.y;
                        velocity.y *= -0.5f;
                    } else if (squareOther->type == SquareType::LEFTWALL) {
                        obj->transform.position.x = other->transform.position.x + obj->transform.scale.x;
                        velocity.x *= -0.5f;
                    } else if (squareOther->type == SquareType::RIGHTWALL) {
                        obj->transform.position.x = other->transform.position.x - obj->transform.scale.x;
                        velocity.x *= -1.5f;
                    }
                } else {
                    obj->transform.position.y = other->transform.position.y - obj->transform.scale.y;
                    velocity.y = 0.0f;
                }
            }
        } else if (obj->shape == ShapeType::CIRCLE) {
            accelerate(obj, deltaTime);
            if (checkCircleCollision(getBoundingBox(obj), getBoundingBox(other))) {
                obj->transform.position.y = other->transform.position.y - obj->transform.scale.y;
                velocity.y *= -0.5f;
            }
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
    if (obj->shape == ShapeType::RECTANGLE && affectedByGravity) {
        acceleration.x = 10.0f;
        acceleration.y = 980.0f;
    } else {
        acceleration.y = 980.0f;
    }
    if (isStatic) return;
    velocity.x += acceleration.x * deltaTime;
    velocity.y += acceleration.y * deltaTime;

    obj->transform.position.x += velocity.x * deltaTime;
    obj->transform.position.y += velocity.y * deltaTime;

    if (obj->shape == ShapeType::CIRCLE) {
        const float radius = obj->transform.scale.x / 2.0f;
        momentOfInertia = 0.5f * mass * radius * radius;
        angularVelocity = velocity.x / radius;
        rotation += angularVelocity * deltaTime;
    }
}



