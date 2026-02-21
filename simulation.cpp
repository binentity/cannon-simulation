#include "simulation.h"

Simulation::Simulation() : window(sf::VideoMode(WIDTH, HEIGHT), PROJECT_NAME),
                           cannon({50.f, 750.f}) {

    window.setFramerateLimit(SCREEN_FREQUENCY);
        
    ground.setSize({1920.f, 50.f});
    ground.setFillColor(sf::Color(70, 70, 70));
    ground.setPosition(0, GROUND_Y);
}

void Simulation::run() {
    sf::Clock clock;
    while (window.isOpen()) {
        float dt = clock.restart().asSeconds();
        processEvents();
        update(dt);
        render();
    }
}

void Simulation::update(float dt) {

    // NOTE: i dont like this point!
    cannon.update(sf::Mouse::getPosition(window), window);

    for (auto it = balls.begin(); it != balls.end(); ) {
        it->update(dt);
        
        // NOTE: Not actual for now...
        if (false) it = balls.erase(it); 
        
        ++it;
    }
}

void Simulation::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }

        if (event.type == sf::Event::MouseButtonPressed && 
            event.mouseButton.button == sf::Mouse::Left) {

            // NOTE: speed is const and not depends on events...
            balls.emplace_back(cannon.getPosition(), cannon.getRotation(), 1000.f);
        }
    }
}

void Simulation::render() {
    window.clear(sf::Color(80, 80, 80));
    window.draw(ground);
    
    for (const auto& ball : balls) {
        ball.draw(window);
    }

    // NOTE: also not this...
    cannon.draw(window);

    window.display();
}

Simulation::~Simulation() {
}
