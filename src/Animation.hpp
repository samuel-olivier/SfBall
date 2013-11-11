//
// Animation.hpp for  in /home/olivie_a//rendu/rider/src
// 
// Made by samuel olivier
// Login   <olivie_a@epitech.net>
// 
// Started on  Wed Apr  3 22:20:28 2013 samuel olivier
// Last update Fri Oct 18 20:38:57 2013 samuel olivier
//

#ifndef __ANIMATION_HPP__
# define __ANIMATION_HPP__

# include <iostream>

# include <SFML/System/Clock.hpp>
# include <SFML/System/Vector2.hpp>
# include <cmath>

template<class T>
class Animation
{
public:
    enum InterpolationType {
        Linear,
        Swing
    };

    Animation() : _duration(0), _type(Linear)
    {
    }

    ~Animation()
    {
    }

    void	init(T const& begin, T const& end,
                 float duration, InterpolationType type = Linear)
    {
        _begin = begin;
        _end = end;
        _duration = duration;
        _currentValue = _begin;
        _type = type;
        _timer.restart();
    }

    void	update()
    {
        float ellapsed = _timer.getElapsedTime().asSeconds();

        if (_type == Linear) {
            _currentValue = (ellapsed >= _duration) ? _end :
                                                      (_begin + ((_end - _begin) * (ellapsed / _duration)));
        } else if (_type == Swing) {
            _currentValue = (ellapsed >= _duration) ? _end :
                                                      (_begin + ((_end - _begin) *
                                                                 (float)(0.5 - (cos(M_PI * ellapsed / _duration) / 2.0))));
        }
    }

    void	currentValue(T& fill) const
    {
        fill = _currentValue;
    }

    T const&	currentValue() const
    {
        return (_currentValue);
    }

    bool		isFinished() const
    {
        return (_duration < _timer.getElapsedTime().asSeconds());
    }

    void		setDuration(float newDuration)
    {
        _duration = newDuration;
    }

    void		setEnd(T const& newEnd)
    {
        _end = newEnd;
    }

private:
    float               _duration;
    sf::Clock           _timer;
    T                   _begin;
    T                   _end;
    T               	_currentValue;
    InterpolationType	_type;
};

typedef Animation<sf::Vector2f> VectorAnimation;

#endif
