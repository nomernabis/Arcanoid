//
// Created by pavel_cpp on 30.06.18.
//

#ifndef ARCANOID_STATE_H
#define ARCANOID_STATE_H


#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "../Game.h"

class State {
    Game* game;
    sf::RenderWindow* window;
public:
    State(Game* game);
    virtual void handleInput(sf::Event& event){};
    virtual void draw(){};

    sf::RenderWindow* getWindow();
    Game* getGame();
};


#endif //ARCANOID_STATE_H
