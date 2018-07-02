//
// Created by pavel_cpp on 30.06.18.
//

#include <SFML/Window/Event.hpp>
#include "Game.h"
#include "states/MenuState.h"
#include "states/GameState.h"

Game::Game(): window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEGIHT), "ARCANOID"){
    curState = new MenuState(this);
}

sf::RenderWindow* Game::getWindow(){
    return &window;
}

Game::~Game() {
    if(curState != nullptr){
        delete curState;
    }
}

void Game::run() {
    while(window.isOpen()){
        handleInput();
        draw();
    }
}

void Game::handleInput() {
    sf::Event event;
    while (window.pollEvent(event)){
        if(event.type == sf::Event::Closed){
            window.close();
        }
        curState->handleInput(event);
    }
}

void Game::draw() {
    curState->draw();
}

void Game::changeState(Game::States stateId) {
    State* temp = curState;
    switch (stateId){
        case States ::GAME_STATE:
            curState = new GameState(this);
            delete temp;
            break;
        default:
            break;
    }
}