//
// Created by Filip on 02.08.2025.
//

#include "Circle.h"
#include <cmath>

Circle::Circle(float x, float y, float radius, int segments) : GameObject(x, y, radius * 2, radius * 2),
                                                               radius(radius),
                                                               numSegments(segments) {
    shape = ShapeType::CIRCLE;
}


void Circle::update(const float deltaTime, const std::vector<GameObject *> &staticObjects) {
    body.update(this, deltaTime, staticObjects);
}

void Circle::render(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

    float centerX = transform.position.x + radius;
    float centerY = transform.position.y + radius;

    for (int i = 0; i < numSegments; i++) {
        float theta1 = (M_PI * 2.0f * i) / numSegments;
        float theta2 = (M_PI * 2.0f * (i + 1)) / numSegments;

        float x1 = centerX + radius * cosf(theta1);
        float y1 = centerY + radius * sinf(theta1);
        float x2 = centerX + radius * cosf(theta2);
        float y2 = centerY + radius * sinf(theta2);

        SDL_RenderLine(renderer, x1, y1, x2, y2);
    }
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    float angle = body.rotation;
    float endX = centerX + radius * cosf(angle);
    float endY = centerY + radius * sinf(angle);

    SDL_RenderLine(renderer, centerX, centerY, endX, endY);
}
