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

#include <iostream>

#include <SFML/Graphics.hpp>

Case::Case(sf::Vector2f const& position) :
    Box(position, sf::Vector2f(1, 1)) {
}

Case::~Case() {
}


void Case::update(sf::Clock *timer) {
    Box::update(timer);
}

Object::Direction Case::collide(Ball *ball, sf::Vector2f *collisionPosition) {
    if (!ball)
        return Direction::NoDirection;
    sf::Vector2f    const& myPosition = position();
    sf::Vector2f    const& mySize = size();
    if (_collide(myPosition, myPosition + sf::Vector2f(mySize.x, 0), ball, collisionPosition))
        return Direction::Up;
    return Direction::NoDirection;
}

void Case::contact() {
    explode();
}

void Case::explode() {

}

bool Case::_collide(const sf::Vector2f &p1, const sf::Vector2f &p2, Ball *ball, sf::Vector2f *collisionPosition) {
    return true;
}
