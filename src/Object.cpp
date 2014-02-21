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

Object::Object(sf::Vector2f const& pos, b2World *world, PhysicType physicType) :
    _world(world), _physicType(physicType), _position(pos), _needDelete(false) {
    _init();
}

Object::~Object() {
    delete _move;
    delete _rotate;
    if (_body) {
        _world->DestroyBody(_body);
        _body = NULL;
    }
}

void    Object::_init() {
    _angle = 0;
    _type = _world ? ((Type)((int)Graphic | (int)Physic)) : Graphic;
    _move = NULL;
    _rotate = NULL;
    _fillColor = sf::Color(120, 80, 200);

    if (isPhysic()) {
        _bodyDef.position.Set(x(), y());
        _bodyDef.angle = angle();
        _bodyDef.userData = this;
        if (_physicType == Dynamic) {
            _bodyDef.type = b2_dynamicBody;
            _defaultFixtureDef.density = 0;
        } else if (_physicType == Kinematic) {
            _bodyDef.type = b2_kinematicBody;
        }
        _defaultFixtureDef.friction = 0;
        _defaultFixtureDef.restitution = 1;
        _body = _world->CreateBody(&_bodyDef);
    } else {
        _body = NULL;
    }
}

void Object::_createFixtures() {
    for (auto it = _fixtureDefs.begin(); it != _fixtureDefs.end(); ++it)
        _fixtures.push_back(_body->CreateFixture(&(*it)));
}

void	Object::setPosition(sf::Vector2f const& pos) {
    _position = pos;
    if (_body)
        _body->SetTransform(b2Vec2(position().x, position().y), angle());
}

void Object::setPosition(float x, float y) {
    setPosition(sf::Vector2f(x, y));
}

sf::Vector2f const&	Object::position() const {
    return (_position);
}

void Object::setX(float x) {
    setPosition(x, y());
}

float Object::x() const {
    return position().x;
}

void Object::setY(float y) {
    setPosition(x(), y);
}

float Object::y() const {
    return position().y;
}

void	Object::setSpeed(sf::Vector2f const& speed) {
    _speed = speed;
    if (_body) {
        _body->SetLinearVelocity(b2Vec2(speed.x, speed.y));
    }
}

sf::Vector2f const&	Object::speed() const {
    return _speed;
}

void	Object::setAcceleration(sf::Vector2f const& acceleration) {
    _acceleration = acceleration;
}

sf::Vector2f const&	Object::acceleration() const {
    return (_acceleration);
}

void Object::applyForce(const sf::Vector2f &newForce) {
    if (_body)
        _body->ApplyForceToCenter(b2Vec2(newForce.x, newForce.y), true);
}

void Object::clearForces() {

}

void	Object::setAngle(float angle) {
    _angle = angle;
    if (_body)
        _body->SetTransform(b2Vec2(position().x, position().y), angle);
}

float	Object::angle() const {
    return (_angle);
}

void	Object::setName(std::string const& name) {
    _name = name;
}

std::string const&	Object::name() const {
    return (_name);
}

void Object::setColor(const sf::Color &color) {
    _fillColor = color;
}

const sf::Color &Object::color() const {
    return _fillColor;
}

void	Object::update(sf::Clock* timer, SfBall *game) {
    float elapsed = timer->getElapsedTime().asSeconds();
    if (_move) {
        _move->update();
        _move->currentValue(_position);
        setPosition(position());
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
        setAngle(angle());
        if (_rotate->isFinished()) {
            delete _rotate;
            _rotate = NULL;
        }
    }
    if (_body) {
        b2Vec2 const& tmpPos = _body->GetPosition();
        _position = sf::Vector2f(tmpPos.x, tmpPos.y);
        _angle = _body->GetAngle();
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

void Object::replaceBodyUserObject(Object *data) {
    if (_body)
        _body->SetUserData(data);
}

b2Body*	Object::body() const {
  return _body;
}

std::list<b2Fixture*> const&	Object::fixtures() const {
    return _fixtures;
}

void Object::setNeedDelete(bool needDelete) {
    _needDelete = needDelete;
}

bool Object::needDelete() const {
    return _needDelete;
}
