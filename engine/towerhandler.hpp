#ifndef TOWERHANDLER_HPP
#define TOWERHANDLER_HPP

#include "iengine.hpp"

class Tower;

class TowerHandler : public iEngine
{
public:
    typedef List<Tower*> type_liste;

    TowerHandler();

    void addTower(Tower* t);

protected:
    void maj();

private:
    type_liste m_towers;
};

#endif // TOWERHANDLER_HPP
