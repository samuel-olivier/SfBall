//
// StandardCase.cpp for  in /home/olivie_a//rendu/ball2DTest/src
// 
// Made by samuel olivier
// Login   <olivie_a@epitech.net>
// 
// Started on  Thu Mar 28 14:39:20 2013 samuel olivier
// Last update Fri Oct 18 20:52:17 2013 samuel olivier
//

#include "StandardCase.hpp"
#include "Math.hpp"

#include <iostream>

#include <SFML/Graphics.hpp>

StandardCase::StandardCase(sf::Vector2f const& position, b2World* world) :
    Case(position, world) {
    setBreakable(true);
}

StandardCase::~StandardCase() {
}


void StandardCase::update(sf::Clock *timer, SfBall *game) {
    Case::update(timer, game);
}

void StandardCase::explode(SfBall *game) {
    Case::explode(game);
    setColor(sf::Color::Blue);
}

void StandardCase::draw(std::list<sf::Drawable *> &toFill) {
    if (isExploding()) {
        Case::draw(toFill);
    } else {
        Case::draw(toFill);
    }
}
