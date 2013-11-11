//
// Bar.hpp for  in /home/olivie_a//rendu/rider/src
// 
// Made by samuel olivier
// Login   <olivie_a@epitech.net>
// 
// Started on  Fri Mar 29 23:14:34 2013 samuel olivier
// Last update Fri Oct 18 20:51:01 2013 samuel olivier
//

#ifndef __BAR_HPP__
# define __BAR_HPP__

# include "Object.hpp"

class Box;
class Circle;

class Bar : public Object
{
public:
    Bar(sf::Vector2f const& position, b2World* world);
    virtual ~Bar();

    virtual void  setPosition(sf::Vector2f const& pos);

    virtual void    resize(int newSize);
    virtual void    extend();
    virtual void    shrink();
    int             size() const;
    float           width() const;

    virtual void  draw(std::list<sf::Drawable*>& toFill);

    virtual void  update(sf::Clock* timer, SfBall *game);

private:
    void    _updateFromBarSize();
    void    _updateCirclePositions();

    int     _size;
    Box*    _center;
    Circle* _left;
    Circle* _right;
};

#endif
