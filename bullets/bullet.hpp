#ifndef BULLET_HPP
#define BULLET_HPP

#include <utils/moving.hpp>
#include <utils/drawable.hpp>
#include <utils/todelsender.hpp>

#include <boost/shared_ptr.hpp>

#include <QPointF>

class Creep;

class Bullet : public Moving<QPointF>, public Drawable, public ToDelSender<Bullet>
{
public:
    typedef boost::weak_ptr<Creep> wp_creep;
    typedef boost::shared_ptr<Creep> sp_creep;

    explicit Bullet(const QPointF& coords, wp_creep cible, quint32 degats);

    virtual ~Bullet();

    wp_creep cible();

    wp_creep cible() const;

    void clearCible();

    void onHit();

private:
    quint32 m_degats;
    wp_creep m_cible;
};

#endif // BULLET_HPP
