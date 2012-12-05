#include "tower.hpp"

Tower::Tower(const QPoint& p, quint32 cost): HasCoords<QPoint>(p), m_cost(cost), m_level(1), m_tile(0)
{}

const Tile* Tower::tile() const
{
    return m_tile;
}

void Tower::setTile(const Tile* tile)
{
    m_tile = tile;
}

quint32 Tower::cost() const
{
    return m_cost;
}

quint8 Tower::level() const
{
    return m_level;
}


void Tower::setLevel(quint8 level)
{
    m_level = level;
}

void Tower::setCost(quint32 cost)
{
    m_cost = cost;
}
