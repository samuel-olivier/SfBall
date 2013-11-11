//
// Map.cpp for  in /home/olivie_a//rendu/rider/src
// 
// Made by samuel olivier
// Login   <olivie_a@epitech.net>
// 
// Started on  Fri Mar 29 16:32:29 2013 samuel olivier
// Last update Fri Oct 18 20:51:30 2013 samuel olivier
//

#include "Map.hpp"

#include <algorithm>
#include <iostream>

#include "Case.hpp"

Map::Map() : _width(0), _height(0) {

}

Map::~Map() {

}

void Map::reset(int width, int height) {
    _width = width;
    _height = height;
    clear();
    std::vector<Case*> line;
    line.resize(width, NULL);
    _cases.resize(height, line);
}

void Map::clear() {
    _cases.clear();
}

int Map::width() const {
    return _width;
}

int Map::height() const {
    return _height;
}

Case *Map::at(int x, int y) const {
    if (x >= 0 && x < width() && y >= 0 && y < height())
        return _cases[y][x];
    return NULL;
}

std::list<Case *> Map::around(Case *check) const {
    int                 x, y;
    std::list<Case*>    res;
    Case*               current = NULL;

    if (_caseIndexes(check, x, y)) {
        for (int i = -1; i < 2; ++i)
            for (int j = -1; j < 2; ++j) {
                if (i == x && j == x)
                    continue ;
                current = at(x + i, y + j);
                if (current)
                    res.push_back(current);
            }
    }
    return res;
}

void	Map::addCase(Case* newCase) {
    int x, y;
    if (!_caseIndexes(newCase, x, y))
        return ;
    if (x >= 0 && x < _width && y >= 0 && y < _height)
        _cases[y][x] = newCase;
}

void	Map::removeCase(Case* toRemove) {
    int x, y;
    if (!_caseIndexes(toRemove, x, y))
        return ;
    if (_cases[y][x] == toRemove) {
        _cases[y][x] = NULL;
    } else {
        for (std::vector<std::vector<Case*>>::iterator it = _cases.begin(); it != _cases.end(); ++it)
            for (std::vector<Case*>::iterator it2 = it->begin(); it2 != it->end(); ++it2)
                if (*it2 == toRemove)
                    *it2 = NULL;
    }
}

void Map::removeCase(int x, int y) {
    if (x >= 0 && x < _width && y >= 0 && y < _height)
        _cases[y][x] = NULL;
}

Map&	Map::operator<<(Case* newCase) {
    this->addCase(newCase);
    return *this;
}

std::list<Case *> Map::allCases() const {
    std::list<Case*> res;

    for (std::vector<std::vector<Case*>>::const_iterator it = _cases.begin(); it != _cases.end(); ++it)
        for (std::vector<Case*>::const_iterator it2 = it->begin(); it2 != it->end(); ++it2)
            if (*it2)
                res.push_back(*it2);
    return res;
}

bool Map::_caseIndexes(Case *current, int &x, int &y) const {
    if (!current)
        return false;
    x = current->position().x / current->size().x;
    y = current->position().y / current->size().y;
    return true;
}

