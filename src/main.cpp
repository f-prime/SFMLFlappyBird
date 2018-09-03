#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "globals.hpp"
#include "Bird.hpp"
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML Flappy Bird");

    sf::Texture background;
    background.loadFromFile("assets/background.png");
    sf::Texture ground;
    ground.loadFromFile("assets/base.png");
    
    sf::RectangleShape background_rect(sf::Vector2f(WIDTH, HEIGHT));
    background_rect.setTexture(&background);
    sf::RectangleShape ground_rect(sf::Vector2f(WIDTH, 112 * 3));
    ground_rect.setPosition(0, HEIGHT - 112 * 5);
    ground_rect.setTexture(&ground);

    Bird bird(window);
    
    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                window.close();
            if(event.type == sf::Event::KeyPressed) {
                bird.flap();
            }
        }
        
        window.clear(sf::Color(255,255,255));

        window.draw(background_rect);
        window.draw(ground_rect);
        bird.update();

        window.display();
        window.setFramerateLimit(60);
    }

    return 0;
}
