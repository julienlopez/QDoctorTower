#ifndef TILEFACTORY_HPP
#define TILEFACTORY_HPP

#include <utils/factory.hpp>

#include <QtGlobal>

class QPoint;
class Tile;

class TileFactory
{
public:
    typedef Factory<Tile, quint8, Tile*(*)(const QPoint&)> type_factory;

    static Tile* createGrassTile(const QPoint& p);

    static Tile* createWaterTile(const QPoint& p);

    static Tile* createRoadTile(const QPoint& p);
};

#endif // TILEFACTORY_HPP
