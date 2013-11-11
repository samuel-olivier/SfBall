//
// Ball.hpp for  in /home/olivie_a//rendu/rider/src
// 
// Made by samuel olivier
// Login   <olivie_a@epitech.net>
// 
// Started on  Fri Mar 29 23:14:34 2013 samuel olivier
// Last update Fri Oct 18 20:50:43 2013 samuel olivier
//

#ifndef __BALL_HPP__
# define __BALL_HPP__

# include "Circle.hpp"

class Ball : public Circle
{
public:
    Ball(sf::Vector2f const& position, float radius, b2World* world);
    virtual ~Ball();

    virtual void  resize(float newRadius, float duration);

    virtual void  update(sf::Clock* timer, SfBall *game);


private:
    Animation<float>*        _resize;
};

#endif
