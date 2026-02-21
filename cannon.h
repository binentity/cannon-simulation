#ifndef CANNON_H
#define CANNON_H

#include <cmath>
#include <iostream>

#include <SFML/Graphics.hpp>

#include "cannon.h"

extern const float PI;

class Cannon {
private:
    sf::RectangleShape rect;
public:
    Cannon(sf::Vector2f pos);
    
    void update(sf::Vector2i mousePos, sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);

    sf::Vector2f getPosition() const { return rect.getPosition(); }
    float getRotation() const { return rect.getRotation(); }
    
    ~Cannon();
};

#endif