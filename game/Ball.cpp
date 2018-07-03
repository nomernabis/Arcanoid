//
// Created by pavel on 03.07.18.
//

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

void Ball::update(const Paddle& paddle) {
    float toX = rect.getPosition().x + dx;
    float toY = rect.getPosition().y + dy;

    sf::FloatRect toBounds = rect.getGlobalBounds();
    toBounds.left = toX;
    toBounds.top = toY;

    if(!isXInBounds(toX)){
        dx = -dx;
    }
    if(!isYInBounds(toY) || paddle.getRect().getGlobalBounds().intersects(toBounds)){
        dy = -dy;
    }

    rect.move(dx, dy);
}

bool Ball::isXInBounds(float x) {
    return x >= 0 && x + rect.getSize().x <= window->getSize().x;
}

bool Ball::isYInBounds(float y) {
    return y >= 0 && y + rect.getSize().y <= window->getSize().y;
}
