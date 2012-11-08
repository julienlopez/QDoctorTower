#include "tile.hpp"
#include "towers/tower.hpp"

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
    if(hasTower())
    {
        QString str = m_tower->icone();
        QPixmap p(str);
        QRect square(coords(), QSize(1,1));
        painter->drawPixmap(square, p);
        if(m_tower->hasEnergy())
        {

            painter->setBrush(QColor(50,50,50));
            QRectF full(square);
            full.adjust(0, 0.9, 0, 0);
            painter->drawRect(full);

            painter->setBrush(QColor(200,50,200));
            double ratio = (double)m_tower->energy()/m_tower->energyMax();
            full.adjust(0, 0, ratio-1, 0);
            painter->drawRect(full);
        }
    }
}
