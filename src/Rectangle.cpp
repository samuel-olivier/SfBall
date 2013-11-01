//
// Rectangle.cpp for  in /home/olivie_a//rendu/ball2DTest/src
//
// Made by samuel olivier
// Login   <olivie_a@epitech.net>
//
// Started on  Thu Mar 28 14:39:20 2013 samuel olivier
// Last update Fri Oct 18 20:52:17 2013 samuel olivier
//

#include "Rectangle.hpp"

#include <iostream>

#include <SFML/Graphics.hpp>

Rectangle::Rectangle(sf::Vector2f const& position, sf::Vector2f const& size) :
    Object(position), _size(size) {
}

Rectangle::~Rectangle() {
}

void	Rectangle::draw(std::list<sf::Drawable*>& toFill) {
    sf::Vector2f		pos = position();
    sf::RectangleShape*	res =
            new sf::RectangleShape(sf::Vector2f(_size.x * 2, _size.y * 2));

    res->setOrigin(_size);
    res->setPosition(pos);
    res->setRotation(angle() * 180 / M_PI);
    res->setFillColor(sf::Color());
    toFill.push_back(res);
}

void  Rectangle::setSize(sf::Vector2f const& size) {
    _size = size;
}

sf::Vector2f const&  Rectangle::size() const {
    return _size;
}
