//
// Math.hpp for  in /home/olivie_a//rendu/rider/src
// 
// Made by samuel olivier
// Login   <olivie_a@epitech.net>
// 
// Started on  Sat Mar 30 19:41:28 2013 samuel olivier
// Last update Fri Oct 18 19:53:10 2013 samuel olivier
//

#ifndef __MATH_HPP__
# define __MATH_HPP__

# include <iostream>
# include <SFML/System/Vector2.hpp>

template<class T>
float	vector2Norm(sf::Vector2<T> const& vec)
{
    return (sqrt(vec.x * vec.x + vec.y * vec.y));
}

template<class T>
float	vector2Angle(sf::Vector2<T> const& vec1, sf::Vector2<T> const& vec2)
{
    return (acos((vec1.x * vec2.x + vec1.y * vec2.y) /
                 (vector2Norm(vec1) * vector2Norm(vec2))));
}

template<class T>
sf::Vector2<T>	operator/(sf::Vector2<T> const& left,
                          sf::Vector2<T> const& right)
{
    return (sf::Vector2<T>(left.x / right.x, left.y / right.y));
}

template<class T>
sf::Vector2<T>	operator/(sf::Vector2<T> const& left,
                          float right)
{
    return (sf::Vector2<T>(left.x / right, left.y / right));
}

template<class T>
sf::Vector2<T>	operator*(sf::Vector2<T> const& left,
                          sf::Vector2<T> const& right)
{
    return (sf::Vector2<T>(left.x * right.x, left.y * right.y));
}

template<class T>
sf::Vector2<T>	operator*(sf::Vector2<T> const& left,
                          float right)
{
    return (sf::Vector2<T>(left.x * right, left.y * right));
}

template<class T>
sf::Vector2<T>	abs(sf::Vector2<T> const& val)
{
    return (sf::Vector2<T>(abs(val.x), abs(val.y)));
}

template<class T>
T		absT(T const& val)
{
    return (val < 0 ? (-val) : val);
}

#endif
