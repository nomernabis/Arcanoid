//
// Created by pavel_cpp on 02.07.18.
//

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include "Paddle.h"

#include "Ball.h"
Paddle::Paddle(sf::RenderWindow *window) {
    this->window = window;
    rect.setSize({WIDTH, HEIGHT});
    rect.setFillColor(sf::Color::White);
    rect.setPosition(window->getSize().x / 2 - rect.getSize().x / 2, window->getSize().y - rect.getSize().y - 10);
}


float Paddle::right() const{
    return getX() + getWidth();
}

sf::RectangleShape Paddle::getRect() const {
    return rect;
}

void Paddle::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(rect, states);
}

void Paddle::stop() {
    dx = 0;
    rect.setPosition(window->getSize().x / 2 - rect.getSize().x / 2,
                     window->getSize().y - rect.getSize().y - 10);
}

void Paddle::handleInput(sf::Event& event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Left) {
            dx = -speed;
        }
        if (event.key.code == sf::Keyboard::Right) {
            dx = speed;
        }
        if (event.key.code == sf::Keyboard::Space){
            release_ball = true;
        }
    }
    if (event.type == sf::Event::KeyReleased) {
        dx = 0;
    }
}

sf::Vector2f Paddle::getPosition() {
    return rect.getPosition();
}

sf::Vector2f Paddle::getSize() {
    return rect.getSize();
}

float Paddle::getCenter() {
    return rect.getPosition().x + rect.getSize().x / 2;
}

float Paddle::getX() const {
    return rect.getPosition().x;
}

float Paddle::getY() const {
    return rect.getPosition().y;
}

float Paddle::getWidth() const{
    return rect.getSize().x;
}

float Paddle::getHeight() const{
    return rect.getSize().y;
}

void Paddle::update(Ball* ball) {
    float toX = rect.getPosition().x + dx;
    if (isInBounds(toX)) {
        rect.move(dx, 0);
        if(ball->isFixed()){
            ball->setPosition(getCenter() - ball->getWidth() / 2,
                              getY() - ball->getHeight());
        }
    }
    if(release_ball && ball->isFixed()){
        ball->setFixed(false);
        ball->start();
    }
    release_ball = false;
}

bool Paddle::isInBounds(float x) {
    return x >= 0 && x + rect.getSize().x <= window->getSize().x;
}