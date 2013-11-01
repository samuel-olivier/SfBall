//
// Rectangle.hpp for  in /home/olivie_a//rendu/rider/src
// 
// Made by samuel olivier
// Login   <olivie_a@epitech.net>
// 
// Started on  Fri Mar 29 23:14:34 2013 samuel olivier
// Last update Fri Oct 18 20:51:01 2013 samuel olivier
//

#ifndef __RECTANGLE_HPP__
# define __RECTANGLE_HPP__

# include "Object.hpp"

class Rectangle : public Object
{
public:
    Rectangle(sf::Vector2f const& position, sf::Vector2f const& size);
    virtual ~Rectangle();

    virtual void  setSize(sf::Vector2f const& size);
    virtual sf::Vector2f const&  size() const;

    virtual void	draw(std::list<sf::Drawable*>& toFill);

protected:
    sf::Vector2f		_size;
};

#endif
