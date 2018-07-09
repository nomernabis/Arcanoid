//
// Created by pavel_cpp on 01.07.18.
//

#include "GameState.h"

GameState::GameState(Game *game) : State(game), paddle(game->getWindow()),
                                   ball(game->getWindow()) {

    for(int i = 0; i < 6; ++i) {
        Brick *brick = new Brick(getWindow(), 5 + i * 100, 10);
        bricks.push_back(brick);
    }
    ball.setPosition(paddle.getPosition().x + paddle.getSize().x / 2 - ball.getSize().x / 2,
        paddle.getPosition().y - ball.getSize().y);

    sf::Color filterColor = sf::Color::Black;
    //50% opacity
    filterColor.a = 128;

    filterRect.setSize({getWindow()->getSize().x, getWindow()->getSize().y});
    filterRect.setFillColor(sf::Color::Black);
    filterRect.setFillColor(filterColor);


    textNode.setText("PRESS SPACE TO START");
    textNode.setWindow(getWindow());
    textNode.setCenterInParent(true);
}

void GameState::handleInput(sf::Event &event) {
    if(is_paused){
        handlePause(event);
    } else {
        paddle.handleInput(event);
    }
}

void GameState::handlePause(sf::Event &event) {
    if(event.type == sf::Event::KeyPressed){
        if(event.key.code == sf::Keyboard::Space){
            is_paused = false;
            ball.start();
        }
    }
}

void GameState::update() {
    paddle.update();
    ball.update(paddle, bricks);
}

void GameState::draw() {
    getWindow()->clear(sf::Color::White);
    getWindow()->draw(paddle);
    getWindow()->draw(ball);
    for (Brick* brick:bricks) {
        getWindow()->draw(*brick);
    }
    if(is_paused){
        getWindow()->draw(filterRect);
        getWindow()->draw(textNode);
    }
    getWindow()->display();
}