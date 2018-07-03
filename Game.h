//
// Created by pavel_cpp on 30.06.18.
//

#ifndef ARCANOID_GAME_H
#define ARCANOID_GAME_H


#include <SFML/Graphics/RenderWindow.hpp>
class State;

class Game {
    const int SCREEN_WIDTH = 600;
    const int SCREEN_HEGIHT = 600;
    sf::RenderWindow window;
    State* curState = nullptr;
    sf::Clock clock;
    void handleInput();
    void update();
    void draw();
public:
    enum class States{
        MENU_STATE,
        GAME_STATE
    };
    void changeState(States stateId);
    Game();
    ~Game();
    void run();
    sf::RenderWindow* getWindow();
};


#endif //ARCANOID_GAME_H
