//
// Ball.cpp for  in /home/olivie_a//rendu/ball2DTest/src
// 
// Made by samuel olivier
// Login   <olivie_a@epitech.net>
// 
// Started on  Thu Mar 28 14:39:20 2013 samuel olivier
// Last update Fri Oct 18 20:52:06 2013 samuel olivier
//

#include "Ball.hpp"

#include <iostream>
#include <SFML/Graphics.hpp>

Ball::Ball(sf::Vector2f const& position, float radius, b2World *world) :
    Circle(position, radius, world, Dynamic), _resize(NULL) {
}

Ball::~Ball() {
}

void Ball::resize(float newRadius, float duration) {
    delete _resize;
    _resize = new Animation<float>();
    _resize->init(radius(), newRadius, duration);
}

void Ball::update(sf::Clock *timer, SfBall* game) {
    Circle::update(timer, game);
    if (_resize) {
        _resize->update();
        _resize->currentValue(_radius);
        setRadius(radius());
        if (_resize->isFinished()) {
            delete _resize;
            _resize = NULL;
        }
    }
}
