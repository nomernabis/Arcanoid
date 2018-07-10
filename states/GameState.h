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
    bool is_running = false;
    TextNode textNode;
    TextNode scoresTextNode;
    TextNode levelTextNode;
    int scores = 0;
    sf::RectangleShape filterRect;
    const int marginTop = 20;
    std::string scoresStr = "SCORES ";
    void handlePause(sf::Event& event);
public:
    GameState(Game* game);
    virtual void handleInput(sf::Event& event);
    virtual void update();
    virtual void draw();

    void addScores();
    void groundTouched();
};


#endif //ARCANOID_GAMESTATE_H
