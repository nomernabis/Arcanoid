//
// Created by pavel_cpp on 01.07.18.
//

#include "GameState.h"

GameState::GameState(Game* game): State(game), paddle(game->getWindow()) {
}

void GameState::handleInput(sf::Event &event) {
    paddle.handleInput(event);
}

void GameState::update() {
    paddle.update();
}

void GameState::draw() {
    getWindow()->clear(sf::Color::White);
    getWindow()->draw(paddle);
    getWindow()->display();
}