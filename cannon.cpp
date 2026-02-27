#include "cannon.h"

#include <cmath>

Cannon::Cannon(const sf::Vector2f pos) {
    rect.setPosition(pos);
    rect.setSize({50.f, 20.f});
    rect.setOrigin(40.f, 10.f);
    
    rect.setFillColor(sf::Color::Red);
}

void Cannon::update(const sf::Vector2i mousePos,
                    const sf::RenderWindow &window) {

    const sf::Vector2f worldMousePos = window.mapPixelToCoords(mousePos);
    
    // Just for xs...
    // std::cout << mousePos.x << std::endl;
    // std::cout << worldMousePos.x << std::endl;

    const sf::Vector2f dir     = worldMousePos - rect.getPosition();
    const float angle          = std::atan2(dir.y, dir.x) * 180.0f / PI;
    
    rect.setRotation(angle);
}

void Cannon::draw(sf::RenderWindow &window) const {
    window.draw(rect);
}
