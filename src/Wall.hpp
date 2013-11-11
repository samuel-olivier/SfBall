//
// Wall.hpp for  in /home/olivie_a//rendu/rider/src
// 
// Made by samuel olivier
// Login   <olivie_a@epitech.net>
// 
// Started on  Fri Mar 29 23:14:34 2013 samuel olivier
// Last update Fri Oct 18 20:51:01 2013 samuel olivier
//

#ifndef __WALL_HPP__
# define __WALL_HPP__

# include "Box.hpp"

# include <SFML/Graphics.hpp>

class SfBall;

class Wall : public Box
{
public:
    enum Type {
        Top,
        Right,
        Bottom,
        Left,
        None
    };

    Wall(b2World* world);
    virtual ~Wall();

    virtual void    draw(std::list<sf::Drawable*>& toFill);

    virtual void    setType(Type type, sf::View const& view);
    Type    type() const;

protected:
    Type    _type;
};

#endif
