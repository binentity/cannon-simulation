#ifndef SIMULATION_H
#define SIMULATION_H

#include <string>
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "cannon.h"
#include "ball.h"
#include "platform.h"

extern const int WIDTH;
extern const int HEIGHT;
extern const int SCREEN_FREQUENCY;

extern const std::string PROJECT_NAME;

struct Contact {
    sf::Vector2f v1, v2;
};

class Simulation {
    std::vector<Ball>       balls;
    std::vector<Platform>   platforms;
    sf::RenderWindow        window;
    sf::RectangleShape      ground;
    Cannon                  cannon;

    std::vector<Contact> contacts;

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