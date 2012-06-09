#include "tile.hpp"

#include <QPainter>

Tile::Tile(const QPoint& coords) : HasCoords<QPoint>(coords), Drawable(), m_tower(0)
{}

Tower* Tile::tower()
{
    return m_tower;
}

void Tile::setTower(Tower* tower)
{
    m_tower = tower;
}

bool Tile::hasTower() const
{
    return m_tower != 0;
}

void Tile::draw(QPainter *painter, const QColor& couleur) const
{
    painter->setPen(Qt::black);
    painter->setBrush(couleur);
    painter->drawRect(coords().x(), coords().y(), 1, 1);
}
