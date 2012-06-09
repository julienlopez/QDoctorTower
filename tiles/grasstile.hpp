#ifndef GRASSTILE_HPP
#define GRASSTILE_HPP

#include "tile.hpp"

class GrassTile : public Tile
{
public:
    GrassTile(const QPoint& coords);

    GrassTile* clone() const;

    virtual bool addTower(Tower* tower);

    void draw(QPainter* painter) const;

    static const quint8 s_idType;
    static const bool s_registered;
};

#endif // GRASSTILE_HPP
