#include "creep.h"
#include <utils/randomgenerator.hpp>
#include <engine/engine.hpp>

#include <QPainter>
#include <QVector2D>

#include <cmath>

Creep::Creep(const QPointF& coords): Moving<QPointF>(coords)
{
    static RandomGenerator<double> gen(-0.4, 0.4);
    double rX = gen();
    double rY = gen();
    (*this)+=QPointF(rX, rY);
    m_vie = 0;
    m_vieMax = 0;
}

void Creep::update(double dt)
{
    QVector2D reste(m_goal - coords());
    if(reste.lengthSquared() < vitesse()*dt)
    {
        //dernier deplacement
        try {
            setGoal(Engine::instance()->getNextGoal(m_goal.toPoint()));
        }
        catch(Engine::AucunPointSuivant& ex)
        {
            emit escaped();
        }

        return;
    }
    (*this) += (reste.normalized()*vitesse()*dt).toPointF();
}

void Creep::draw(QPainter *painter) const
{
    painter->setBrush(life2brush());
    painter->drawEllipse(coords()+QPointF(0.5, 0.5), 0.1, 0.1);
}

void Creep::setVieMax(quint32 viemax)
{
    m_vieMax = viemax;
    m_vie = viemax;
}

void Creep::setGoal(const QPoint& goal)
{
    m_goal = goal;
}

quint32 Creep::vie() const
{
    return m_vie;
}

quint32 Creep::vieMax() const
{
    return m_vieMax;
}

QBrush Creep::life2brush() const
{
    //quint8 nbPaliers = 5;
    double facteur = m_vie / m_vieMax;
    return QBrush(QColor(floor((1-facteur)*255), floor(facteur*255), 0));
}

void Creep::hit(quint32 degats)
{
    if(degats >= m_vie)
    {
        m_vie = 0;
        emit dead();
        return;
    }
    m_vie -= degats;
}
