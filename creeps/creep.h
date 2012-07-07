#ifndef CREEP_H
#define CREEP_H

#include <utils/moving.hpp>
#include <utils/drawable.hpp>

#include <QPointF>
#include <QObject>
#include <QBrush>

class Creep : public QObject, public Moving<QPointF>, public Drawable
{
    Q_OBJECT
public:
    Creep(const QPointF& p);

    virtual void update(double dt);

    virtual void draw(QPainter *painter) const;

    void setGoal(const QPoint& goal);

    quint32 vie() const;
    quint32 vieMax() const;

    QBrush life2brush() const;

    void hit(quint32 degats);

protected:
    void setVieMax(quint32 viemax);

private:
    QPointF m_goal;
    quint32 m_vie;
    quint32 m_vieMax;

signals:
    void dead();
    void escaped();
};

#endif // CREEP_H
