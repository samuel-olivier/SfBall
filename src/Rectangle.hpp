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
    Rectangle(sf::Vector2f const& position, sf::Vector2f const& size, b2World* world, PhysicType physicType = Static);
    virtual ~Rectangle();

    virtual void    draw(std::list<sf::Drawable*>& toFill);

    virtual void    setSize(sf::Vector2f const& size);
    void            setSize(float width, float height);
    virtual sf::Vector2f const&  size() const;

    void            setWidth(float width);
    float           width() const;

    void            setHeight(float height);
    float           height() const;

    void            setLeft(float left);
    float           left() const;

    void            setRight(float right);
    float           right() const;

    void            setTop(float top);
    float           top() const;

    void            setBottom(float bottom);
    float           bottom() const;

    void                setTopLeft(sf::Vector2f const& topLeft);
    sf::Vector2f const& topLeft() const;

    void                setTopRight(sf::Vector2f const& topRight);
    sf::Vector2f const& topRight() const;

    void                setBottomLeft(sf::Vector2f const& bottomLeft);
    sf::Vector2f const& bottomLeft() const;

    void                setBottomRight(sf::Vector2f const& bottomRight);
    sf::Vector2f const& bottomRight() const;

protected:
    b2PolygonShape      _shape;
    sf::Vector2f		_size;
};

#endif
