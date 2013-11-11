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
#include "ExplodingCase.hpp"
#include "StandardCase.hpp"
#include "Map.hpp"
#include "Bar.hpp"
#include "Wall.hpp"

SfBall::SfBall() :
    _window(new sf::RenderWindow(sf::VideoMode(960, 540), "SfBall")),
    _gameTimer(new sf::Clock()), _scene(new Scene()), _map(new Map()),
    _gameWorld(new b2World(b2Vec2(0, 0))), _playerBar(new Bar(sf::Vector2f(), _gameWorld)) {

    _gameWorld->SetContactListener(this);
    _init();
}

SfBall::~SfBall() {
    if (_window->isOpen())
        _window->close();
    delete _window;
}

void SfBall::_init() {
    _window->setFramerateLimit(30);
    _window->setKeyRepeatEnabled(false);
    _window->setMouseCursorVisible(false);
    sf::View view;
    view.reset(sf::FloatRect(0, 12.375, 22, -12.375));
    _window->setView(view);

    _topWall = new Wall(_gameWorld);
    _topWall->setType(Wall::Top, view);

    _bottomWall = new Wall(_gameWorld);
    _bottomWall->setType(Wall::Bottom, view);

    _leftWall = new Wall(_gameWorld);
    _leftWall->setType(Wall::Left, view);

    _rightWall = new Wall(_gameWorld);
    _rightWall->setType(Wall::Right, view);

    *_scene << _leftWall << _rightWall << _topWall << _bottomWall << _playerBar;
    _initNewGame();
}

void    SfBall::_initNewGame() {
    for (std::list<Ball*>::iterator it = _balls.begin(); it != _balls.end(); ++it)
        delete *it;
    _balls.clear();
    _map->reset(22, 26);
    _resetMousePosition();

    Ball* ball = new Ball(sf::Vector2f(5.5, 5.5), 0.15, _gameWorld);
    ball->setName("Ball_1");
    ball->setSpeed(sf::Vector2f(1, 5));
    *_scene << ball;
    _balls.push_back(ball);
    Case* current;

    for (int i = 0; i < 22; ++i) {
        current = new StandardCase(sf::Vector2f(i, 10), _gameWorld);
        current->setColor(sf::Color::Yellow);
        *_scene << current;
        *_map << current;
    }
    for (int i = 6; i < 22; ++i) {
        current = new StandardCase(sf::Vector2f(i, 5), _gameWorld);
        current->setColor(sf::Color::Yellow);
        *_scene << current;
        *_map << current;
    }
    sf::View view = _window->getView();

    _playerBar->setPosition(sf::Vector2f(view.getCenter().x, 1));
}

void	SfBall::run() {
    while (_window->isOpen()) {
        _update();
        _render();
    }
}

Map *SfBall::map() const {
    return _map;
}

void SfBall::BeginContact(b2Contact *contact) {
}

void SfBall::EndContact(b2Contact *contact) {
}

void SfBall::PreSolve(b2Contact *contact, const b2Manifold *oldManifold) {
    Object* objA = (Object*)contact->GetFixtureA()->GetBody()->GetUserData();
    Object* objB = (Object*)contact->GetFixtureB()->GetBody()->GetUserData();
    Ball* currentBall = dynamic_cast<Ball*>(objA);
    Object* currentObject = NULL;

    if (!currentBall) {
        currentBall = dynamic_cast<Ball*>(objB);
        currentObject = objA;
    } else {
        currentObject = objB;
    }
    if (!currentBall || !currentObject)
        return ;
    Case* currentCase = NULL;
    Wall* currentWall = NULL;
    if ((currentCase = dynamic_cast<Case*>(currentObject)) != NULL) {
        currentCase->contact(this);
    } else if ((currentWall = dynamic_cast<Wall*>(currentObject)) != NULL) {
        if (currentWall == _bottomWall)
            std::cout << "LOOOOSE" << std::endl;
    }
}

void SfBall::PostSolve(b2Contact *contact, const b2ContactImpulse *impulse) {

}

void	SfBall::_update() {
    _checkEvents();
    _updateObjects();
    _resetMousePosition();
}

void	SfBall::_checkEvents() {
    sf::Event event;
    while (_window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            _window->close();
        } else if (event.type == sf::Event::KeyPressed) {

        } else if (event.type == sf::Event::KeyReleased) {
            if (event.key.code == sf::Keyboard::Up)
                _playerBar->extend();
            else if (event.key.code == sf::Keyboard::Down)
                _playerBar->shrink();
        } else if (event.type == sf::Event::MouseButtonPressed) {

        } else if (event.type == sf::Event::MouseButtonReleased) {

        } else if (event.type == sf::Event::MouseMoved) {
            int deltaS = event.mouseMove.x - _window->getSize().x / 2;

            if (deltaS != 0) {
                sf::Vector2f deltaW = _window->mapPixelToCoords(sf::Vector2i(deltaS, 0));

                _playerBar->setX(_playerBar->x() + deltaW.x);
            }
        }
    }
}

void	SfBall::_updateObjects() {
    float barSize = _playerBar->width(),
            barPosition = _playerBar->x(),
            barLeft = barPosition - barSize / 2,
            barRight = barLeft + barSize,
            worldWidth = _window->getView().getSize().x;

    if (barLeft < 0) {
        _playerBar->setX(barSize / 2);
    } else if (barRight > worldWidth) {
        _playerBar->setX(worldWidth - barSize / 2);
    }

    for (int i = 0; i < 10; ++i)
      _gameWorld->Step(1.0 / 200, 6, 20);
    std::list<Object*> objects = _scene->allObjects();

    for (std::list<Object*>::iterator it = objects.begin(); it != objects.end(); ++it) {
        (*it)->update(_gameTimer, this);
        if ((*it)->needDelete()) {
            _scene->removeObject(*it);
            _map->removeCase(dynamic_cast<Case*>(*it));
            delete *it;
        }
    }
    _gameTimer->restart();
}

void SfBall::_resetMousePosition() {
    sf::Mouse::setPosition(sf::Vector2i(_window->getSize().x / 2, _window->getSize().y / 2), *_window);
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
