#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "globals.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML Flappy Bird");
    sf::RectangleShape bird(sf::Vector2f(50, 40));
    sf::Texture bird_texture;
    bird_texture.loadFromFile("assets/bird.png");
    bird.setTexture(&bird_texture);

    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                window.close();
        }
        
        window.clear(sf::Color(255,255,255));

        window.draw(bird);

        window.display();
        window.setFramerateLimit(60);
    }

    return 0;
}
