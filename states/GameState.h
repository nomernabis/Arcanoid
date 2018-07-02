//
// Created by pavel_cpp on 01.07.18.
//

#ifndef ARCANOID_GAMESTATE_H
#define ARCANOID_GAMESTATE_H


#include <SFML/Graphics/RectangleShape.hpp>
#include "State.h"
#include "../game/Paddle.h"

class GameState : public State{
    Paddle paddle;
public:
    GameState(Game* game);
    virtual void handleInput(sf::Event& event);
    virtual void update();
    virtual void draw();
};


#endif //ARCANOID_GAMESTATE_H
