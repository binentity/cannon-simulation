#include "ball.h"

#include <cmath>
#include <iostream>

#include "platform.h"

Ball::Ball(const sf::Vector2f pos, const float angle, const float speed) {
    shape.setRadius(8.f);
    shape.setFillColor(sf::Color::Black);
    shape.setOrigin(8.f, 8.f);
    shape.setPosition(pos);

    const float rad = angle * PI / 180.f;
    velocity.x = std::cos(rad) * speed;
    velocity.y = std::sin(rad) * speed;
}

void Ball::update(const float dt, const std::vector<Platform>& platforms) {
    velocity.y += GRAVITY * dt;
    shape.move(velocity * dt);
    sf::Vector2f nextPos = shape.getPosition() + velocity * dt;

    for (const auto& platform : platforms) {
        sf::FloatRect ballBounds     = shape.getGlobalBounds();
        sf::FloatRect platformBounds = platform.getBounds();

        ballBounds.left = nextPos.x - shape.getRadius();
        ballBounds.top  = nextPos.y - shape.getRadius();

        if (ballBounds.intersects(platformBounds)) {
            std::cout << "Collision..." << std::endl;

            if (velocity.y > 0.f && shape.getPosition().y > platformBounds.top) {
                velocity.y = -velocity.y * ELASTICITY;
                nextPos.y = platformBounds.top - shape.getRadius();
            } else if (velocity.y < 0.f && shape.getPosition().y > platformBounds.top + platformBounds.height) {
                velocity.y = -velocity.y * ELASTICITY;
                nextPos.y = platformBounds.top + platformBounds.height + shape.getRadius();
            }
        }
    }

    if (shape.getPosition().y + shape.getRadius() >= GROUND_Y) {
        shape.setPosition(shape.getPosition().x, GROUND_Y - shape.getRadius());

        velocity.y = -velocity.y * ELASTICITY;

        // Crutch...for simplicity
        velocity.x *= 0.98f;        
        if (std::abs(velocity.y) < 10.f) 
            velocity.y = 0.f;
    }
}
void Ball::drawVelocityLine(sf::RenderWindow &window) const {
    sf::Vertex line[] = {
        sf::Vertex(shape.getPosition(), sf::Color::Black),
        sf::Vertex(shape.getPosition() + velocity * 0.1f, sf::Color::Black)
    };
    window.draw(line, 2, sf::Lines);
}
