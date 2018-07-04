//
// Created by pavel on 03.07.18.
//

#include <iostream>
#include "Ball.h"

Ball::Ball(sf::RenderWindow *window) {
    this->window = window;
    rect.setFillColor(sf::Color::Red);
    rect.setSize({WIDTH, HEIGHT});
    rect.setPosition(window->getSize().x / 2 - rect.getSize().x ,
                     window->getSize().y / 2 - rect.getSize().y);
}

void Ball::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(rect, states);
}

void Ball::update(const Paddle& paddle, std::vector<Brick*>& bricks) {
    float toX = rect.getPosition().x + dx;
    float toY = rect.getPosition().y + dy;


    if(!isXInBounds(toX)){
        dx = -dx;
    }
    if(!isYInBounds(toY)){
        dy = -dy;
    }

    sf::FloatRect toBounds = rect.getGlobalBounds();
    toBounds.left = toX;

    if(paddle.getRect().getGlobalBounds().intersects(toBounds)){
        //check is from sides
        if(toBounds.left < paddle.getRect().getPosition().x + paddle.getRect().getSize().x / 2){
            if(dx != -speed){
                dx = -speed;
            } else {
                rect.setPosition(paddle.getRect().getPosition().x - rect.getSize().x, rect.getPosition().y);
            }
        } else {
            if(dx != speed){
                dx = speed;
            } else {
                rect.setPosition(paddle.getRect().getPosition().x + paddle.getRect().getSize().x,
                                 rect.getPosition().y);
            }
        }
    } else {
        toBounds.top = toY;
        if(paddle.getRect().getGlobalBounds().intersects(toBounds)){
            dy = -dy;
        }
    }

    for(int i=0; i < bricks.size(); ++i){
        Brick* brick = bricks.at(i);
        if(brick->intersects(toBounds)){
            dy = -dy;
            bricks.erase(bricks.begin() + i);
            delete brick;
            break;
        }
    }

    rect.move(dx, dy);
}

bool Ball::isXInBounds(float x) {
    return x >= 0 && x + rect.getSize().x <= window->getSize().x;
}

bool Ball::isYInBounds(float y) {
    return y >= 0 && y + rect.getSize().y <= window->getSize().y;
}
