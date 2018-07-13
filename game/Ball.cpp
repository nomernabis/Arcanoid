//
// Created by pavel on 03.07.18.
//

#include <iostream>
#include "Ball.h"
#include "../states/GameState.h"

Ball::Ball(sf::RenderWindow *window) {
    this->window = window;
    rect.setFillColor(sf::Color::White);
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

bool Ball::checkPaddleCollisionX(const Paddle& paddle) {
    sf::FloatRect toBounds = rect.getGlobalBounds();
    toBounds.left += dx;

    if(toBounds.intersects(paddle.getRect().getGlobalBounds())){
        return true;
    }
    return false;
}

bool Ball::checkPaddleCollisionY(const Paddle& paddle) {

    sf::FloatRect toBounds = rect.getGlobalBounds();
    toBounds.top += dy;

    if(toBounds.intersects(paddle.getRect().getGlobalBounds())){
        return true;
    }
    return false;
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



    if(checkPaddleCollisionX(paddle)){
        if(getX() < paddle.getX()){
            if(dx != -speed){
                dx = -speed;
            } else {
                //pushing ball to left side
                rect.setPosition(paddle.getX() - getWidth(), getY());
            }
        } else {
            if(dx != speed){
                dx = speed;
            } else {
                rect.setPosition(paddle.right(), getY());
            }
        }
    } else if(checkPaddleCollisionY(paddle)){
        dy = -dy;
    }


    checkCollisionWithBricks(bricks, gameState);
    rect.move(dx, dy);
}

void Ball::checkCollisionWithBricks(std::vector<Brick*>& bricks, GameState* gameState) {
    sf::FloatRect toBounds = rect.getGlobalBounds();
    toBounds.left += dx;
    for (int i = 0; i < bricks.size(); ++i) {
        Brick *brick = bricks.at(i);
        if (brick->intersects(toBounds)) {
            dx = -dx;
            stop();
            rect.setFillColor(sf::Color::Red);
            /*  bricks.erase(bricks.begin() + i);
              delete brick;*/
            gameState->addScores();

        } else {
            toBounds.top += dy;
            if (brick->intersects(toBounds)) {
                dy = -dy;
                bricks.erase(bricks.begin() + i);
                delete brick;
                gameState->addScores();
            }
        }
    }
}

float Ball::getX() {
    return rect.getPosition().x;
}

float Ball::getY() {
    return rect.getPosition().y;
}

bool Ball::isXInBounds(float x) {
    return x >= 0 && x + rect.getSize().x <= window->getSize().x;
}

bool Ball::isYInBounds(float y) {
    return y >= 0 && y + rect.getSize().y <= window->getSize().y;
}
