#ifndef WATERTILE_H
#define WATERTILE_H

#include "tile.hpp"

class WaterTile : public Tile
{
public:
    WaterTile(const QPoint& coords);

    virtual bool addTower(Tower* tower);

    virtual WaterTile* clone() const;

    void draw(QPainter* painter) const;

    static const quint8 s_idType;
    static const bool s_registered;
};

#endif // WATERTILE_H
