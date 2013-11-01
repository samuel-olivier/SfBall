//
// Object.cpp for  in /home/olivie_a//rendu/box2DTest/src
// 
// Made by samuel olivier
// Login   <olivie_a@epitech.net>
// 
// Started on  Thu Mar 28 14:18:25 2013 samuel olivier
// Last update Sun Oct 20 21:40:39 2013 samuel olivier
//

#include "Object.hpp"

#include <iostream>
#include <algorithm>

#include <SFML/Graphics.hpp>

Object::Object(sf::Vector2f const& pos) :
    _position(pos) {
    _init();
}

Object::Object() {
    _init();
}

Object::~Object() {
    delete _move;
    delete _rotate;
}

void    Object::_init() {
    _angle = 0;
    _type = (Type)((int)Graphic | (int)Physic);
    _move = NULL;
    _rotate = NULL;
}


sf::Vector2f const&	Object::position() const {
    return (_position);
}

sf::Vector2f const&	Object::speed() const {
    return (_speed);
}

float	Object::angle() const {
    return (_angle);
}

std::string const&	Object::name() const {
    return (_name);
}

void	Object::setPosition(sf::Vector2f const& pos) {
    _position = pos;
}

void	Object::setSpeed(sf::Vector2f const& speed) {
    _speed = speed;
}

void	Object::setAngle(float angle) {
    _angle = angle;
}

void	Object::setName(std::string const& name) {
    _name = name;
}

void	Object::update(sf::Clock* timer) {
    float elapsed = timer->getElapsedTime().asSeconds();
    for (std::list<sf::Vector2f>::iterator it = _forces.begin(); it != _forces.end(); ++it)
        _acceleration += *it * elapsed;
    _speed += _acceleration * elapsed;
    if (_move) {
        _move->update();
        _move->currentValue(_position);
        if (_move->isFinished()) {
            delete _move;
            _move = NULL;
        }
    } else {
        _position += _speed * elapsed;
    }
    if (_rotate) {
        _rotate->update();
        _rotate->currentValue(_angle);
        if (_rotate->isFinished()) {
            delete _rotate;
            _rotate = NULL;
        }
    }
}

void  Object::draw(std::list<sf::Drawable*>& toFill) {
}

void	Object::setType(Type type) {
    _type = type;
}

Object::Type	Object::type() const {
    return _type;
}

bool	Object::isGraphic() const {
    return _type & Graphic;
}

bool	Object::isPhysic() const {
    return _type & Physic;
}

void    Object::move(sf::Vector2f const& newPosition, float duration) {
    delete _move;
    _move = new Animation<sf::Vector2f>();
    _move->init(_position, newPosition, duration);
}

void    Object::rotate(float newAngle, float duration) {
    delete _rotate;
    _rotate = new Animation<float>();
    _rotate->init(_angle, newAngle, duration);
}
