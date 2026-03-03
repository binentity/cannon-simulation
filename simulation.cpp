#include "simulation.h"

#include <cmath>

Simulation::Simulation() : window(sf::VideoMode(WIDTH, HEIGHT), PROJECT_NAME),
                           cannon({50.f, 750.f}) {

    window.setFramerateLimit(SCREEN_FREQUENCY);
        
    ground.setSize({1920.f, 50.f});
    ground.setFillColor(sf::Color(70, 70, 70));
    ground.setPosition(0, GROUND_Y);

    platforms.emplace_back(sf::Vector2f(200, 500), sf::Vector2f(200, 20));
}

void Simulation::run() {
    sf::Clock clock;
    while (window.isOpen()) {
        const float dt = clock.restart().asSeconds();
        processEvents();
        update(dt);
        render();
    }
}

void Simulation::update(const float dt) {

    // NOTE: i dont like this point!
    cannon.update(sf::Mouse::getPosition(window), window);

    resolveBallCollisions();

    for (auto it = balls.begin(); it != balls.end(); ) {
        it->update(dt, platforms);
        
        // NOTE: Not actual for now...
        // if (false) it = balls.erase(it);
        
        ++it;
    }
}

void Simulation::processEvents() {
    sf::Event event {};
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed ||
            event.type == sf::Event::KeyPressed &&
            event.key.code == sf::Keyboard::Delete) {

            window.close();
        }

        if (event.type == sf::Event::MouseButtonPressed && 
            event.mouseButton.button == sf::Mouse::Left) {

            // NOTE: speed is const and not depends on events...
            balls.emplace_back(cannon.getPosition(), cannon.getRotation(), 500.f);
        }
    }
}

void Simulation::resolveBallCollisions() {
    contacts.clear();

    for (size_t i = 0; i < balls.size(); ++i) {
        for (size_t j = 0; j < balls.size(); ++j) {
            Ball& b1 = balls[i];
            Ball& b2 = balls[j];

            if (i == j) {
                continue;
            }

            const sf::Vector2f delta = b1.shape.getPosition() - b2.shape.getPosition();
            const float dist = std::sqrt(delta.x * delta.x + delta.y * delta.y);
            const float minDist = b1.shape.getRadius() + b2.shape.getRadius();

            if (dist < minDist) {
                std::cout << dist << std::endl;

                const sf::Vector2f normal = delta / dist;

                // TODO: Should be draw
                contacts.push_back({b1.shape.getPosition(), b2.shape.getPosition()});

                const float overlap = minDist - dist;
                const float totalMass = b1.mass + b2.mass;

                // TODO: Now i'll be adding the position of the each ball...
                b1.shape.setPosition(b1.shape.getPosition() + normal * (overlap * (b2.mass / totalMass)));
                b2.shape.setPosition(b2.shape.getPosition() - normal * (overlap * (b1.mass / totalMass)));
                
                sf::Vector2f relativeVelosity = b1.velocity - b2.velocity;
                const float velAlongNormal = relativeVelosity.x * normal.x + relativeVelosity.y * normal.y;
                
                std::cout << velAlongNormal << std::endl;

                if (velAlongNormal < 0) {
                    float j_impulse = -(1.0f + ELASTICITY ) / velAlongNormal;
                    j_impulse /= (1.0f / b1.mass + 1.0f / b2.mass);

                    const sf::Vector2f impulseVec = j_impulse * normal;
                    b1.velocity += impulseVec / b1.mass;
                    b2.velocity -= impulseVec / b2.mass;
                }
            }
        }
    }
}

void Simulation::render() {
    window.clear(sf::Color(80, 80, 80));
    window.draw(ground);
    
    for (const auto& ball : balls) {
        ball.draw(window);
        ball.drawVelocityLine(window);
    }

    for (const auto& platform : platforms) {
        platform.draw(window);
    }

    // NOTE: also not this...
    cannon.draw(window);

    window.display();
}