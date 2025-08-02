//
// Created by Filip on 02.08.2025.
//

#ifndef VEC2_H
#define VEC2_H

struct Vec2 {
    float x;
    float y;
    Vec2() = default;
    Vec2(float x, float y) : x(x), y(y) {}

    Vec2 operator+(const Vec2 &other) const {  return {x + other.x, y + other.y}; }
    Vec2 operator*(const float scalar) const {  return {scalar * x, scalar * y}; }

};

#endif //VEC2_H
