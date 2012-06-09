#include "tower.hpp"

Tower::Tower(const QPoint& p): HasCoords<QPoint>(p), m_tile(0)
{}

const Tile* Tower::tile() const
{
    return m_tile;
}

void Tower::setTile(const Tile* tile)
{
    m_tile = tile;
}
