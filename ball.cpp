#include "ball.h"

Ball::Ball(sf::Vector2f pos, float angle, float speed) {
    shape.setRadius(8.f);
    shape.setFillColor(sf::Color::Yellow);
    shape.setOrigin(8.f, 8.f);
    shape.setPosition(pos);

    float rad = angle * PI / 180,f;
    velocity.x = std::cos(rad) * speed;
    velocity.y = -std::sin(rad) * speed;
}

void Ball::update(float dt) {
    velocity.y += GRAVITY * dt;
    shape.move(velocity * dt);
}

Ball::~Ball() {
}
