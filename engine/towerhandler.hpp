#ifndef TOWERHANDLER_HPP
#define TOWERHANDLER_HPP

#include "iengine.hpp"

class Tower;

class TowerHandler : public iEngine
{
public:
    typedef boost::shared_ptr<Tower> sp_tower;
    typedef std::list<sp_tower> type_liste;

    TowerHandler();

    void addTower(Tower* t);

protected:
    void maj();

private:
    type_liste m_towers;
};

#endif // TOWERHANDLER_HPP
