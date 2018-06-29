#include <iostream>
#include <SFML/Graphics.hpp>
int main() {
    sf::RenderWindow window(sf::VideoMode(100, 100), "TEST");
    sf::RectangleShape rect({100, 100});
    rect.setFillColor(sf::Color::Red);
    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }
        }
        window.clear(sf::Color::White);
        window.draw(rect);
        window.display();
    }
    return 0;
}