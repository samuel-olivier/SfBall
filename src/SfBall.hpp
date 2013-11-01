//
// SfBall.hpp for  in /home/olivie_a//rendu/dxBall/src
// 
// Made by samuel olivier
// Login   <olivie_a@epitech.net>
// 
// Started on  Sat Mar 30 02:16:05 2013 samuel olivier
// Last update Fri Nov  1 13:43:55 2013 samuel olivier
//

#ifndef __DXBALL_HPP__
# define __DXBALL_HPP__

# include <list>

namespace sf {
class RenderWindow;
class Clock;
};

class Scene;
class Ball;
class Box;
class Lap;

class SfBall {
public:
    SfBall();
    ~SfBall();

    void	run();

private:

    void  _initGame();

    void	_update();
    void	_checkEvents();
    void	_render();
    void	_physicUpdate();

    sf::RenderWindow*     _window;
    sf::Clock*            _gameTimer;
    Scene*		_scene;
    std::list<Ball*>      _balls;
    std::list<Box*>       _boxes;
    Lap*                  _playerLap;
};

#endif
