//
// Circle.hpp for  in /home/olivie_a//rendu/rider/src
// 
// Made by samuel olivier
// Login   <olivie_a@epitech.net>
// 
// Started on  Fri Mar 29 23:14:34 2013 samuel olivier
// Last update Fri Oct 18 20:50:43 2013 samuel olivier
//

#ifndef __CIRCLE_HPP__
# define __CIRCLE_HPP__

# include "Object.hpp"

class Circle : public Object
{
public:
    Circle(sf::Vector2f const& position, float radius, b2World* world, PhysicType physicType = Static);
    virtual ~Circle();

    virtual void	draw(std::list<sf::Drawable*>& toFill);

    virtual void  setRadius(float radius);
    virtual float  radius() const;

protected:
    float           _radius;
    b2CircleShape   _shape;
};

#endif
