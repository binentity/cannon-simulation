#ifndef CANNON_H
#define CANNON_H

#include <SFML/Graphics.hpp>

#include "cannon.h"

extern const float PI;

class Cannon {
    sf::RectangleShape rect;

public:
    explicit Cannon(sf::Vector2f pos);

    void update(sf::Vector2i mousePos, const sf::RenderWindow& window);
    void draw(sf::RenderWindow& window) const;

    sf::Vector2f getPosition() const { return rect.getPosition(); }
    float getRotation() const { return rect.getRotation(); }

    ~Cannon() = default;
};

#endif