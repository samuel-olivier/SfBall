//
// ExplodingCase.cpp for  in /home/olivie_a//rendu/ball2DTest/src
// 
// Made by samuel olivier
// Login   <olivie_a@epitech.net>
// 
// Started on  Thu Mar 28 14:39:20 2013 samuel olivier
// Last update Fri Oct 18 20:52:17 2013 samuel olivier
//

#include "ExplodingCase.hpp"

#include <iostream>

#include <SFML/Graphics.hpp>

#include "Math.hpp"
#include "SfBall.hpp"
#include "Map.hpp"

ExplodingCase::ExplodingCase(sf::Vector2f const& position, b2World* world) :
    Case(position, world), _hasExplodedArounds(false) {
}

ExplodingCase::~ExplodingCase() {
}


void ExplodingCase::update(sf::Clock *timer, SfBall *game) {
    Case::update(timer, game);
    if (game && isExploding() && !_hasExplodedArounds &&
        explosionElapsedTime() > 0.1) {
        Map* gameMap = game->map();

        if (gameMap) {
            std::list<Case*> arounds = gameMap->around(this);
            for (std::list<Case*>::iterator current = arounds.begin(); current != arounds.end(); ++current)
                if (*current && !(*current)->isExploding())
                    (*current)->explode(game);
        }
        _hasExplodedArounds = true;
    }
}

void ExplodingCase::explode(SfBall *game) {
    Case::explode(game);
    setColor(sf::Color::Blue);
}

void ExplodingCase::draw(std::list<sf::Drawable *> &toFill) {
    if (isExploding()) {
        Case::draw(toFill);
    } else {
        Case::draw(toFill);
    }
}
