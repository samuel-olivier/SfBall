//
// Scene.cpp for  in /home/olivie_a//rendu/rider/src
// 
// Made by samuel olivier
// Login   <olivie_a@epitech.net>
// 
// Started on  Fri Mar 29 16:32:29 2013 samuel olivier
// Last update Fri Oct 18 20:51:30 2013 samuel olivier
//

#include "Scene.hpp"

#include <algorithm>
#include <iostream>

#include "Object.hpp"

Scene::Scene() {

}

Scene::~Scene() {

}

void	Scene::addObject(Object* obj) {
    if (obj &&
            std::find(_objects.begin(), _objects.end(), obj) == _objects.end()) {
        _objects.push_back(obj);
        if (obj->isGraphic()) {
            _graphicObjects.push_back(obj);
        }
        if (obj->isPhysic()) {
            _physicObjects.push_back(obj);
        }
    }
}

void	Scene::removeObject(Object* obj) {
    if (obj &&
            std::find(_objects.begin(), _objects.end(), obj) != _objects.end()) {
        _objects.remove(obj);
        if (obj->isGraphic())
            _graphicObjects.remove(obj);
        if (obj->isPhysic())
            _physicObjects.remove(obj);
    }
}

Object*	Scene::objectByName(std::string const& name) const {
    for (auto it = _objects.begin(); it != _objects.end(); ++it)
        if ((*it)->name() == name)
            return (*it);
    return (NULL);
}

std::list<Object*> const&	Scene::graphicObjects() const {
    return _graphicObjects;
}

std::list<Object*> const&		Scene::physicObjects() const {
    return _physicObjects;
}

Scene&	Scene::operator<<(Object* obj) {
    this->addObject(obj);
    return *this;
}

