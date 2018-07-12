//
// Created by pavel on 03.07.18.
//

#include "Brick.h"

Brick::Brick(sf::RenderWindow* window, float x, float y): window(window) {
    rect.setPosition(x, y);
    rect.setFillColor(sf::Color::White);
    rect.setSize({WIDTH, HEIGHT});
}

bool Brick::intersects(sf::FloatRect& bounds) {
    return rect.getGlobalBounds().intersects(bounds);
}

void Brick::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(rect, states);
}

float Brick::getHeight() {
    return rect.getSize().y;
}

float Brick::getWidth() {
    return rect.getSize().x;
}