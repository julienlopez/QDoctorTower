#include "networkhandlerimplbasique.hpp"

NetworkHandlerImplBasique::NetworkHandlerImplBasique()
{
}

void NetworkHandlerImplBasique::addTowerToNetwork(Tower* tower, quint8 x, quint8 y)
{
    m_vertexes.push_back(Vertex(tower, x, y));
}

void NetworkHandlerImplBasique::update(double dt)
{

}

void NetworkHandlerImplBasique::draw(QPainter* painter) const
{

}
