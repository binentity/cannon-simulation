#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>
#include <cmath>

const float PI          = 3.14159265f;
constexpr float GRAVITY = 981.0f;

constexpr float GROUND_Y = 950.0f;

// Crutch... for simplicity
constexpr float ELASTICITY = 0.6f;

struct Ball {
    sf::CircleShape shape;
    sf::Vector2f velocity;

    void update(float dt);
    void draw(sf::RenderWindow& window) const { window.draw(shape); }
    Ball(sf::Vector2f pos, float angle, float speed);
    ~Ball();
};

#endif