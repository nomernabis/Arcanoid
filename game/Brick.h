//
// Created by pavel on 03.07.18.
//

#ifndef ARCANOID_BRICK_H
#define ARCANOID_BRICK_H


#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

class Brick: public sf::Drawable{
    sf::RenderWindow* window;
    sf::RectangleShape rect;
public:
    static constexpr float WIDTH = 90;
    static constexpr float HEIGHT = 20;
    Brick(sf::RenderWindow* window, float x, float y);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    bool intersects(sf::FloatRect& bounds);
    float getWidth();
    float getHeight();
};


#endif //ARCANOID_BRICK_H
