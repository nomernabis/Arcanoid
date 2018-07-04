//
// Created by pavel_cpp on 01.07.18.
//

#include "GameState.h"

GameState::GameState(Game* game): State(game), paddle(game->getWindow()),
                                  ball(game->getWindow()) {
   for(int i=0; i < 6; ++i){
       Brick* brick = new Brick(getWindow(), i * 100, 10);
       bricks.push_back(brick);
   }
}

void GameState::handleInput(sf::Event &event) {
    paddle.handleInput(event);
}

void GameState::update() {
    paddle.update();
    ball.update(paddle, bricks);
}

void GameState::draw() {
    getWindow()->clear(sf::Color::White);
    getWindow()->draw(paddle);
    getWindow()->draw(ball);
    for(Brick* brick:bricks){
        getWindow()->draw(*brick);
    }
    getWindow()->display();
}