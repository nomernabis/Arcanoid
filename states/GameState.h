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
    bool is_running = false;
    TextNode infoTextNode;
    TextNode scoresTextNode;
    TextNode levelTextNode;
    TextNode livesTextNode;
    int scores = 0;
    int lives = 1;
    bool is_lose = false;
    bool is_win = false;
    sf::RectangleShape filterRect;
    const int marginTop = 20;
    std::string scoresStr = "SCORES ";
    std::string livesStr = "LIVES ";
    void handlePause(sf::Event& event);
    void initBricks();

    const int BRICK_COLS = 6;
    const int BRICK_ROWS = 3;
public:
    GameState(Game* game);
    ~GameState();

    virtual void handleInput(sf::Event& event);
    virtual void update();
    virtual void draw();

    void addScores();
    void groundTouched();
    void restart();
};


#endif //ARCANOID_GAMESTATE_H
