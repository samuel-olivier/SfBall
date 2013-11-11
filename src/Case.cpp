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

Case::Case(sf::Vector2f const& position, b2World* world) :
    Box(position, sf::Vector2f(1, 0.5), world, Static),
    _isExploding(false), _isBreakable(true), _explosionDuration(0.5) {
}

Case::~Case() {
}


void Case::update(sf::Clock *timer, SfBall *game) {
    Box::update(timer, game);
    if (isExploding() && explosionElapsedTime() > explosionDuration())
        setNeedDelete(true);
}

void Case::contact(SfBall *game) {
    if (isBreakable())
        explode(game);
}

void Case::explode(SfBall *game) {
    _isExploding = true;
    _explosionStart.restart();
}

void Case::makeBreakable() {
    _isBreakable = true;
}

void Case::setBreakable(bool breakable) {
    _isBreakable = breakable;
}

bool Case::isBreakable() {
    return _isBreakable;
}

bool Case::isExploding() const {
    return _isExploding;
}

void Case::setExplosionDuration(float duration) {
    _explosionDuration = duration;
}

float Case::explosionDuration() const {
    return _explosionDuration;
}

float Case::explosionElapsedTime() const {
    return _explosionStart.getElapsedTime().asSeconds();
}
