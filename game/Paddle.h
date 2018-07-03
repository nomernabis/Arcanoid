//
// Created by pavel_cpp on 02.07.18.
//

#ifndef ARCANOID_PADDLE_H
#define ARCANOID_PADDLE_H


#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

class Paddle: public sf::Drawable {
    sf::RectangleShape rect;
    sf::RenderWindow* window;
    float dx = 0;
    float speed = 15;
    bool isInBounds(float x);
public:
    const float WIDTH = 150;
    const float HEIGHT = 50;
    Paddle(sf::RenderWindow* window);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void handleInput(sf::Event&);
    void update();
};


#endif //ARCANOID_PADDLE_H
