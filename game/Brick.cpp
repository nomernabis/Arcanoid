//
// Created by pavel on 03.07.18.
//

#include "Brick.h"

Brick::Brick(sf::RenderWindow* window, float x, float y): window(window) {
    rect.setPosition(x, y);
    rect.setFillColor(sf::Color::Red);
    rect.setOutlineThickness(2);
    rect.setOutlineColor(sf::Color::Black);
    rect.setSize({100, 50});
}

void Brick::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(rect, states);
}