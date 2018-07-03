//
// Created by pavel on 03.07.18.
//

#ifndef ARCANOID_BALL_H
#define ARCANOID_BALL_H


#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Ball: public sf::Drawable {
    const float WIDTH = 30;
    const float HEIGHT = 30;
    float dx = 1, dy = -1;
    sf::RectangleShape rect;
    sf::RenderWindow* window;
public:
    Ball(sf::RenderWindow* window);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void update();
    bool isXInBounds(float x);
    bool isYInBounds(float y);
};


#endif //ARCANOID_BALL_H
