#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <cmath>

#include <SFML/Graphics.hpp>

using namespace std;

int main(int argc, char *argv[]) {
    
    // window initialization...
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::VideoMode mode(1920, 1080);
    sf::RenderWindow window(mode, "Ball");
    

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