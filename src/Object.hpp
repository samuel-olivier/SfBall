//
// Object.hpp for  in /home/olivie_a//rendu/box2DTest/src
// 
// Made by samuel olivier
// Login   <olivie_a@epitech.net>
// 
// Started on  Thu Mar 28 14:12:39 2013 samuel olivier
// Last update Sun Oct 20 21:41:45 2013 samuel olivier
//

#ifndef __OBJECT_HPP__
# define __OBJECT_HPP__

# include <list>
# include <string>
# include <SFML/System/Vector2.hpp>

# include "Animation.hpp"

namespace sf {
class Drawable;
class Clock;
};

class Object
{
public:

    enum Type {
        Graphic = 0x1,
        Physic = 0x2,
        NoType
    };

    enum Direction {
        Up,
        Down,
        Left,
        Right,
        NoDirection
    };

    Object(sf::Vector2f const& pos);
    Object();
    virtual ~Object();

    virtual void          setPosition(sf::Vector2f const& pos);
    sf::Vector2f const&	position() const;

    virtual void          setSpeed(sf::Vector2f const& speed);
    sf::Vector2f const&	speed() const;

    virtual void	setAngle(float angle);
    float		angle() const;

    virtual void	setType(Type type);
    Type		type() const;
    bool		isGraphic() const;
    bool		isPhysic() const;

    virtual void          setName(std::string const& name);
    std::string const&	name() const;

    virtual void  update(sf::Clock* timer);

    virtual void  draw(std::list<sf::Drawable*>& toFill);

    virtual void  move(sf::Vector2f const& newPosition, float duration);

    virtual void  rotate(float newAngle, float duration);

private:

    void  _init();

    sf::Vector2f		_position;
    sf::Vector2f		_speed;
    sf::Vector2f		_acceleration;
    std::list<sf::Vector2f>   _forces;
    float             _angle;
    std::string		_name;
    Type                  _type;
    Animation<sf::Vector2f>*        _move;
    Animation<float>*             _rotate;
};

#endif
