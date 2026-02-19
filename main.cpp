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

constexpr int SCREEN_FREQUENCY = 144;
constexpr int WIDTH            = 1920;
constexpr int HEIGHT           = 1080;

const std::string PROJECT_NAME = "Cannon simulation";

int main(int argc, char *argv[]) {
    
    // window initialization...
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::VideoMode mode(WIDTH, HEIGHT);
    sf::RenderWindow window(mode, PROJECT_NAME);
    window.setFramerateLimit(SCREEN_FREQUENCY);

    // entities...
    sf::Clock clock;
    vector<Ball> balls;

    // notification messages...
    cout << "window started..." << endl;

    // static objects...
    sf::RectangleShape cannon(sf::Vector2f(50.0, 20.0)); 
    cannon.setFillColor(sf::Color::White);
    cannon.setOrigin(0, 10);
    cannon.setPosition(50, 750);

    // window loop...
    while (window.isOpen()) {
        float dt = clock.getElapsedTime().asSeconds();
        sf::Event event {};

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color::Blue);
        window.draw(cannon);

        window.display();
    }

    return 0;
}