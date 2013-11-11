//
// Map.hpp for  in /home/olivie_a//rendu/rider/src
// 
// Made by samuel olivier
// Login   <olivie_a@epitech.net>
// 
// Started on  Fri Mar 29 16:14:07 2013 samuel olivier
// Last update Fri Oct 18 20:38:38 2013 samuel olivier
//

#ifndef __MAP_HPP_
# define __MAP_HPP_

# include <vector>
# include <list>
# include <string>

class Case;

class Map
{
public:
    Map();
    ~Map();

    void		addCase(Case* newCase);
    void		removeCase(Case* toRemove);
    void		removeCase(int x, int y);

    void        reset(int width, int height);
    void        clear();

    int         width() const;
    int         height() const;

    Case*       at(int x, int y) const;

    std::list<Case*>    around(Case* check) const;

    Map&	operator<<(Case* obj);

    std::list<Case*>   allCases() const;

    template <class T>
    std::list<T*>   cases() const {
        std::list<T*> res;
        T*  current = NULL;

        for (std::vector<std::vector<Case*>>::const_iterator it = _cases.begin(); it != _cases.end(); ++it)
            for (std::vector<Case*>::const_iterator it2 = it->begin(); it2 != it->end(); ++it2)
                if ((current = dynamic_cast<T*>(*it2)))
                    res.push_back(current);
        return res;
    }

private:
    bool    _caseIndexes(Case* current, int& x, int& y) const;

    std::vector<std::vector<Case*>> _cases;
    int     _width;
    int     _height;
};

#endif
