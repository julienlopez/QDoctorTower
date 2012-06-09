#include "tilefactory.hpp"
#include "grasstile.hpp"
#include "watertile.hpp"
#include "roadtile.hpp"

Tile* TileFactory::createGrassTile(const QPoint& p)
{
    return type_factory::instance().create(GrassTile::s_idType, p);
}

Tile* TileFactory::createWaterTile(const QPoint& p)
{
    return type_factory::instance().create(WaterTile::s_idType, p);
}

Tile* TileFactory::createRoadTile(const QPoint& p)
{
    return type_factory::instance().create(RoadTile::s_idType, p);
}
