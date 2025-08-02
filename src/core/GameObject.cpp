//
// Created by Filip on 29.07.2025.
//

#include "GameObject.h"

GameObject::GameObject(float x, float y, float w, float h) {
    transform.position = Vec2(x, y);
    transform.scale = Vec2(w, h);
}

