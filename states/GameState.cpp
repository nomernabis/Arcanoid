//
// Created by pavel_cpp on 01.07.18.
//

#include <iostream>
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
    filterRect.setFillColor(filterColor);

    infoTextNode.setText("PRESS SPACE TO START");
    infoTextNode.setTextColor(sf::Color::White);
    infoTextNode.setWindow(getWindow());
    infoTextNode.setCenterInParent(true);

    scoresTextNode.setText(scoresStr + std::to_string(scores));
    scoresTextNode.setWindow(getWindow());
    scoresTextNode.setTextColor(sf::Color::White);
    scoresTextNode.setPosition(5, 0);
    scoresTextNode.setFontSize(24);


    livesTextNode.setText(livesStr + std::to_string(lives));
    livesTextNode.setWindow(getWindow());
    livesTextNode.setTextColor(sf::Color::White);
    livesTextNode.setPosition(scoresTextNode.getPosition().x + scoresTextNode.getWidth() + 25,
                              scoresTextNode.getPosition().y);
    livesTextNode.setFontSize(24);

    initBricks();
}

void GameState::initBricks() {


    for (int i = 0; i < BRICK_ROWS; ++i) {
        for(int j=0; j < BRICK_COLS; ++j){
            Brick *brick = new Brick(getWindow(), 50 + j * (Brick::WIDTH + 10), 20 + scoresTextNode.getPosition().y + scoresTextNode.getHeight() + i* (Brick::HEIGHT + 10) + 20);
            bricks.push_back(brick);
        }
    }
}

GameState::~GameState() {
    for(Brick* brick:bricks){
        delete brick;
    }
}

void GameState::groundTouched() {
    paddle.stop();
    ball.stop();
    ball.setPosition(paddle.getPosition().x + paddle.getSize().x / 2 - ball.getSize().x / 2,
                     paddle.getPosition().y - ball.getSize().y);
    ball.setFixed(true);

    lives--;
    livesTextNode.setText(livesStr + std::to_string(lives));
    if(lives == 0){
        is_running = false;
        is_lose = true;
        infoTextNode.setText("YOU LOOSE!");
        infoTextNode.setCenterHorizontal(true);
    }
}

void GameState::handleInput(sf::Event& event) {
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
                if(is_lose || is_win){
                    restart();
                }
            }
        }
    }
}

void GameState::update() {
    if(is_running){
        paddle.update(&ball);
        ball.update(paddle, bricks, this);
        std::cout << bricks.size() << "\n";
        if(bricks.empty()){
            is_win = true;
            is_running = false;
            infoTextNode.setText("YOU WIN!");
            infoTextNode.setCenterInParent(true);
        }
    }
}

void GameState::addScores() {
    scores++;
    scoresTextNode.setText(scoresStr + std::to_string(scores));
}

void GameState::draw() {
    getWindow()->clear(sf::Color::Black);
    getWindow()->draw(paddle);
    getWindow()->draw(ball);
    getWindow()->draw(scoresTextNode);
    getWindow()->draw(livesTextNode);
    for (Brick *brick:bricks) {
        getWindow()->draw(*brick);
    }
    if (!is_running) {
        getWindow()->draw(filterRect);
        getWindow()->draw(infoTextNode);
    }
    getWindow()->display();
}

void GameState::restart() {
    paddle.stop();
    ball.stop();
    ball.setFixed(true);

    for(Brick* brick:bricks){
        delete brick;
    }
    bricks.clear();

    initBricks();
    scores = 0;
    lives = 3;
    is_win = false;
    is_lose = false;
    scoresTextNode.setText(scoresStr + std::to_string(scores));
    livesTextNode.setText(livesStr + std::to_string(lives));
}