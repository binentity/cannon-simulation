#ifndef PLATFORM_H
#define PLATFORM_H

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Platform {
    sf::RectangleShape shape;

public:
    explicit Platform(sf::Vector2f pos, sf::Vector2f size);
    void draw(sf::RenderWindow& window) const;
    sf::FloatRect getBounds() const;
};

#endif // PLATFORM_H
