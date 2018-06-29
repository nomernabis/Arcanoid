#include <iostream>
#include <SFML/Graphics.hpp>
#include <ui/Container.h>

int main() {

    Container container;
    sf::RenderWindow window(sf::VideoMode(640, 800), "TEST");
    container.setWindow(&window);
    container.setSize({100, 100});
    container.setSizeMode(Container::SizeMode::FIXED);
    container.setBackgroundColor(sf::Color::Yellow);
    container.setBottomInparent(true);
    container.setCenterHorizontal(true);

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
        window.draw(container);
        window.display();
    }
    return 0;
}