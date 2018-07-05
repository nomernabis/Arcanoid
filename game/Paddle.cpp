//
// Created by pavel_cpp on 02.07.18.
//

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include "Paddle.h"

Paddle::Paddle(sf::RenderWindow *window) {
    this->window = window;
    rect.setSize({WIDTH, HEIGHT});
    rect.setFillColor(sf::Color::Red);
    rect.setPosition(0, window->getSize().y - rect.getSize().y - 10);
}

sf::RectangleShape Paddle::getRect() const {
    return rect;
}

void Paddle::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(rect, states);
}

void Paddle::handleInput(sf::Event &event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Left) {
            dx = -speed;
        }
        if (event.key.code == sf::Keyboard::Right) {
            dx = speed;
        }
    }
    if (event.type == sf::Event::KeyReleased) {
        dx = 0;
    }
}

void Paddle::update() {
    float toX = rect.getPosition().x + dx;
    if (isInBounds(toX)) {
        rect.move(dx, 0);
    }
}

bool Paddle::isInBounds(float x) {
    return x >= 0 && x + rect.getSize().x <= window->getSize().x;
}