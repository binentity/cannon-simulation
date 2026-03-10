#ifndef SIMULATION_H
#define SIMULATION_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>

#include "ball.h"
#include "cannon.h"
#include "platform.h"

extern const int WIDTH;
extern const int HEIGHT;
extern const int SCREEN_FREQUENCY;

extern const std::string PROJECT_NAME;

struct Contact {
    sf::Vector2f v1, v2;
};

class Simulation {
    std::vector<Ball> balls;
    std::vector<Platform> platforms;
    sf::RenderWindow window;
    sf::RectangleShape ground;
    Cannon cannon;

    std::vector<Contact> contacts;

    float getDistance(const Ball& b1, const Ball& b2) const;
    sf::Vector2f getDeltaPosition(const Ball& b1, const Ball& b2) const;

    void render();
    void update(float dt);
    void processEvents();
    void resolveBallCollisions();

public:
    Simulation();
    void run();
    ~Simulation() = default;
};

#endif