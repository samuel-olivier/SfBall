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
# include <SFML/Graphics/Color.hpp>

# include <Box2D/Box2D.h>

# include "Animation.hpp"

namespace sf {
class Drawable;
class Clock;
};

class SfBall;

class Object
{
public:

    enum Type {
        Graphic = 0x1,
        Physic = 0x2,
        NoType
    };

    enum PhysicType {
        Dynamic,
        Static,
        Kinematic
    };

    Object(sf::Vector2f const& pos, b2World* world, PhysicType physicType = Static);
    virtual ~Object();

    virtual void        setPosition(sf::Vector2f const& pos);
    void                setPosition(float x, float y);
    sf::Vector2f const&	position() const;

    void            setX(float x);
    float           x() const;

    void            setY(float y);
    float           y() const;

    virtual void        setSpeed(sf::Vector2f const& speed);
    sf::Vector2f const&	speed() const;

    virtual void        setAcceleration(sf::Vector2f const& acceleration);
    sf::Vector2f const&	acceleration() const;

    virtual void        applyForce(sf::Vector2f const& newForce);
    virtual void        clearForces();

    virtual void        setAngle(float angle);
    float               angle() const;

    virtual void        setType(Type type);
    Type                type() const;
    bool                isGraphic() const;
    bool                isPhysic() const;

    virtual void        setName(std::string const& name);
    std::string const&	name() const;

    virtual void        setColor(sf::Color const& color);
    sf::Color const&	color() const;

    virtual void  update(sf::Clock* timer, SfBall *game);

    virtual void  draw(std::list<sf::Drawable*>& toFill);

    virtual void  move(sf::Vector2f const& newPosition, float duration);

    virtual void  rotate(float newAngle, float duration);

    void    replaceBodyUserObject(Object *data);
    b2Body*	body() const;

    std::list<b2Fixture*> const&	fixtures() const;

    void    setNeedDelete(bool needDelete);
    bool    needDelete() const;

protected:
    void    _createFixtures();

    b2World*                _world;
    PhysicType              _physicType;
    b2BodyDef               _bodyDef;
    std::list<b2FixtureDef>	_fixtureDefs;
    b2Body*                 _body;
    std::list<b2Fixture*>	_fixtures;
    b2FixtureDef			_defaultFixtureDef;

private:

    void    _init();

    sf::Vector2f            _position;
    sf::Vector2f            _speed;
    sf::Vector2f            _acceleration;
    std::list<sf::Vector2f> _forces;
    float                   _angle;
    std::string             _name;
    sf::Color               _fillColor;
    Type                    _type;
    Animation<sf::Vector2f>*_move;
    Animation<float>*       _rotate;
    bool                    _needDelete;
};

#endif
