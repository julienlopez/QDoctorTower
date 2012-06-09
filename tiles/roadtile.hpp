#ifndef __ROADTILE_HPP__
#define __ROADTILE_HPP__

#include "tile.hpp"

class RoadTile : public Tile
{
public:
	RoadTile(const QPoint& coords);
	
	RoadTile* clone() const;

    virtual bool addTower(Tower* tower);

    void draw(QPainter* painter) const;

    static const quint8 s_idType;
    static const bool s_registered;
};

#endif
