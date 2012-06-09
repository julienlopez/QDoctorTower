#ifndef BULLET_HPP
#define BULLET_HPP

#include <utils/moving.hpp>

#include <QObject>
#include <QPointF>

class Bullet : public QObject, public Moving<QPointF>
{
    Q_OBJECT
public:
    explicit Bullet(const QPointF& coords, QObject *parent = 0);

signals:
    void hit();

public slots:

};

#endif // BULLET_HPP
