#include "ball.h"

#include <cmath>
#include <iostream>

#include "platform.h"

Ball::Ball(const sf::Vector2f pos, const float angle, const float speed) {
    shape.setRadius(20.f);
    shape.setFillColor(sf::Color::Black);
    //shape.setOrigin(10.f, 10.f);
    shape.setPosition(pos);

    const float rad = angle * PI / 180.f;
    velocity.x = std::cos(rad) * speed;
    velocity.y = std::sin(rad) * speed;
}

void Ball::update(const float dt, const std::vector<Platform> &platforms) {
    velocity.y += GRAVITY * dt;
    shape.move(velocity * dt);
    sf::Vector2f nextPos = getPosition() + velocity * dt;

    for (const auto& platform : platforms) {
        sf::FloatRect ballBounds     = shape.getGlobalBounds();
        sf::FloatRect platformBounds = platform.getBounds();

        ballBounds.left = nextPos.x - getRadius();
        ballBounds.top  = nextPos.y - getRadius();

        if (ballBounds.intersects(platformBounds)) {
            //std::cout << "platform collision..." << std::endl;
            
            // TODO: Should be correct...
            if (velocity.y > 0.f && (getPosition().y + getRadius()) > platformBounds.top) {
                velocity.y = -velocity.y * ELASTICITY;
                nextPos.y = platformBounds.top - getRadius();
            } else if (velocity.y < 0.f && (getPosition().y - getRadius()) > 
                                            platformBounds.top + platformBounds.height) {
                velocity.y = -velocity.y * ELASTICITY;
                nextPos.y = platformBounds.top + platformBounds.height + getRadius();
            } else if (velocity.x > 0.f && (getPosition().x + getRadius()) > platformBounds.left) {
                velocity.x = -velocity.x * ELASTICITY;
                nextPos.x = platformBounds.left - getRadius() * 2;
                // std::cout << "left collision..." << std::endl;
            } else if (velocity.x < 0.f && (getPosition().x - getRadius()) < 
                                            platformBounds.left + platformBounds.width) {
                velocity.x = -velocity.x * ELASTICITY;
                nextPos.x = platformBounds.left + platformBounds.width + getRadius() * 2;
                // std::cout << "right collision..." << std::endl;
            }
        }
    }

    if (shape.getPosition().y + shape.getRadius() >= GROUND_Y) {
        shape.setPosition(shape.getPosition().x, GROUND_Y - shape.getRadius());

        velocity.y = -velocity.y * ELASTICITY;

        velocity.x *= 0.98f;        
        if (std::abs(velocity.y) < 10.f) 
            velocity.y = 0.f;
    }
}

void Ball::drawVelocityLine(sf::RenderWindow &window) const {
    const sf::Vertex line[] = {
        sf::Vertex(sf::Vector2f(getPosition().x + getRadius(), 
                    getPosition().y + getRadius()), 
                    sf::Color::Black),

        // NOTE: Per one second...
        sf::Vertex(sf::Vector2f(getPosition().x + velocity.x * 0.2f,
                    getPosition().y + velocity.y * 0.2f),
                    sf::Color::Black)
    };
    window.draw(line, 2, sf::Lines);
}

void Ball::draw(sf::RenderWindow &window) const {
    window.draw(shape);
}

float Ball::getMass() const {
    return mass;
}

sf::Vector2f Ball::getPosition() const {
    return shape.getPosition();
}

float Ball::getRadius() const {
    return shape.getRadius();
}

sf::Vector2f Ball::getVelocity() const {
    return velocity;
}

void Ball::addVelocity(const sf::Vector2f velocity) {
    this->velocity += velocity;
}

void Ball::addPosition(const sf::Vector2f pos) {
    setPosition(getPosition() + pos);
}

void Ball::setPosition(const sf::Vector2f pos) {
    shape.setPosition(pos);
}
