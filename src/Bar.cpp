//
// Bar.cpp for  in /home/olivie_a//rendu/ball2DTest/src
// 
// Made by samuel olivier
// Login   <olivie_a@epitech.net>
// 
// Started on  Thu Mar 28 14:39:20 2013 samuel olivier
// Last update Fri Oct 18 20:52:17 2013 samuel olivier
//

#include "Bar.hpp"

#include <iostream>

#include <SFML/Graphics.hpp>

#include "Box.hpp"
#include "Circle.hpp"

#define BAR_HEIGHT 0.5

Bar::Bar(sf::Vector2f const& position, b2World *world) :
    Object(position, NULL, Static), _size(3),
    _center(new Box(position, sf::Vector2f(30, 30), world, Kinematic)),
    _left(new Circle(position, BAR_HEIGHT / 2, world, Kinematic)),
    _right(new Circle(position, BAR_HEIGHT / 2, world, Kinematic)) {

    _updateFromBarSize();
    _center->replaceBodyUserObject(this);
    _left->replaceBodyUserObject(this);
    _right->replaceBodyUserObject(this);
}

Bar::~Bar() {
}

void Bar::setPosition(const sf::Vector2f &pos) {
    Object::setPosition(pos);
    _center->setPosition(pos);
    _updateCirclePositions();
}

void Bar::resize(int newSize) {
    _size = newSize;
    _center->resize(sf::Vector2f(_size - BAR_HEIGHT, BAR_HEIGHT), 0.3);
}

void Bar::extend() {
    resize(size() + 1);
}

void Bar::shrink() {
    resize(size() - 1);
}

int Bar::size() const {
    return _size;
}

float Bar::width() const {
    return size();
}

void Bar::draw(std::list<sf::Drawable *> &toFill) {
    _left->draw(toFill);
    _right->draw(toFill);
    _center->draw(toFill);
}

void Bar::_updateFromBarSize() {
    _center->setSize(sf::Vector2f(_size - BAR_HEIGHT, BAR_HEIGHT));
    _updateCirclePositions();
}

void Bar::_updateCirclePositions() {
    _left->setPosition(sf::Vector2f(_center->left(), _center->y()));
    _right->setPosition(sf::Vector2f(_center->right(), _center->y()));
}

void Bar::update(sf::Clock *timer, SfBall *game) {
    Object::update(timer, game);
    _center->update(timer, game);
    _left->update(timer, game);
    _right->update(timer, game);
    if (_center->isResizing()) {
        _updateCirclePositions();
    }
}
