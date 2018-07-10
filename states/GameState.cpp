//
// Created by pavel_cpp on 01.07.18.
//

#include "GameState.h"

GameState::GameState(Game *game) : State(game), paddle(game->getWindow()),
                                   ball(game->getWindow()) {

    ball.setPosition(paddle.getPosition().x + paddle.getSize().x / 2 - ball.getSize().x / 2,
                     paddle.getPosition().y - ball.getSize().y);
    ball.stop();
    ball.setFixed(true);

    sf::Color filterColor = sf::Color::Black;
    //50% opacity
    filterColor.a = 128;

    filterRect.setSize({getWindow()->getSize().x, getWindow()->getSize().y});
    filterRect.setFillColor(sf::Color::Black);
    filterRect.setFillColor(filterColor);

    textNode.setText("PRESS SPACE TO START");
    textNode.setWindow(getWindow());
    textNode.setCenterInParent(true);

    scoresTextNode.setText(scoresStr + std::to_string(scores));
    scoresTextNode.setWindow(getWindow());
    scoresTextNode.setPosition(5, 0);
    scoresTextNode.setFontSize(24);

    for (int i = 0; i < 6; ++i) {
        Brick *brick = new Brick(getWindow(), 5 + i * 100, 20 + scoresTextNode.getPosition().y + scoresTextNode.getHeight());
        bricks.push_back(brick);
    }
}

void GameState::groundTouched() {
    paddle.stop();
    ball.stop();
    ball.setPosition(paddle.getPosition().x + paddle.getSize().x / 2 - ball.getSize().x / 2,
                     paddle.getPosition().y - ball.getSize().y);
    ball.setFixed(true);
}

void GameState::handleInput(sf::Event &event) {
    if (!is_running) {
        handlePause(event);
    } else {
        paddle.handleInput(event);
    }
}

void GameState::handlePause(sf::Event &event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Space) {
            if(!is_running){
                is_running = true;
                ball.setFixed(false);
                ball.start();
            }
        }
    }
}

void GameState::update() {
    if(is_running){
        paddle.update(&ball);
        ball.update(paddle, bricks, this);
    }
}

void GameState::addScores() {
    scores++;
    scoresTextNode.setText(scoresStr + std::to_string(scores));
}

void GameState::draw() {
    getWindow()->clear(sf::Color::White);
    getWindow()->draw(paddle);
    getWindow()->draw(ball);
    getWindow()->draw(scoresTextNode);
    for (Brick *brick:bricks) {
        getWindow()->draw(*brick);
    }
    if (!is_running) {
        getWindow()->draw(filterRect);
        getWindow()->draw(textNode);
    }
    getWindow()->display();
}