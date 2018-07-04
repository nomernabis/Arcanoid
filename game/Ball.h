//
// Created by pavel on 03.07.18.
//

#ifndef ARCANOID_BALL_H
#define ARCANOID_BALL_H


#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Paddle.h"
#include "Brick.h"

class Ball: public sf::Drawable {
    const float WIDTH = 15;
    const float HEIGHT = 15;
    float speed = 5;
    float dx = speed, dy = -speed;
    sf::RectangleShape rect;
    sf::RenderWindow* window;
public:
    Ball(sf::RenderWindow* window);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void update(const Paddle& paddle, std::vector<Brick*>& bricks);
    bool isXInBounds(float x);
    bool isYInBounds(float y);
};


#endif //ARCANOID_BALL_H
