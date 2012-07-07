#include "grasstile.hpp"
#include "tilefactory.hpp"
#include <towers/tower.hpp>
#include "engine.h"

const quint8 GrassTile::s_idType = 3;

GrassTile::GrassTile(const QPoint& coords): Tile(coords)
{}

GrassTile* GrassTile::clone() const
{
    return new GrassTile(*this);
}

bool GrassTile::addTower(Tower* tower)
{
    if(hasTower()) return false;
    setTower(tower);
    tower->setTile(this);
    Engine::instance()->addTower(tower);
    return true;
}

void GrassTile::draw(QPainter* painter) const
{
    Tile::draw(painter, Qt::green);
}

namespace {

Tile* creerGrassTile(const QPoint& coords)
{
    return new GrassTile(coords);
}

}

const bool GrassTile::s_registered = TileFactory::type_factory::instance().registerProduct(GrassTile::s_idType, &creerGrassTile);
