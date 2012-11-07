#include "tower.hpp"

Tower::Tower(const QPoint& p, quint32 cost): HasCoords<QPoint>(p), m_cost(cost), m_tile(0)
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
