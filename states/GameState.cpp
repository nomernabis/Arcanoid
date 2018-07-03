//
// Created by pavel_cpp on 01.07.18.
//

#include "GameState.h"

GameState::GameState(Game* game): State(game), paddle(game->getWindow()),
                                  ball(game->getWindow()) {
}

void GameState::handleInput(sf::Event &event) {
    paddle.handleInput(event);
}

void GameState::update() {
    ball.update();
    paddle.update();
}

void GameState::draw() {
    getWindow()->clear(sf::Color::White);
    getWindow()->draw(paddle);
    getWindow()->draw(ball);
    getWindow()->display();
}