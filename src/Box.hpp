//
// Box.hpp for  in /home/olivie_a//rendu/rider/src
// 
// Made by samuel olivier
// Login   <olivie_a@epitech.net>
// 
// Started on  Fri Mar 29 23:14:34 2013 samuel olivier
// Last update Fri Oct 18 20:51:01 2013 samuel olivier
//

#ifndef __BOX_HPP__
# define __BOX_HPP__

# include "Rectangle.hpp"

class Box : public Rectangle
{
public:
    Box(sf::Vector2f const& position, sf::Vector2f const& size, b2World* world, PhysicType physicType = Static);
    virtual ~Box();

    virtual void    resize(sf::Vector2f const& newSize, float duration);
    bool            isResizing() const;

    virtual void  update(sf::Clock* timer, SfBall *game);

private:
    Animation<sf::Vector2f>*        _resize;
};

#endif
