#include "ball.h"

Ball::Ball(sf::Vector2f pos, float angle, float speed) {
    shape.setRadius(8.f);
    shape.setFillColor(sf::Color::Black);
    shape.setOrigin(8.f, 8.f);
    shape.setPosition(pos);

    float rad = angle * PI / 180,f;
    velocity.x = std::cos(rad) * speed;
    velocity.y = std::sin(rad) * speed;
}

void Ball::update(float dt) {
    velocity.y += GRAVITY * dt;
    shape.move(velocity * dt);

    if (shape.getPosition().y + shape.getRadius() >= GROUND_Y) {
        shape.setPosition(shape.getPosition().x, GROUND_Y - shape.getRadius());

        
        velocity.y = -velocity.y * ELASTICITY;

        // Crutch...for simplicity
        velocity.x *= 0.98f;        
        if (std::abs(velocity.y) < 10.f) 
            velocity.y = 0.f;
    }
}

Ball::~Ball() {
}
