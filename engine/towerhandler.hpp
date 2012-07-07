#ifndef TOWERHANDLER_HPP
#define TOWERHANDLER_HPP

#include "iengine.hpp"

class Tower;

class TowerHandler : public iEngine
{
public:
    TowerHandler();

    void addTower(Tower* t);

protected:
    void maj();

private:
    QList<Tower*> m_towers;
};

#endif // TOWERHANDLER_HPP
