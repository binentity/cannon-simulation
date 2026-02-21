#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <cmath>

#include <SFML/Graphics.hpp>

#include "ball.h"
#include "cannon.h"
#include "simulation.h"

using namespace std;

const int SCREEN_FREQUENCY = 144;
const int WIDTH            = 1920;
const int HEIGHT           = 1080;

const std::string PROJECT_NAME = "Cannon simulation";

int main(int argc, char *argv[]) {
    
    // window initialization...
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    Simulation sim;
    // notification messages...
    // cout << "window started..." << endl;

    sim.run();

    // static objects...
    // sf::RectangleShape cannon(sf::Vector2f(50.f, 20.f)); 
    // cannon.setFillColor(sf::Color::White);
    // cannon.setPosition(50, 750);
    // cannon.setOrigin(40, 10);

    // window loop...

    return 0;
}