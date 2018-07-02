//
// Created by pavel_cpp on 30.06.18.
//

#ifndef ARCANOID_MENUSTATE_H
#define ARCANOID_MENUSTATE_H


#include <ui/MenuList.h>
#include "State.h"

class MenuState : public State {
    MenuList menuList;
    TextNode textNode;
public:
    MenuState(Game* game);
    virtual void handleInput(sf::Event& event);
    virtual void draw();
};


#endif //ARCANOID_MENUSTATE_H
