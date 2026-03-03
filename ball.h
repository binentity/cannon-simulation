#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>

#include "platform.h"

extern const float PI;
constexpr float GRAVITY = 981.0f;

constexpr float GROUND_Y = 950.0f;

// Crutch... for simplicity
constexpr float ELASTICITY = 0.6f;

struct Ball {
    sf::CircleShape shape;
    sf::Vector2f velocity;
    sf::Vertex velocityLine[2];

    float mass = 10.f;

    void update(float dt, const std::vector<Platform>& platforms);
    void updateVelocityLine();
    void drawVelocityLine(sf::RenderWindow& window) const;
    void draw(sf::RenderWindow& window) const { window.draw(shape); }
    Ball(sf::Vector2f pos, float angle, float speed);
    ~Ball() = default;
};

#endif