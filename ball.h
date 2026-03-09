#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>

#include "platform.h"

extern const float PI;
constexpr float GRAVITY = 981.0f;

constexpr float GROUND_Y = 950.0f;

// Crutch... for simplicity
constexpr float ELASTICITY = 0.6f;

class Ball {
public:
    sf::CircleShape shape;
    sf::Vector2f velocity;
    sf::Vertex velocityLine[2];

    float mass = 10.f;

    float getMass() const;
    sf::Vector2f getPosition() const;
    float getRadius() const;
    sf::Vector2f getVelocity() const;
    void addVelocity(const sf::Vector2f velocity);
    void addPosition(const sf::Vector2f pos);
    void setPosition(const sf::Vector2f pos);

    void update(float dt, const std::vector<Platform>& platforms);
    void drawVelocityLine(sf::RenderWindow& window) const;
    void draw(sf::RenderWindow& window) const;
    Ball(sf::Vector2f pos, float angle, float speed);
    ~Ball() = default;
};

#endif