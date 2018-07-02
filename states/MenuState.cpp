//
// Created by pavel_cpp on 30.06.18.
//

#include <SFML/Window/Event.hpp>
#include <iostream>
#include "MenuState.h"

MenuState::MenuState(Game* game):State(game) {
    menuList.setWindow(State::getWindow());
    menuList.setBottomInparent(true);
    menuList.setCenterHorizontal(true);
    menuList.setBackgroundColor(sf::Color::Black);
    menuList.setChildSpacing(20);
    menuList.setPadding(100, 0);
    menuList.add("START", [this](){
        this->getGame()->changeState(Game::States::GAME_STATE);
    });
    menuList.add("OPTIONS", [](){
        std::cout << "OPTIONS\n";
    });
    menuList.add("EXIT", [this](){
        this->getWindow()->close();
    });

    textNode.setFontSize(40);
    textNode.setText("ARCANOID");
    textNode.setTextColor(sf::Color::White);
    textNode.setWindow(State::getWindow());
    textNode.setCenterHorizontal(true);
    textNode.setMarginTop(150);
}

void MenuState::handleInput(sf::Event& event) {
    menuList.handleInput(event);
}

void MenuState::draw() {
    getWindow()->clear(sf::Color::Black);
    getWindow()->draw(textNode);
    getWindow()->draw(menuList);
    getWindow()->display();
}