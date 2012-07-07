#ifndef BULLET_HPP
#define BULLET_HPP

#include <utils/moving.hpp>

#include <QObject>
#include <QPointF>

class Creep;

class Bullet : public QObject, public Moving<QPointF>
{
    Q_OBJECT
public:
    explicit Bullet(const QPointF& coords, Creep* cible, quint32 degats, QObject *parent = 0);

    Creep* cible();

public slots:
    void onHit();

signals:
    void hasHit();

private:
    quint32 m_degats;
    Creep* m_cible;
};

#endif // BULLET_HPP
