//
// Created by pavel_cpp on 01.07.18.
//

#ifndef ARCANOID_GAMESTATE_H
#define ARCANOID_GAMESTATE_H


#include <SFML/Graphics/RectangleShape.hpp>
#include <ui/elements/TextNode.h>
#include "State.h"
#include "../game/Paddle.h"
#include "../game/Ball.h"
#include "../game/Brick.h"

class GameState : public State{
    Paddle paddle;
    Ball ball;
    std::vector<Brick*> bricks;
    bool is_paused = true;
    TextNode textNode;
    sf::RectangleShape filterRect;
    void handlePause(sf::Event& event);
public:
    GameState(Game* game);
    virtual void handleInput(sf::Event& event);
    virtual void update();
    virtual void draw();

    void groundTouched();
};


#endif //ARCANOID_GAMESTATE_H
