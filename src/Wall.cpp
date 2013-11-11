//
// Wall.cpp for  in /home/olivie_a//rendu/ball2DTest/src
// 
// Made by samuel olivier
// Login   <olivie_a@epitech.net>
// 
// Started on  Thu Mar 28 14:39:20 2013 samuel olivier
// Last update Fri Oct 18 20:52:17 2013 samuel olivier
//

#include "Wall.hpp"
#include "Case.hpp"
#include "Math.hpp"

#include <iostream>

#include <SFML/Graphics.hpp>

Wall::Wall(b2World* world) :
    Box(sf::Vector2f(0, 0), sf::Vector2f(30, 30), world, Static), _type(None) {
}

Wall::~Wall() {
}

void Wall::draw(std::list<sf::Drawable *> &toFill) {
    if (type() != None) {
        Box::draw(toFill);
    }
}

void Wall::setType(Wall::Type type, const sf::View &view) {
    float width = abs(view.getSize().x),
            height = abs(view.getSize().y),
            x = view.getCenter().x,
            y = view.getCenter().y;

    if (type == Left) {
        setPosition(-0.5, y);
        setSize(1, height);
    } else if (type == Right) {
        setPosition(width + 0.5, y);
        setSize(1, height);
    } else if (type == Top){
        setPosition(x, height + 0.25);
        setSize(width, 0.5);
    } else if (type == Bottom) {
        setPosition(x, -0.25);
        setSize(width, 0.5);
    } else {
        _type = None;
        return ;
    }
    _type = type;
}

Wall::Type Wall::type() const {
    return _type;
}
