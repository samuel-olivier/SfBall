//
// Circle.cpp for  in /home/olivie_a//rendu/Circle2DTest/src
// 
// Made by samuel olivier
// Login   <olivie_a@epitech.net>
// 
// Started on  Thu Mar 28 14:39:20 2013 samuel olivier
// Last update Fri Oct 18 20:52:06 2013 samuel olivier
//

#include "Circle.hpp"

#include <iostream>
#include <SFML/Graphics.hpp>

Circle::Circle(sf::Vector2f const& position, float radius, b2World *world, PhysicType physicType) :
    Object(position, world, physicType), _radius(radius) {
    if (_body) {
        setRadius(_radius);
        b2FixtureDef def = _defaultFixtureDef;
        def.shape= &_shape;
        _fixtureDefs.push_back(def);
        _createFixtures();
    }
}

Circle::~Circle() {
}

void	Circle::draw(std::list<sf::Drawable*>& toFill) {
    sf::Vector2f const&	pos = position();
    sf::CircleShape*	res =
            new sf::CircleShape(_radius);

    res->setOrigin(_radius, _radius);
    res->setPosition(pos);
    res->setRotation(angle() * 180 / M_PI);
    res->setFillColor(color());
    toFill.push_back(res);
}

void  Circle::setRadius(float radius) {
    _radius = radius;
    if (_body)
        _shape.m_radius = radius;
}

float  Circle::radius() const {
    return _radius;
}

