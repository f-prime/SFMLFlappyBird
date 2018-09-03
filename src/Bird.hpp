#ifndef BIRD_H
#define BIRD_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Bird {
    private:
        sf::RenderWindow& window;
        sf::RectangleShape bird;
    public:
        sf::Texture frames[3];
        int animation_on;
        int next_frame; 
        float gravity_value;
        float gravity_acceleration;
        int flapping;
        int angle;

        void animate();
        void render();
        void gravity();
        bool collide(sf::RectangleShape& object);
        void update();
        void flap();

        Bird(sf::RenderWindow& window);
};

#endif
