//
// Created by pavel on 03.07.18.
//

#include <iostream>
#include "Ball.h"
#include "../states/GameState.h"

Ball::Ball(sf::RenderWindow *window) {
    this->window = window;
    rect.setFillColor(sf::Color::Red);
    rect.setSize({WIDTH, HEIGHT});
}

bool Ball::isFixed() {
    return is_fixed;
}

float Ball::getWidth() {
    return getSize().x;
}

float Ball::getHeight() {
    return getSize().y;
}

void Ball::setFixed(bool val) {
    is_fixed = val;
}

void Ball::start() {
    dx = speed;
    dy = -speed;
}

void Ball::stop() {
    dx = 0;
    dy = 0;
}

void Ball::setPosition(float x, float y) {
    rect.setPosition(x, y);
}

sf::Vector2f Ball::getPosition() {
    return rect.getPosition();
}

sf::Vector2f Ball::getSize() {
    return rect.getSize();
}

void Ball::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(rect, states);
}

void Ball::update(const Paddle &paddle, std::vector<Brick *> &bricks, GameState* gameState) {
    if(is_fixed){
        return;
    }

    float toX = rect.getPosition().x + dx;
    float toY = rect.getPosition().y + dy;


    if (!isXInBounds(toX)) {
        dx = -dx;
    }
    if (!isYInBounds(toY)) {
        if (toY + getSize().y >= window->getSize().y) {
            stop();
            gameState->groundTouched();
        } else {
            dy = -dy;
        }
    }

    sf::FloatRect toBounds = rect.getGlobalBounds();
    toBounds.left = toX;

    if (paddle.getRect().getGlobalBounds().intersects(toBounds)) {
        //check is from sides
        if (toBounds.left < paddle.getRect().getPosition().x + paddle.getRect().getSize().x / 2) {
            if (dx != -speed) {
                dx = -speed;
            } else {
                rect.setPosition(paddle.getRect().getPosition().x - rect.getSize().x,
                                 rect.getPosition().y);
            }
        } else {
            if (dx != speed) {
                dx = speed;
            } else {
                rect.setPosition(paddle.getRect().getPosition().x + paddle.getRect().getSize().x,
                                 rect.getPosition().y);
            }
        }
    } else {
        toBounds.top = toY;
        if (paddle.getRect().getGlobalBounds().intersects(toBounds)) {
            dy = -dy;
        }
    }
    toBounds.top -= dy;
    for (int i = 0; i < bricks.size(); ++i) {
        Brick *brick = bricks.at(i);
        if (brick->intersects(toBounds)) {
            dx = -dx;
            bricks.erase(bricks.begin() + i);
            delete brick;
            gameState->addScores();
            break;
        } else {
            toBounds.top += dy;
            if (brick->intersects(toBounds)) {
                dy = -dy;
                bricks.erase(bricks.begin() + i);
                delete brick;
                gameState->addScores();
                break;
            }
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
