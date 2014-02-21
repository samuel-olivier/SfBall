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
#include "Math.hpp"

Rectangle::Rectangle(sf::Vector2f const& position, sf::Vector2f const& size, b2World *world, PhysicType physicType) :
    Object(position, world, physicType), _size(size) {
    if (_body) {
        setSize(_size);
        b2FixtureDef def = _defaultFixtureDef;
        def.shape= &_shape;
        _fixtureDefs.push_back(def);
        this->_createFixtures();
    }
}

Rectangle::~Rectangle() {
}

void	Rectangle::draw(std::list<sf::Drawable*>& toFill) {
    sf::Vector2f		pos = position();
    sf::RectangleShape*	res =
            new sf::RectangleShape(sf::Vector2f(_size.x, _size.y));

    res->setOrigin(_size / 2);
    res->setPosition(pos);
    res->setRotation(angle() * 180 / M_PI);
    res->setFillColor(color());
    toFill.push_back(res);
}

void  Rectangle::setSize(sf::Vector2f const& size) {
    _size = size;
    if (_body) {
        b2PolygonShape* shape = NULL;

        if (_fixtures.size()) {
            b2Fixture* tmp = *_fixtures.begin();
            shape = (b2PolygonShape*)tmp->GetShape();
        } else {
            shape = &_shape;
        }
        shape->SetAsBox(_size.x / 2, _size.y / 2);
    }
}

void Rectangle::setSize(float width, float height) {
    setSize(sf::Vector2f(width, height));
}

sf::Vector2f const&  Rectangle::size() const {
    return _size;
}

void Rectangle::setWidth(float width) {
    setSize(width, height());
}

float Rectangle::width() const {
    return _size.x;
}

void Rectangle::setHeight(float height) {
    setSize(width(), height);
}

float Rectangle::height() const {
    return _size.y;
}

void Rectangle::setLeft(float left) {
    setWidth(right() - left);
    setX(left + width() / 2);
}

float Rectangle::left() const {
    return x() - width() / 2;
}

void Rectangle::setRight(float right) {
    setWidth(right - left());
    setX(right - width() / 2);
}

float Rectangle::right() const {
    return x() + width() / 2;
}

void Rectangle::setTop(float top) {
    setHeight(top - bottom());
    setY(top - height() / 2);
}

float Rectangle::top() const {
    return y() - height() / 2;
}

void Rectangle::setBottom(float bottom) {
    setHeight(top() - bottom);
    setY(bottom + height() / 2);
}

float Rectangle::bottom() const {
    return y() + height() / 2;
}

void Rectangle::setTopLeft(const sf::Vector2f &topLeft) {
    setLeft(topLeft.x);
    setTop(topLeft.y);
}

sf::Vector2f Rectangle::topLeft() const {
    return sf::Vector2f(left(), top());
}

void Rectangle::setTopRight(const sf::Vector2f &topRight) {
    setRight(topRight.x);
    setTop(topRight.y);
}

sf::Vector2f Rectangle::topRight() const {
    return sf::Vector2f(right(), top());
}

void Rectangle::setBottomLeft(const sf::Vector2f &bottomLeft) {
    setLeft(bottomLeft.x);
    setBottom(bottomLeft.y);
}

sf::Vector2f Rectangle::bottomLeft() const {
    return sf::Vector2f(left(), bottom());
}

void Rectangle::setBottomRight(const sf::Vector2f &bottomRight) {
    setRight(bottomRight.x);
    setBottom(bottomRight.y);
}

sf::Vector2f Rectangle::bottomRight() const {
    return sf::Vector2f(right(), bottom());
}
