//
// Created by pavel on 03.07.18.
//

#ifndef ARCANOID_BALL_H
#define ARCANOID_BALL_H


#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Brick.h"
#include "Paddle.h"


class Ball : public sf::Drawable {
    const float WIDTH = 15;
    const float HEIGHT = 15;
    float speed = 5;
    float dx = 0, dy = 0;
    sf::RectangleShape rect;
    sf::RenderWindow *window;

public:
    Ball(sf::RenderWindow *window);

    void start();

    void stop();

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    void update(const Paddle &paddle, std::vector<Brick *> &bricks);

    bool isXInBounds(float x);

    bool isYInBounds(float y);

    void setPosition(float x, float y);

    sf::Vector2f getPosition();

    sf::Vector2f getSize();
};


#endif //ARCANOID_BALL_H
