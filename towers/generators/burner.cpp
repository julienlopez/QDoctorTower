#include "burner.hpp"
#include <towers/towerfactory.hpp>

const quint8 Burner::s_idType = 3;

const QString Burner::s_icone = TowerFactory::prefixeIcones()+"burner.png";

Burner::Burner(const QPoint& p): Generator(p, 20, 100)
{
    setEnergyOutputMax(10);
}

bool Burner::canGoOnWater() const
{
    return false;
}

const QString& Burner::icone() const
{
    return s_icone;
}

double Burner::produceEnergy()
{
    return 5;
}

bool Burner::canLevelUp() const
{
    return false;
}

void Burner::levelUp()
{

}

std::string Burner::label() const
{
    return "Burner";
}

namespace
{
Tower* createBurner(const QPoint& p) {
    return new Burner(p);
}
}

const bool Burner::s_registered = TowerFactory::registerTower(Burner::s_idType, &createBurner, s_icone);
