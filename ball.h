#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>
#include <cmath>

class Ball {
private:
    sf::CircleShape shape;
    sf::Vector2f velocity;
public:
    Ball(sf::Vector2f pos, float angle, float speed);
    
    ~Ball();
};

#endif