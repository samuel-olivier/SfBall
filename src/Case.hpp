//
// Case.hpp for  in /home/olivie_a//rendu/rider/src
// 
// Made by samuel olivier
// Login   <olivie_a@epitech.net>
// 
// Started on  Fri Mar 29 23:14:34 2013 samuel olivier
// Last update Fri Oct 18 20:51:01 2013 samuel olivier
//

#ifndef __CASE_HPP__
# define __CASE_HPP__

# include "Box.hpp"

class SfBall;

class Case : public Box
{
public:
    Case(sf::Vector2f const& position, b2World* world);
    virtual ~Case();

    virtual void        update(sf::Clock* timer, SfBall *game);

    virtual void        contact(SfBall *game);

    virtual void        explode(SfBall *game);

    virtual void        makeBreakable();
    virtual void        setBreakable(bool isBreakable);
    virtual bool        isBreakable();

    virtual bool        isExploding() const;

    virtual void        setExplosionDuration(float duration);
    virtual float       explosionDuration() const;
    virtual float       explosionElapsedTime() const;

protected:
    bool        _isExploding;
    sf::Clock   _explosionStart;
    bool        _isBreakable;
    float       _explosionDuration;
};

#endif
