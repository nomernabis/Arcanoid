//
// Created by pavel_cpp on 01.07.18.
//

#include "GameState.h"

GameState::GameState(Game* game): State(game) {
    rect.setSize({200, 200});
    rect.setFillColor(sf::Color::Green);
}

void GameState::handleInput(sf::Event &event) {

}

void GameState::draw() {
    getWindow()->clear(sf::Color::White);
    getWindow()->draw(rect);
    getWindow()->display();
}