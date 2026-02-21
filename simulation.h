#ifndef SIMULATION_H
#define SIMULATION_H

#include <string>
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "cannon.h"
#include "ball.h"

extern const int WIDTH;
extern const int HEIGHT;
extern const int SCREEN_FREQUENCY;

extern const std::string PROJECT_NAME;

class Simulation {
private:
    sf::RenderWindow    window;
    Cannon              cannon;
    std::vector<Ball>   balls;
    sf::RectangleShape  ground;

    void render();
    void update(float dt);
    void processEvents();
public:
    Simulation();
    void run();    
    ~Simulation();
};

#endif