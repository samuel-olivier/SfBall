//
// SfBall.cpp for  in /home/olivie_a//rendu/dxBall/src
// 
// Made by samuel olivier
// Login   <olivie_a@epitech.net>
// 
// Started on  Sat Mar 30 02:20:14 2013 samuel olivier
// Last update Fri Nov  1 13:44:01 2013 samuel olivier
//

#include "SfBall.hpp"

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "Box.hpp"
#include "Ball.hpp"
#include "Math.hpp"
#include "Animation.hpp"
#include "Scene.hpp"

SfBall::SfBall() :
    _window(new sf::RenderWindow(sf::VideoMode(960, 540), "SfBall")),
    _gameTimer(new sf::Clock()), _scene(new Scene()) {
    _window->setFramerateLimit(30);
    _window->setKeyRepeatEnabled(false);
    Ball* ball = new Ball(sf::Vector2f(5, 5), 0.5);
    ball->setName("Ball_1");
    ball->setSpeed(sf::Vector2f(0.1, 0.2));
    *_scene << ball;
}

SfBall::~SfBall() {
    if (_window->isOpen())
        _window->close();
    delete _window;
}

void    SfBall::_initGame() {
    for (std::list<Ball*>::iterator it = _balls.begin(); it != _balls.end(); ++it)
        delete *it;
    _balls.clear();
    for (std::list<Box*>::iterator it = _boxes.begin(); it != _boxes.end(); ++it)
        delete *it;
    _balls.clear();
}

void	SfBall::run() {
    while (_window->isOpen()) {
        _update();
        _render();
    }
}

void	SfBall::_update() {
    _checkEvents();
    _physicUpdate();
}

void	SfBall::_checkEvents() {
    sf::Event event;
    while (_window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            _window->close();
        } else if (event.type == sf::Event::KeyPressed) {

        } else if (event.type == sf::Event::KeyReleased) {

        } else if (event.type == sf::Event::MouseButtonPressed) {

        } else if (event.type == sf::Event::MouseButtonReleased) {

        } else if (event.type == sf::Event::MouseMoved) {

        }
    }
}

void	SfBall::_physicUpdate() {
    std::list<Object*> const& objects = _scene->physicObjects();

    std::cout << objects.size() << std::endl;

    for (std::list<Object*>::const_iterator it = objects.begin(); it != objects.end(); ++it)
        (*it)->update(_gameTimer);
    _gameTimer->restart();
}

void	SfBall::_render() {
    _window->clear();
    std::list<Object*> const& graphicObjects = _scene->graphicObjects();
    for (auto it = graphicObjects.begin(); it != graphicObjects.end(); ++it) {
        std::list<sf::Drawable*> surfaces;
        (*it)->draw(surfaces);
        for (auto it = surfaces.begin(); it != surfaces.end(); ++it) {
            _window->draw(*(*it));
            delete *it;
        }
    }
    _window->display();
}
