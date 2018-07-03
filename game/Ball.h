//
// Created by pavel on 03.07.18.
//

#ifndef ARCANOID_BALL_H
#define ARCANOID_BALL_H


#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Paddle.h"

class Ball: public sf::Drawable {
    const float WIDTH = 15;
    const float HEIGHT = 15;
    float dx = 5, dy = -5;
    sf::RectangleShape rect;
    sf::RenderWindow* window;
public:
    Ball(sf::RenderWindow* window);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void update(const Paddle& paddle);
    bool isXInBounds(float x);
    bool isYInBounds(float y);
};


#endif //ARCANOID_BALL_H
