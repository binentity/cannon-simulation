#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>
#include <cmath>

constexpr float PI      = 3.14159265f;
constexpr float GRAVITY = 981.0f;

struct Ball {
    sf::CircleShape shape;
    sf::Vector2f velocity;

    void update(float dt);
    Ball(sf::Vector2f pos, float angle, float speed);
    ~Ball();
};

#endif