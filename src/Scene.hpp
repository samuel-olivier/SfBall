//
// Scene.hpp for  in /home/olivie_a//rendu/rider/src
// 
// Made by samuel olivier
// Login   <olivie_a@epitech.net>
// 
// Started on  Fri Mar 29 16:14:07 2013 samuel olivier
// Last update Fri Oct 18 20:38:38 2013 samuel olivier
//

#ifndef __SCENE_HPP_
# define __SCENE_HPP_

# include <list>
# include <string>

class Object;

class Scene
{
public:
    Scene();
    ~Scene();

    void		addObject(Object* obj);
    void		removeObject(Object* obj);

    Object*	objectByName(std::string const& name) const;

    std::list<Object*> const&	graphicObjects() const;
    std::list<Object*> const&	physicObjects() const;

    Scene&	operator<<(Object* obj);

    template <class T*>
    std::list<T*>   getObjects() const {
        std::list<T*> res;
        T*  current = NULL;

        for (std::list<Object*>::const_iterator it = _objects.begin(); it != _objects.end(); ++it)
            if ((current = dynamic_cast<T*>(*it)))
                res.push_back(current);
        return res;
    }

private:
    std::list<Object*>	_objects;
    std::list<Object*>	_graphicObjects;
    std::list<Object*>	_physicObjects;
};

#endif
