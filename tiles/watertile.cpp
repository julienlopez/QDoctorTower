#include "watertile.hpp"
#include "tilefactory.hpp"
#include "towers/tower.hpp"
#include "engine/engine.hpp"

const quint8 WaterTile::s_idType = 2;

WaterTile::WaterTile(const QPoint& coords): Tile(coords)
{}

WaterTile* WaterTile::clone() const
{
    return new WaterTile(*this);
}

bool WaterTile::addTower(Tower* tower)
{
    if(!tower || !tower->canGoOnWater() || hasTower()) return false;
    setTower(tower);
    tower->setTile(this);
    Engine::instance()->addTower(tower);
    return true;
}

void WaterTile::draw(QPainter* painter) const
{
    Tile::draw(painter, Qt::blue);
}

namespace {

Tile* creerWaterTile(const QPoint& coords)
{
    return new WaterTile(coords);
}

}

const bool WaterTile::s_registered = TileFactory::type_factory::instance().registerProduct(WaterTile::s_idType, &creerWaterTile);
