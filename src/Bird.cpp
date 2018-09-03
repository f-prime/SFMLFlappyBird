#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Bird.hpp"
#include "globals.hpp"
#include <iostream>
#include <cmath>

Bird::Bird(sf::RenderWindow& window):window(window) {
    sf::Texture frame_0;
    sf::Texture frame_1;
    sf::Texture frame_2;

    if(!frame_0.loadFromFile("assets/bird/0.png")) {
        std::exit(0);
    }

    if(!frame_1.loadFromFile("assets/bird/1.png")) {
        std::exit(0);
    }

    if(!frame_2.loadFromFile("assets/bird/2.png")) {
        std::exit(0);
    }

    frames[0] = frame_0;
    frames[1] = frame_1;
    frames[2] = frame_2;

    animation_on = 0;
    next_frame = 0;
    gravity_acceleration = 9.8; 
    gravity_value = 0;

    angle = 0;

    flapping = 0;

    bird = sf::RectangleShape(sf::Vector2f(68, 48));
    bird.setTexture(&frames[0]);
    bird.setPosition(WIDTH / 2, 0);
}

void Bird::animate() {
    if(this->flapping > 0) {
        if(animation_on < 2)
            animation_on++;
    } else {
        animation_on = 0;
    }
     
    if(this->angle < 90 && this->flapping <= 0) {
        this->angle += 3;
    }
    
    this->bird.setRotation(this->angle);
    this->bird.setTexture(&frames[animation_on]);
}

void Bird::render() {
    window.draw(this->bird);
}

void Bird::flap() {
    this->angle = -10;
    this->gravity_value = 0;
    this->flapping = 9;
    this->bird.setRotation(-45);
}

void Bird::gravity() {
    bird.move(sf::Vector2f(0, gravity_value));
    gravity_value += 1;
}

bool Bird::collide(sf::RectangleShape& object) {
    return false;
}

void Bird::update() {
    if(this->flapping <= 0) {
        this->gravity();
    } else {
        bird.move(sf::Vector2f(0, -10));
        this->flapping--;        
    }
    this->animate();
    this->render();
}
