#include "networkhandler.hpp"

#include "networkhandlerimpl/networkhandlerimplbasique.hpp"

NetworkHandler::NetworkHandler(): pimpl(new type_impl)
{}

void NetworkHandler::addTowerToNetwork(Tower* tower, quint8 x, quint8 y)
{
    pimpl->addTowerToNetwork(tower, x, y);
}

void NetworkHandler::update(double dt)
{
    pimpl->update(dt);
}

void NetworkHandler::draw(QPainter* painter) const
{
    pimpl->draw(painter);
}
