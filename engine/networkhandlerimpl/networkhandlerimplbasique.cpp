#include "networkhandlerimplbasique.hpp"
#include <towers/tower.hpp>

#include <QVector2D>
#include <QPainter>

NetworkHandlerImplBasique::NetworkHandlerImplBasique()
{
}

void NetworkHandlerImplBasique::addTowerToNetwork(Tower* tower, quint8 x, quint8 y)
{
    m_vertexes.push_back(Vertex(tower, x, y));
    updateConnections();
}

#include <QDebug>
void NetworkHandlerImplBasique::update(double dt)
{
    m_effectiveConnections = m_connections;
    typedef std::map<Tower*, quint32> type_map_value_by_tower;
    type_map_value_by_tower mapOutputs;
    type_map_value_by_tower mapInputs;
    for(type_list_connections::const_iterator i = m_effectiveConnections.begin(); i != m_effectiveConnections.end(); ++i)
    {
        //taking care of tower outputs
        type_map_value_by_tower::iterator it = mapOutputs.find(i->from.tower);
        if(it == mapOutputs.end()) mapOutputs.insert(std::make_pair(i->from.tower, i->from.tower->energyOutputMax()));
        else it->second += i->from.tower->energyOutputMax();

        //taking care of tower inputs
        it = mapInputs.find(i->to.tower);
        if(it == mapInputs.end()) mapInputs.insert(std::make_pair(i->to.tower, i->to.tower->energyInputMax()));
        else it->second += i->to.tower->energyInputMax();
    }

    while(!testEffectiveConnectionsAreValid())
    {
        //TODO reduce energy flows
        qDebug() << "flux d'énergie invalides!!!";
        return;
    }

    applyEffectiveConnections(dt);
}

namespace
{
    QColor capacity2Color(double capacity)
    {
        if(capacity < 100) return Qt::red;
        return Qt::yellow;
    }
}

void NetworkHandlerImplBasique::draw(QPainter* painter) const
{
    painter->save();
    for(type_list_connections::const_iterator i = m_effectiveConnections.begin(); i != m_effectiveConnections.end(); ++i)
    {
        painter->setPen(capacity2Color(i->capacity));
        QPointF from(i->from.x, i->from.y);
        QPointF to(i->to.x, i->to.y);
        painter->drawLine(from + QPointF(0.5,0.5), to + QPointF(0.5, 0.5));
    }
    painter->restore();
}

void NetworkHandlerImplBasique::updateConnections()
{
    m_connections.clear();
    for(type_list_vertex::const_iterator i = m_vertexes.begin(); i != m_vertexes.end(); ++i)
    {
        type_list_vertex::const_iterator j = i;
        ++j;
        for(; j != m_vertexes.end(); ++j)
        {
            double distance = QVector2D(i->x - j->x, i->y - j->y).length();
            if(distance > 3) continue;
            if(i->tower->energyOutputMax() > 0 && j->tower->energyInputMax() > 0)
                m_connections.push_back(Connection(*i, *j, std::min(i->tower->energyOutputMax(), j->tower->energyInputMax())));
            if(j->tower->energyOutputMax() > 0 && i->tower->energyInputMax() > 0)
                m_connections.push_back(Connection(*j, *i, std::min(j->tower->energyOutputMax(), i->tower->energyInputMax())));
        }
    }
    qDebug() << "rapport connexions: " << m_connections.size() << " connexions créées.";
}

bool NetworkHandlerImplBasique::testEffectiveConnectionsAreValid()
{
//    int cpt = 1;
    for(type_list_connections::const_iterator i = m_effectiveConnections.begin(); i != m_effectiveConnections.end(); ++i)
    {
//        qDebug() << "connexion n°" << cpt++;
//        qDebug() << "capacity = " << i->capacity;
//        qDebug() << "from->energyOutputMax() = " << i->from->energyOutputMax();
//        qDebug() << "to->energyInputMax() = " << i->to->energyInputMax();
        if(i->capacity > i->from.tower->energyOutputMax() || i->capacity > i->to.tower->energyInputMax())
            return false;
    }
    return true;
}

void NetworkHandlerImplBasique::applyEffectiveConnections(double dt)
{
    for(type_list_connections::const_iterator i = m_effectiveConnections.begin(); i != m_effectiveConnections.end(); ++i)
    {
        double transfer = dt * i->capacity;
        if(i->from.tower->energy() >= transfer && (i->to.tower->energyMax() - i->to.tower->energy()) > transfer)
        {
            i->from.tower->subtractEnergy(transfer);
            i->to.tower->addEnergy(transfer);
        }
    }
}
