#ifndef UTILS_H
#define UTILS_H

#include <SFML/Graphics.hpp>

float[] lerp(float x1, float x2, float y1, float y2, int points);
float getTopleft(sf::RectangleShape rect);
float getTopRight(sf::RectangleShape rect);
float getBottomLeft(sf::RectangleShape rect);
float getBottomRight(sf::RectangleShape rect);
float getMiddle(sf::RectangleShape rect);
bool collide(sf::RectangleShape& rect1, sf::RectangleShape rect2);

#endif
