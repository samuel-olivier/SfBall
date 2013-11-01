//
// Case.hpp for  in /home/olivie_a//rendu/rider/src
// 
// Made by samuel olivier
// Login   <olivie_a@epitech.net>
// 
// Started on  Fri Mar 29 23:14:34 2013 samuel olivier
// Last update Fri Oct 18 20:51:01 2013 samuel olivier
//

#ifndef __Case_HPP__
# define __Case_HPP__

# include "Box.hpp"

class Ball;

class Case : public Box
{
public:
    Case(sf::Vector2f const& position);
    virtual ~Case();

    virtual void  update(sf::Clock* timer);

    virtual Direction   collide(Ball* ball, sf::Vector2f* collisionPosition = NULL) const;

    virtual void        contact();

    virtual void        explode();

    virtual bool        isExploding() const;

protected:
    virtual bool        _collide(sf::Vector2f const& p1, sf::Vector2f const& p2, Ball* ball, sf::Vector2f* collisionPosition = NULL) const;

    bool        _isExploding;
    sf::Clock   _explosionStart;

};

#endif
