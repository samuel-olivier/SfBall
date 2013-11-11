//
// Box.cpp for  in /home/olivie_a//rendu/ball2DTest/src
// 
// Made by samuel olivier
// Login   <olivie_a@epitech.net>
// 
// Started on  Thu Mar 28 14:39:20 2013 samuel olivier
// Last update Fri Oct 18 20:52:17 2013 samuel olivier
//

#include "Box.hpp"

#include <iostream>

#include <SFML/Graphics.hpp>

Box::Box(sf::Vector2f const& position, sf::Vector2f const& size, b2World *world, PhysicType physicType) :
    Rectangle(position, size, world, physicType), _resize(NULL) {
}

Box::~Box() {
}

void Box::resize(const sf::Vector2f &newSize, float duration) {
    delete _resize;
    _resize = new Animation<sf::Vector2f>();
    _resize->init(size(), newSize, duration);
}

bool Box::isResizing() const {
    return _resize != NULL;
}

void Box::update(sf::Clock *timer, SfBall *game) {
    Rectangle::update(timer, game);
    if (_resize) {
        _resize->update();
        _resize->currentValue(_size);
        setSize(size());
        if (_resize->isFinished()) {
            delete _resize;
            _resize = NULL;
        }
    }
}
