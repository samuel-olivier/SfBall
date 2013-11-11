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

# include <Box2D/Dynamics/b2WorldCallbacks.h>

namespace sf {
    class RenderWindow;
    class Clock;
}

class b2World;

class Scene;
class Map;

class Ball;
class Box;
class Bar;
class Wall;

class SfBall : public b2ContactListener {
public:
    SfBall();
    ~SfBall();

    void	run();

    Map*    map() const;

    void BeginContact(b2Contact* contact);
    void EndContact(b2Contact* contact);
    void PreSolve(b2Contact* contact, const b2Manifold* oldManifold);
    void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse);

private:

    void    _init();
    void    _initNewGame();

    void	_update();
    void	_checkEvents();
    void	_render();
    void	_updateObjects();
    void	_resetMousePosition();

    sf::RenderWindow*       _window;
    sf::Clock*              _gameTimer;
    Scene*                  _scene;
    std::list<Ball*>        _balls;
    Map*                    _map;
    b2World*                _gameWorld;
    Bar*                    _playerBar;
    Wall*                   _topWall;
    Wall*                   _bottomWall;
    Wall*                   _leftWall;
    Wall*                   _rightWall;
};

#endif
