//
// Created by pavel_cpp on 30.06.18.
//

#include "State.h"

State::State(Game* game) {
    this->game = game;
    this->window = game->getWindow();
}

Game* State::getGame() {
    return this->game;
}

sf::RenderWindow* State::getWindow() {
    return this->window;
}
