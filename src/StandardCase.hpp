//
// Case.hpp for  in /home/olivie_a//rendu/rider/src
// 
// Made by samuel olivier
// Login   <olivie_a@epitech.net>
// 
// Started on  Fri Mar 29 23:14:34 2013 samuel olivier
// Last update Fri Oct 18 20:51:01 2013 samuel olivier
//

#ifndef __STANDARD_CASE_HPP__
# define __STANDARD_CASE_HPP__

# include "Case.hpp"

class StandardCase : public Case
{
public:
    StandardCase(sf::Vector2f const& position, b2World* world);
    virtual ~StandardCase();

    virtual void        update(sf::Clock* timer, SfBall *game);

    virtual void        explode(SfBall *game);

    virtual void        draw(std::list<sf::Drawable*>& toFill);

protected:
};

#endif
