//
// Created by pavel on 03.07.18.
//

#include "Brick.h"

Brick::Brick(sf::RenderWindow* window, float x, float y): window(window) {
    rect.setPosition(x, y);
    rect.setFillColor(sf::Color::Red);
    rect.setOutlineThickness(1);
    rect.setOutlineColor(sf::Color::Black);
    rect.setSize({WIDTH, HEIGHT});
}

bool Brick::intersects(sf::FloatRect& bounds) {
    return rect.getGlobalBounds().intersects(bounds);
}

void Brick::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(rect, states);
}