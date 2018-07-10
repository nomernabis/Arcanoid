//
// Created by pavel_cpp on 02.07.18.
//

#ifndef ARCANOID_PADDLE_H
#define ARCANOID_PADDLE_H


#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

class Ball;
class Paddle : public sf::Drawable {
    sf::RectangleShape rect;
    sf::RenderWindow *window;
    float dx = 0;
    bool release_ball;
    float speed = 10;
    bool isInBounds(float x);
    float getCenter();
public:
    const float WIDTH = 150;
    const float HEIGHT = 20;

    Paddle(sf::RenderWindow *window);

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    void handleInput(sf::Event &);

    void update(Ball* ball);

    sf::RectangleShape getRect() const;

    sf::Vector2f getPosition();

    sf::Vector2f getSize();

    float getX();

    float getY();

    float getWidth();

    float getHeight();

    void stop();
};


#endif //ARCANOID_PADDLE_H
