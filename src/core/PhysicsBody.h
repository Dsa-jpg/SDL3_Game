//
// Created by Filip on 30.07.2025.
//

#ifndef PHYSICSBODY_H
#define PHYSICSBODY_H
#include "Common.h"
#include "GameObject.h"
#include "SDL3/SDL.h"


class PhysicsBody {
public:
    ShapeType shapeType = ShapeType::UNKNOWN;
    // velocity
    Vec2 velocity{};
    // acceleration
    Vec2 acceleration{};

    float angularVelocity = 0.0f;
    float torque = 0.0f;
    float rotation = 0.0f;
    float momentOfInertia = 1.0f;

    float mass = 1.0f;

    bool affectedByGravity = true;

    void update(GameObject *obj, float deltaTime, const GameObject *floor);

private:
    static SDL_FRect getBoundingBox(const GameObject *obj);

    void accelerate(GameObject *obj, float deltaTime);
};


#endif //PHYSICSBODY_H
