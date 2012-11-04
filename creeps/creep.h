#ifndef CREEP_H
#define CREEP_H

#include <utils/moving.hpp>
#include <utils/drawable.hpp>

#include <boost/signals.hpp>

#include <QPointF>
#include <QBrush>

class Creep : public Moving<QPointF>, public Drawable, public boost::enable_shared_from_this<Creep>
{
public:
    typedef boost::weak_ptr<Creep> wp_creep;
    typedef boost::signal<void(wp_creep)> type_signal_creep;

    Creep(const QPointF& p);

    virtual ~Creep() throw();

    virtual void update(double dt);

    virtual void draw(QPainter *painter) const;

    void setGoal(const QPoint& goal);

    quint32 vie() const;
    quint32 vieMax() const;

    QBrush life2brush() const;

    void hit(quint32 degats);

    type_signal_creep& dead();
    type_signal_creep& escaped();

protected:
    void setVieMax(quint32 viemax);

    type_signal_creep m_dead;
    type_signal_creep m_escaped;

private:
    QPointF m_goal;
    quint32 m_vie;
    quint32 m_vieMax;
};

#endif // CREEP_H
