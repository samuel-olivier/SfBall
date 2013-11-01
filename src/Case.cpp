//
// Case.cpp for  in /home/olivie_a//rendu/ball2DTest/src
// 
// Made by samuel olivier
// Login   <olivie_a@epitech.net>
// 
// Started on  Thu Mar 28 14:39:20 2013 samuel olivier
// Last update Fri Oct 18 20:52:17 2013 samuel olivier
//

#include "Ball.hpp"
#include "Case.hpp"
#include "Math.hpp"

#include <iostream>

#include <SFML/Graphics.hpp>

Case::Case(sf::Vector2f const& position) :
    Box(position, sf::Vector2f(1, 1)), _isExploding(false) {
}

Case::~Case() {
}


void Case::update(sf::Clock *timer) {
    Box::update(timer);
}

Object::Direction Case::collide(Ball *ball, sf::Vector2f *collisionPosition) const {
    if (!ball)
        return Direction::NoDirection;
    sf::Vector2f    const& myPosition = position();
    sf::Vector2f    const& mySize = size();

    if (_collide(myPosition, myPosition + sf::Vector2f(mySize.x, 0), ball, collisionPosition))
        return Direction::Up;
    else if (_collide(myPosition + sf::Vector2f(0, mySize.y), myPosition + sf::Vector2f(mySize.x, mySize.y), ball, collisionPosition))
        return Direction::Down;
    else if (_collide(myPosition, myPosition + sf::Vector2f(0, mySize.y), ball, collisionPosition))
        return Direction::Left;
    else if (_collide(myPosition + sf::Vector2f(mySize.x, 0), myPosition + sf::Vector2f(mySize.x, mySize.y), ball, collisionPosition))
        return Direction::Right;
    return Direction::NoDirection;
}

void Case::contact() {
    explode();
}

void Case::explode() {
    _isExploding = true;
    _explosionStart.restart();
}

bool Case::isExploding() const {
    return _isExploding;
}

bool Case::_collide(const sf::Vector2f &p1, const sf::Vector2f &p2, Ball *ball, sf::Vector2f *collisionPosition) const {
    sf::Vector2f const& ballPosition = ball->position();
    float               ballSize = ball->radius();
    sf::Vector2f        u(p2.x - p1.x, p2.y - p1.y);
    sf::Vector2f        AC(ballPosition.x - p1.x, ballPosition.y - p1.y);
    float               num = u.x*AC.y - u.y*AC.x;

    if (num < 0)
       num = -num;
    float den = vector2Norm(u);
    float CI = num / den;
    if (CI < ballSize)
       return true;
    return false;
}
