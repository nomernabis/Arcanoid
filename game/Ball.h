//
// Created by pavel on 03.07.18.
//

#ifndef ARCANOID_BALL_H
#define ARCANOID_BALL_H


#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Brick.h"
#include "Paddle.h"

class GameState;

class Ball : public sf::Drawable {
    const float WIDTH = 15;
    const float HEIGHT = 15;
    float speed = 5;
    float dx = 0, dy = 0;
    sf::RectangleShape rect;
    sf::RenderWindow *window;
    bool is_fixed;

public:
    Ball(sf::RenderWindow *window);

    void start();

    void stop();

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    void update(const Paddle &paddle, std::vector<Brick*> &bricks, GameState* gameState);

    bool isXInBounds(float x);

    bool isYInBounds(float y);

    bool checkPaddleCollisionX(const Paddle& paddle);

    bool checkPaddleCollisionY(const Paddle& paddle);

    void setPosition(float x, float y);

    sf::Vector2f getPosition();

    sf::Vector2f getSize();

    float getWidth();

    float getHeight();

    bool isFixed();

    void setFixed(bool val);

    float getX();

    float getY();

    void checkCollisionWithBricks(std::vector<Brick*>& bricks, GameState* gameState);
};


#endif //ARCANOID_BALL_H
