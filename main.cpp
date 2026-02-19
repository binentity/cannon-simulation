#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <cmath>

#include <SFML/Graphics.hpp>

#include "ball.h"

using namespace std;

constexpr int screen_frequency = 144;
constexpr int width            = 1920;
constexpr int height           = 1080;

const std::string project_name = "Cannon simulation";

int main(int argc, char *argv[]) {
    
    // window initialization...
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::VideoMode mode(width, height);
    sf::RenderWindow window(mode, project_name);
    window.setFramerateLimit(screen_frequency);

    // notification messages...
    cout << "window started..." << endl;

    // window loop...
    while (window.isOpen()) {
        sf::Event event {};

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color::Blue);

        window.display();
    }

    return 0;
}