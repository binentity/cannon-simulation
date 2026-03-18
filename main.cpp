#include <string>

#include <SFML/Graphics.hpp>

#include "simulation.h"

using namespace std;

const int SCREEN_FREQUENCY = 144;
const int WIDTH = 1920;
const int HEIGHT = 1080;

const float PI = 3.14159265f;

const std::string PROJECT_NAME = "Cannon simulation";

int main(int argc, char* argv[])
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    Simulation sim;
    sim.run();

    return 0;
}