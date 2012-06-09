#include "roadtile.hpp"
#include "tilefactory.hpp"

const quint8 RoadTile::s_idType = 1;

RoadTile::RoadTile(const QPoint& coords): Tile(coords)
{}
	
RoadTile* RoadTile::clone() const
{
	return new RoadTile(*this);
}

bool RoadTile::addTower(Tower*)
{
    return false;
}

void RoadTile::draw(QPainter* painter) const
{
    Tile::draw(painter, Qt::lightGray);
}

namespace {
	
Tile* creerRoadTile(const QPoint& coords)
{
    return new RoadTile(coords);
}

}

const bool RoadTile::s_registered = TileFactory::type_factory::instance().registerProduct(RoadTile::s_idType, &creerRoadTile);
