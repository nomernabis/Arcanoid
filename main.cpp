#include <iostream>
#include <SFML/Graphics.hpp>
#include <ui/Container.h>
#include <ui/MenuList.h>

int main() {

    sf::RenderWindow window(sf::VideoMode(1200, 800), "TEST");
    MenuList menuList;
    menuList.setWindow(&window);
    menuList.setBottomInparent(true);
    menuList.setCenterHorizontal(true);
    menuList.setBackgroundColor(sf::Color::Black);
    menuList.setChildSpacing(20);
    menuList.setPadding(100, 0);
    menuList.add("START");
    menuList.add("OPTIONS");
    menuList.add("EXIT");


    TextNode textNode;
    textNode.setFontSize(40);
    textNode.setText("ARCANOID");
    textNode.setTextColor(sf::Color::White);
    textNode.setWindow(&window);
    textNode.setCenterHorizontal(true);
    textNode.setMarginTop(150);

    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }
            menuList.handleInput(event);
        }
        window.clear(sf::Color::Black);
        window.draw(menuList);
        window.draw(textNode);
        window.display();
    }
    return 0;
}