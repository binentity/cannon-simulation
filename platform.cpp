#include "platform.h"

sf::FloatRect Platform::getBounds() const {
    return shape.getGlobalBounds();
}

Platform::Platform(const sf::Vector2f pos, const sf::Vector2f size) {
    shape.setSize(size);
    shape.setPosition(pos);
    shape.setFillColor(sf::Color(150, 75, 0));
}

void Platform::draw(sf::RenderWindow &window) const {
    window.draw(shape);
}
